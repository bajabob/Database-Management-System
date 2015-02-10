#ifndef SRC_DBMS_SQL_RELATION_H_
#define SRC_DBMS_SQL_RELATION_H_

#include "sql_error_manager.h"

using namespace std;

class SQLRelation {
private:
	string name; // name of this relation (table)
	vector<SQLAttribute> attr;
	vector<SQLTuple> tuples;
	SQLErrorManager error_manager;

public:

	SQLRelation(string name) :
			name(name) {
	}

	void add_attribute(SQLAttribute at) {
		// compare attributes for errors
		bool has_error = false;
		for (auto &attr : this->attr) {
			attr.compare_for_errors(at, error_manager);
		}
		this->attr.push_back(at);
	}

	void add_tuple(string data[]) {
		int data_offset = 0;
		bool had_auto_increment = false;
		SQLTuple* tuple = new SQLTuple();

		for (auto &attr : this->attr) {
			// this is an ID column, and is auto incrementing (skip data[])
			if (attr.get_index() == PRIMARY && attr.has_auto_increment()) {
				tuple->add_attribute(attr,
						to_string(attr.get_auto_increment()), error_manager);
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
											+ attr.get_name()+"'."));
				}
			}

			// Fall through - this is not a fancy column, just add it
			tuple->add_attribute(attr, data[data_offset],
					error_manager);
			data_offset++;
		}

		// test for errors (need error reporting class within this table)
		// then add tuple to table
		this->tuples.push_back(*tuple);
	}

	/**
	 * Test if a unique value exists in in the
	 *  list of tuples by the specified key
	 */
	bool has_unique(string key, string data) {
		for (auto &tuple : this->tuples) {
			if (tuple.has_matching_data(key, data)) {
				return true;
			}
		}
		return false;
	}

	friend ostream& operator<<(std::ostream& os, const SQLRelation& obj) {
		os << "\nRelation: " << obj.name << "\n";
		os << "----------------------------\n\n";
		os << "Attributes: " << obj.attr.size() << "\n";
		for (int i = 0; i < obj.attr.size(); ++i) {
			os << obj.attr[i];
		}
		os << "----------------------------\n\n";
		os << "Tuples: " << obj.tuples.size() << "\n";
		for (int i = 0; i < obj.tuples.size(); ++i) {
			os << obj.tuples[i];
		}
		os << "----------------------------\n\n";
		os << "Errors: " << obj.error_manager;
		return os;
	}

};

#endif
