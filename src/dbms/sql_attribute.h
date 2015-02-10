#ifndef SRC_DBMS_SQL_ATTRIBUTE_H_
#define SRC_DBMS_SQL_ATTRIBUTE_H_

#include <string>

using namespace std;

class SQLAttribute {
private:
	string name;
	SQLType kind;
	int length;
	string default_value;
	SQLIndex index;
	bool is_auto_increment;
	int auto_increment;

public:

	SQLAttribute(string name, SQLType kind, int length, string default_value,
			SQLIndex index, bool is_auto_increment, int auto_increment) :
			name(name), kind(kind), length(length), default_value(
					default_value), index(index), is_auto_increment(
					is_auto_increment), auto_increment(auto_increment) {
		// intentionally blank
	}

	string get_name() {
		return this->name;
	}

	SQLType get_kind() {
		return this->kind;
	}

	int get_length() {
		return this->length;
	}

	string get_default_value(){
		return this->default_value;
	}

	SQLIndex get_index() {
		return this->index;
	}

	bool has_auto_increment(){
		return this->is_auto_increment;
	}

	int get_auto_increment(){
		return this->auto_increment;
	}

	void on_auto_increment(){
		++this->auto_increment;
	}

	friend ostream& operator<<(std::ostream& os, const SQLAttribute& obj) {
		os << "Attribute [name] :" << obj.name << "\n";
		os << "kind             :" << obj.kind << "\n";
		os << "length           :" << obj.length << "\n";
		os << "defualt_value    :" << obj.default_value << "\n";
		os << "index            :" << obj.index << "\n";
		os << "is_auto_increment:" << obj.is_auto_increment << "\n";
		os << "auto_increment   :" << obj.auto_increment << "\n";
		return os;
	}

};

#endif
