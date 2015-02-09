#ifndef SRC_DBMS_SQL_TUPLE_H_
#define SRC_DBMS_SQL_TUPLE_H_

#include <string>
#include <iostream>

using namespace std;

class SQLTuple
{
private:
	map<string, SQLTypeData> data;
	vector<string> keys;

public:
	SQLTuple()
	{
	}
	void add_attribute( string name, string data )
	{
		this->data.insert(
				pair<string, SQLTypeData>( name, SQLTypeData( data ) ) );
		this->keys.push_back( name );
	}

	friend ostream& operator<<( std::ostream& os, const SQLTuple& obj )
	{
		for ( int i = 0; i < obj.keys.size(); ++i )
		{
			os << obj.keys[i] << ": " << obj.data.find( obj.keys[i] )->second << "\n";
		}
		return os;
	}
};

#endif
