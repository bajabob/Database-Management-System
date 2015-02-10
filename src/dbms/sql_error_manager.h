#ifndef SRC_DBMS_SQL_ERROR_MANAGER_H_
#define SRC_DBMS_SQL_ERROR_MANAGER_H_

#include <string>
#include <vector>
#include <iostream>

#include "sql_error.h"

using namespace std;

class SQLErrorManager {

private:
	vector<SQLError> errors;

public:
	SQLErrorManager() {
	}

	/**
	 * Add a error to the list
	 */
	void add_error(SQLError error) {
		this->errors.push_back(error);
	}

	/**
	 * Does this manager have any errors?
	 */
	bool has_errors() {
		return (this->errors.size() > 0);
	}

	/**
	 * Does the list of errors contain a kill query flaq?
	 */
	bool has_kill_query_error(){
		for(auto &error: this->errors){
			if(error.can_kill_query()){
				return true;
			}
		}
		return false;
	}


	/**
	 * How many errors are in this manager?
	 */
	int error_count() {
		return this->errors.size();
	}

	friend ostream& operator<<(std::ostream& os, const SQLErrorManager& obj) {
		if (obj.errors.size() > 0) {
			os << obj.errors.size() << " Errors \n";
			for (auto &error : obj.errors) {
				os << error << " \n";
			}
		} else {
			os << "0 Errors \n";
		}
		return os;
	}

};

#endif
