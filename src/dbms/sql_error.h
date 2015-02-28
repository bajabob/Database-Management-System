#ifndef SRC_DBMS_SQL_ERROR_H_
#define SRC_DBMS_SQL_ERROR_H_

#include <string>
#include <iostream>

#include "enum.h"

using namespace std;

class SQLError {

public:
	SQLError(SQLErrorCode error_code, string message) :
			error_code(error_code), message(message) {
		/**
		 * WARNING error codes are the only codes that
		 * allow the system to keep working
		 */
		if (error_code != WARNING) {
			this->no_save_flag = true;
		} else {
			this->no_save_flag = false;
		}
	}

	/**
	 * Should this error prevent a save or other important queries?
	 */
	bool has_no_save_flagged() {
		return this->no_save_flag;
	}

	friend ostream& operator<<(ostream& os, const SQLError& obj) {
		if (obj.no_save_flag) {
			os << "-- Error   [Code: " << obj.error_code << "]: "
					<< obj.message;
		} else {
			os << "-- Warning [Code: " << obj.error_code << "]: "
					<< obj.message;
		}
		return os;
	}

private:
	bool no_save_flag;
	SQLErrorCode error_code;
	string message;

};

#endif
