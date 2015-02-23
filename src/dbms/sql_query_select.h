#ifndef SRC_DBMS_SQL_QUERY_SELECT_H_
#define SRC_DBMS_SQL_QUERY_SELECT_H_

#include <string>
#include <vector>

using namespace std;

class SQLQuerySelect {

public:

	SQLQuerySelect(){}

	SQLQuerySelect(vector<string> attributes);
	vector<string> get_queries(){ return this->select;}
	vector<vector<string>> get_wheres(){ return this->where;}
private:
	vector<string> select;
	vector<vector<string>>  where;
	
};

#endif
