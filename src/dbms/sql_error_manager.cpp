#include "sql_error_manager.h"

void SQLErrorManager::add_error( SQLError error ) {
	this->errors.push_back( error );
}

bool SQLErrorManager::has_errors() {
	return (this->errors.size() > 0);
}

bool SQLErrorManager::has_no_save_flagged() {
	for ( auto &error : this->errors ) {
		if ( error.has_no_save_flagged() ) {
			return true;
		}
	}
	return false;
}

int SQLErrorManager::error_count() {
	return this->errors.size();
}
