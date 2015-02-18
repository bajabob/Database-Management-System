#include "sql_relation.h"

using namespace std;

void SQLRelation::add_attribute(SQLAttribute at) {
	// compare attributes for errors
	bool has_error = false;
	for (auto &attr : this->attributes) {
		attr.compare_for_errors(at, error_manager);
	}
	this->attributes.push_back(at);
}

vector<string> SQLRelation::get_attribute_names(){
	vector<string> names;
	for(auto &attr : this->attributes){
		names.push_back(attr.get_name());
	}
	return names;
}

void SQLRelation::add_tuple(vector<string> data) {
	int data_offset = 0;
	bool had_auto_increment = false;
	SQLTuple* tuple = new SQLTuple();

	for (auto &attr : this->attributes) {

		// this is an ID column, and is auto incrementing (skip data[])
		if (attr.get_index() == PRIMARY && attr.has_auto_increment()) {
			tuple->add_attribute(attr, to_string(attr.get_auto_increment()),
					error_manager);
			attr.on_auto_increment();
			continue;
		}

		// this column is UNIQUE, check table for pre-existing data
		if (attr.get_index() == UNIQUE) {
			if (this->has_unique(attr.get_name(), data[data_offset])) {
				error_manager.add_error(
						SQLError(DUPLICATE,
								"Relation already contains a unique value '"
										+ data[data_offset] + "' in '"
										+ attr.get_name() + "'."));
			}
		}

		// run out of data, send empty date to tuple
		if (data.size() <= data_offset) {
			tuple->add_attribute(attr, "", error_manager);
		} else { // default, send data to tuple

			tuple->add_attribute(attr, data[data_offset], error_manager);
			data_offset++;
		}

	}

	// test for errors (need error reporting class within this table)
	// then add tuple to table
	this->tuples.push_back(*tuple);
}

bool SQLRelation::has_unique(string key, string data) {
	for (auto &tuple : this->tuples) {
		if (tuple.has_matching_data(key, data)) {
			return true;
		}
	}
	return false;
}

void SQLRelation::delete_column(string attr){
	std::vector<SQLAttribute>::iterator it;
	//find column attribute and ensure it is not a primary
	for(it = attributes.begin(); it != attributes.end(); ++it){
		if (it->get_name()== attr){
			if(it->get_index()==1){
				cout<<"\n"<<"Cannot delete a Primary Attribute";
				return;
			}	
			attributes.erase(it);
			break;
		}
	}
	//attribute not found insert error
	if(it == attributes.end()){
		cout<<"\nColumn does not exist";
		return;
	}
	//delete column if attribute found
	for(int i = 0; i < tuples.size() ; ++i ){
		tuples[i].delete_data(attr);
	}
}

void SQLRelation::delete_row(string attr, string data){
	std::vector<SQLAttribute>::iterator it;
	std::vector<SQLTuple>::iterator it_2;
	//find attribute
	for(it = attributes.begin(); it != attributes.end(); ++it){
		if (it->get_name()== attr){
			break;
		}		
	}
	//attribute not found insert error
	if (it==attributes.end()){
		cout<<"\nAttribute does not exist";
		return;
	}
	//delete row
	for(it_2=tuples.begin();it_2 != tuples.end(); ++it_2){
		if(it_2->has_matching_data( it->get_name(), data )){
			tuples.erase(it_2);
			break;
		}
	}
	//find attribute with auto increment
	for(it = attributes.begin(); it != attributes.end(); ++it){
		if (it->has_auto_increment()){
			it->on_auto_decrement();
			break;
		}		
	}
	//decrement id's by updating data 
	if(it->has_auto_increment()){
		for(;it_2 !=tuples.end(); ++it_2){
			string current_data = it_2->get_data(it->get_name());
			int c_data = stoi(current_data);
			string mod_data = to_string(--c_data);
			cout<<"\n"<<mod_data;
			it_2->update_data(*it, error_manager, mod_data);
	
	
		}
	}
	
}
