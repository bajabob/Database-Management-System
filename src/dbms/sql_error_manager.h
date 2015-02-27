#ifndef SRC_DBMS_SQL_ERROR_MANAGER_H_
#define SRC_DBMS_SQL_ERROR_MANAGER_H_

#include <string>
#include <vector>
#include <iostream>

#include "sql_error.h"

using namespace std;

class SQLErrorManager {

public:
	SQLErrorManager() {
	}

	/**
	 * Add a error to the list
	 */
	void add_error(SQLError error);

	/**
	 * Does this manager have any errors?
	 */
	bool has_errors();

	/**
	 * Does the list of errors contain a "no save" flagged?
	 */
	bool has_no_save_flagged();

	/**
	 * How many errors are in this manager?
	 */
	int error_count();

	friend ostream& operator<<(ostream& os, const SQLErrorManager& obj) {
		if (obj.errors.size() > 0) {
			os << obj.errors.size() << " Errors \n";
			for (auto &e : obj.errors) {
				os << e << " \n";
			}
		} else {
			os << "0 Errors \n";
		}
		return os;
	}

private:
	vector<SQLError> errors;

};

#endif
