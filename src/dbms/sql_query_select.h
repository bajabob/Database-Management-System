#ifndef SRC_DBMS_SQL_QUERY_SELECT_H_
#define SRC_DBMS_SQL_QUERY_SELECT_H_

#include <string>
#include <vector>

using namespace std;

struct where_obj{
	where_obj(string attribute, string wher){
		attr = attribute;
		where = wher;
	}
	string attr;
	string where;
	
};


class SQLQuerySelect {

public:

	SQLQuerySelect(){}

	SQLQuerySelect(vector<string> attributes);
	vector<string> get_queries(){ return this->select;}
	vector<where_obj> get_wheres(){ return this->where;}
private:
	vector<string> select;
	vector<where_obj>  where;
	
};

#endif
