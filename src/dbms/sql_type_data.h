
#ifndef SRC_DBMS_SQL_TYPE_DATA_H_
#define SRC_DBMS_SQL_TYPE_DATA_H_

#include <string>

using namespace std;

class SQLTypeData
{

public:
	string data;

	SQLTypeData( string data )
	{
		this->data = string( data );
	}
};



#endif
