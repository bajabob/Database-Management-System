
#ifndef SRC_DBMS_SQL_TUPLE_H_
#define SRC_DBMS_SQL_TUPLE_H_

#include <string>

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
};

#endif
