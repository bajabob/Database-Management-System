#ifndef SRC_DBMS_SQL_QUERY_SELECT_H_
#define SRC_DBMS_SQL_QUERY_SELECT_H_

#include <string>
#include <vector>
#include "sql_relation.h"
#include "sql_attribute.h"
#include "sql_tuple.h"
#include <stack>
#include <sstream>

using namespace std;

struct where_obj{ 
	where_obj(string attribute, string wher){
		attr = attribute;
		where = wher;
	}
	string attr;
	string where;
	bool operator ==(const where_obj &w){
		if (this->attr == w.attr && this->where== w.where)
			return true;
		else
			return false;
	
	}
};


class SQLQuerySelect {

public:

	SQLQuerySelect(){}
	SQLQuerySelect(SQLRelation &rel);
	vector<string> get_queries(){ return this->select;}
	vector<where_obj> get_wheres(){ return this->where;}
	vector<where_obj> get_not_wheres(){ return this->not_where;}
	bool sel_greater(SQLTuple tup,string attr_1,string num);
	bool sel_greater_equal(SQLTuple tup,string attr_1,string num);
	bool sel_lesser(SQLTuple tup,string attr_1,string num);
	bool sel_lesser_equal(SQLTuple tup,string attr_1,string num);
	bool sel_equals(SQLTuple tup,string op1,string op2);
	bool sel_not(SQLTuple tup,string op1,string op2);
	bool operation(vector<string> ops);
	bool comparison(SQLTuple tup,string comp);
	void select_cmd(vector<string> ops, string name);
	int conv_attr(SQLTuple tup,string operand);//check to see if literal or attribute, return proper int data
	string conv_attr_2(SQLTuple tup,string operand);//check to see if literal or attribute, return proper string data
	private:
	SQLRelation relation;
	vector<string> select;
	vector<where_obj> where;
	vector<where_obj> not_where;
	vector<SQLTuple> tups;
	vector<bool> show_row;
};

#endif
