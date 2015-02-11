#ifndef SRC_DBMS_SQL_TUPLE_H_
#define SRC_DBMS_SQL_TUPLE_H_

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "enum.h"
#include "sql_error.h"
#include "sql_attribute.h"
#include "sql_type_data.h"
#include "sql_error_manager.h"

using namespace std;

class SQLTuple {

public:
	SQLTuple() {
	}

	/**
	 * Add an attribute (column) to the tuple.
	 */
	void add_attribute(SQLAttribute &attr, string data, SQLErrorManager &em);

	/**
	 * Does this tuple contain data (by a specified key) that matches
	 *  the inquired data? Good for testing if the table contains duplicate data.
	 */
	bool has_matching_data(string key, string data);

	friend ostream& operator<<(std::ostream& os, const SQLTuple& obj) {
		for (int i = 0; i < obj.keys.size(); ++i) {
			os << obj.data.find(obj.keys[i])->second << " ";
		}
		os << "\n";
		return os;
	}

private:

	/**
	 * This object (SQLTuple) represents a single row in the table.
	 * We store all the data for this tuple by it's column name (a key)
	 * This allows the tuple to contain any number of columns.
	 */
	map<string, SQLTypeData> data;

	/**
	 * It is difficult to iterate a map since it's data is stored in a tree
	 *  we store a list of local key's so we can figure out if this tuple has
	 *  all the keys required for the relation.
	 */
	vector<string> keys;
};

#endif
