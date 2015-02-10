#ifndef SRC_DBMS_SQL_ERROR_H_
#define SRC_DBMS_SQL_ERROR_H_

#include <string>
#include <iostream>

#include "enum.h"

using namespace std;

class SQLError {

private:
	bool kill_query;
	SQLErrorCode error_code;
	string message;

public:
	SQLError(SQLErrorCode error_code, bool kill_query, string message) :
			error_code(error_code), kill_query(kill_query), message(message) {
	}

	/**
	 * Should this error kill the query?
	 */
	bool can_kill_query(){
		return this->kill_query;
	}

	friend ostream& operator<<(std::ostream& os, const SQLError& obj) {
		os << "Error [Code: " << obj.error_code << "]: " << obj.message;
		return os;
	}

};

#endif
