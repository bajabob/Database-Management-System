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

