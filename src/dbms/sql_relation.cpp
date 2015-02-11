#include "sql_relation.h"

using namespace std;

void SQLRelation::add_attribute( SQLAttribute at ) {
	// compare attributes for errors
	bool has_error = false;
	for ( auto &attr : this->attr ) {
		attr.compare_for_errors( at, error_manager );
	}
	this->attr.push_back( at );
}

void SQLRelation::add_tuple( vector<string> data ) {
	int data_offset = 0;
	bool had_auto_increment = false;
	SQLTuple* tuple = new SQLTuple();

	for ( auto &attr : this->attr ) {

		// this is an ID column, and is auto incrementing (skip data[])
		if ( attr.get_index() == PRIMARY && attr.has_auto_increment() ) {
			tuple->add_attribute( attr,
					to_string( attr.get_auto_increment() ), error_manager );
			attr.on_auto_increment();
			continue;
		}

		// this column is UNIQUE, check table for pre-existing data
		if ( attr.get_index() == UNIQUE ) {
			if ( this->has_unique( attr.get_name(), data[data_offset] ) ) {
				error_manager.add_error(
						SQLError( DUPLICATE,
								"Relation already contains a unique value '"
										+ data[data_offset] + "' in '"
										+ attr.get_name() + "'." ) );
			}
		}

		// run out of data, send empty date to tuple
		if ( data.size() <= data_offset ) {
			tuple->add_attribute( attr, "", error_manager );
		} else { // default, send data to tuple

			tuple->add_attribute( attr, data[data_offset], error_manager );
			data_offset++;
		}

	}

	// test for errors (need error reporting class within this table)
	// then add tuple to table
	this->tuples.push_back( *tuple );
}


bool SQLRelation::has_unique( string key, string data ) {
	for ( auto &tuple : this->tuples ) {
		if ( tuple.has_matching_data( key, data ) ) {
			return true;
		}
	}
	return false;
}


void SQLRelation::attr_to_json(){
	for(int i = 0;i<attr.size();++i){
		json_db->to_json("attributes", "name", attr[i].get_name(), i);	
		json_db->to_json("attributes", "kind", to_string(attr[i].get_kind()), i);
		json_db->to_json("attributes", "length", to_string(attr[i].get_length()), i);
		json_db->to_json("attributes", "default", attr[i].get_default_value(), i);
		json_db->to_json("attributes", "index", to_string(attr[i].get_index()), i);
		json_db->to_json("attributes", "is_auto_increment",	\
			to_string(attr[i].has_auto_increment()), i);
		json_db->to_json("attributes", "auto_increment",	\
			to_string(attr[i].get_auto_increment()), i);		
	}
}


void SQLRelation::json_to_attr(){
//	attr.clear();
//
//	vector<string> at_name, at_default;
//	vector<SQLType> at_kind;
//	vector<int> at_length, at_bauto, at_auto;
//	vector<SQLIndex> at_indx;
//	for(int i = 0;i<4;++i){
//		at_name.push_back(json_db->from_json("attributes", "name", i));
//		at_kind.push_back(	\
//			SQLType(stoi(json_db->from_json("attributes", "kind", i))));
//		at_length.push_back(stoi(json_db->from_json("attributes", "length", i)));
//		at_default.push_back(json_db->from_json("attributes", "default" , i));
//		at_indx.push_back(SQLIndex(stoi(json_db->from_json("attributes", "index", i))));
//		at_bauto.push_back(	\
//			stoi(json_db->from_json("attributes", "is_auto_increment", i)));
//		at_auto.push_back(stoi(json_db->from_json("attributes", "auto_increment", i)));
//	}
//	for(int j = 0;j<4;++j){
//		attr.push_back(	SQLAttribute(at_name[j], at_kind[j], at_length[j],
//		at_default[j], at_indx[j], at_bauto[j], at_auto[j]));
//	}
//
//	attr.reserve(4);
	/*for(int i = 0;i<attr.size();++i){
		attr[i].name = 
			json_db->from_json("attributes", "name", i);	
		attr[i].kind = 
			SQLType(stoi(json_db->from_json("attributes", "kind",  i)));
		attr[i].length = 
			stoi(json_db->from_json("attributes", "length", i));
		attr[i].default_value = 
			json_db->from_json("attributes", "default" , i);
		attr[i].index = 
			SQLIndex(stoi(json_db->from_json("attributes", "index",  i)));
		attr[i].is_auto_increment = 
			stoi(json_db->from_json("attributes", "is_auto_increment", i));
		attr[i].auto_increment = 
			stoi(json_db->from_json("attributes", "auto_increment", i));		
	}*/

}
