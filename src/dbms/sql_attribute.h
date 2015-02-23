#ifndef SRC_DBMS_SQL_ATTRIBUTE_H_
#define SRC_DBMS_SQL_ATTRIBUTE_H_

#include <string>

#include "sql_error.h"
#include "json/json.h"
#include "sql_error_manager.h"

using namespace std;

class SQLAttribute {

public:

	SQLAttribute(Json::Value);

	SQLAttribute(string name, SQLType kind, int length, string default_value,
			SQLIndex index, bool is_auto_increment, int auto_increment) :
			name(name), kind(kind), length(length), default_value(
					default_value), index(index), is_auto_increment(
					is_auto_increment), auto_increment(auto_increment) {
		// intentionally blank
	}

	string get_name();
	SQLType get_kind();
	int get_length();
	string get_default_value();
	SQLIndex get_index();
	bool has_auto_increment();
	int get_auto_increment();
	void on_auto_increment();
	void on_auto_decrement();
	
	/**
	 * Compare this attribute against another for errors
	 * return true if error is found, store actual error in error manager
	 */
	bool compare_for_errors(SQLAttribute attr, SQLErrorManager &em);

	/**
	 * Convert this attribute to a json obj
	 */
	Json::Value to_json();


	friend ostream& operator<<(std::ostream& os, const SQLAttribute& obj) {
		os << "Attribute '" << obj.name << "'\n";
		os << " - kind             :" << obj.kind << "\n";
		os << " - length           :" << obj.length << "\n";
		os << " - defualt_value    :" << obj.default_value << "\n";
		os << " - index            :" << obj.index << "\n";
		os << " - is_auto_increment:" << obj.is_auto_increment << "\n";
		os << " - auto_increment   :" << obj.auto_increment << "\n";
		return os;
	}

private:
	string name;
	SQLType kind;
	int length;
	string default_value;
	SQLIndex index;
	bool is_auto_increment;
	int auto_increment;

};

#endif
