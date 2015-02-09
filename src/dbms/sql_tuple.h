
#ifndef SRC_DBMS_SQL_TUPLE_H_
#define SRC_DBMS_SQL_TUPLE_H_

#include <string>
#include <iostream>

using namespace std;

class SQLTuple
{
private:
	map<string, SQLTypeData> data;

public:
	SQLTuple()
	{
	}
	void add_attribute( string name, string data )
	{
		this->data.insert(
				pair<string, SQLTypeData>( name, SQLTypeData( data ) ) );
	}
	
	friend ostream& operator<<(std::ostream& os, const T& obj)
	{
		os << "test";
		return os;
	}
};

#endif
