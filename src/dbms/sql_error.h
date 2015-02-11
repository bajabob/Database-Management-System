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
	SQLError(SQLErrorCode error_code, string message) :
			error_code(error_code), message(message) {
		/**
		 * WARNING error codes are the only codes that
		 * allow the system to keep working
		 */
		if(error_code != WARNING){
			this->kill_query = true;
		}else{
			this->kill_query = false;
		}
	}

	/**
	 * Should this error kill the query?
	 */
	bool can_kill_query(){
		return this->kill_query;
	}

	friend ostream& operator<<(std::ostream& os, const SQLError& obj) {
		if(obj.kill_query){
			os << "-- Error   [Code: " << obj.error_code << "]: " << obj.message;
		}else{
			os << "-- Warning [Code: " << obj.error_code << "]: " << obj.message;
		}
		return os;
	}

};

#endif
