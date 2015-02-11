#ifndef SRC_DBMS_SQL_STORAGE_MANAGER_H_
#define SRC_DBMS_SQL_STORAGE_MANAGER_H_

#include <fstream>
#include <iostream>
#include <sys/stat.h>

#include "json/json.h"

using namespace std;

class SQLStorageManager {

public:

	SQLStorageManager(string filename) {
		cout << "Does the file exist? " << this->file_exists(filename) << endl;
	}

private:

	/**
	 * Does the specified file exist?
	 */
	inline bool file_exists(const string& name) {
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	}

};

#endif
