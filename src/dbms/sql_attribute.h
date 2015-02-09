#ifndef SRC_DBMS_SQL_ATTRIBUTE_H_
#define SRC_DBMS_SQL_ATTRIBUTE_H_

#include <string>

using namespace std;

class SQLAttribute
{
public:
	string name;
	SQLType kind;
	int length;
	string default_value;
	SQLIndex index;
	bool auto_increment;

	SQLAttribute( string name, SQLType kind, int length, string default_value,
			SQLIndex index, bool auto_increment )
	{
		this->name = string( name );
		this->kind = SQLType( kind );
		this->length = int( length );
		this->default_value = string( default_value );
		this->index = SQLIndex( index );
		this->auto_increment = bool( auto_increment );
	}
	/*
	//maybe this? 
	
	SQLAttribute( string name, SQLType kind, int length, string default_value,
			SQLIndex index, bool auto_increment ) : name(name), kind(kind), length(length),
			default(default_value), index(auto_increment) 
	{
	}*/
	
};

#endif
