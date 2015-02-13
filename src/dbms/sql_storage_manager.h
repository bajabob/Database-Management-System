#ifndef SRC_DBMS_SQL_STORAGE_MANAGER_H_
#define SRC_DBMS_SQL_STORAGE_MANAGER_H_

#include <vector>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

#include "sql_error.h"
#include "sql_tuple.h"
#include "sql_attribute.h"
#include "sql_type_data.h"
#include "sql_error_manager.h"
#include "json/json.h"

using namespace std;

class SQLStorageManager {

public:

	SQLStorageManager(string filename) :
			filename(filename) {
		// intentionally blank
	}

	void load(SQLErrorManager&, vector<SQLAttribute>&, vector<SQLTuple>&);

	void save(SQLErrorManager&, vector<SQLAttribute>&, vector<SQLTuple>);

private:

	string filename;

	/**
	 * Does the specified file exist?
	 */
	inline bool file_exists(const string& name) {
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	}

	Json::Value save_to_value(vector<SQLAttribute>&, vector<SQLTuple>);

	void load_from_value(Json::Value, vector<SQLAttribute>&, vector<SQLTuple>&,
				SQLErrorManager&);
};

#endif
