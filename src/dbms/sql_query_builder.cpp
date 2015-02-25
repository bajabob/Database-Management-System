#include "sql_query_builder.h"
#include <algorithm>

using namespace std;


SQLQueryBuilder::SQLQueryBuilder(SQLRelation &rel,SQLQuerySelect &sel):relation(rel), select(sel)  {
		query_attr = select.get_queries();
		where = select.get_wheres();
		
	}




void SQLQueryBuilder::add_select(){ 
	attributes = relation.get_attribute_names();
	vector<string>::iterator it;
	for(int i = 0;i < attributes.size(); ++i){	
		it = find(query_attr.begin(), query_attr.end(),attributes[i]);
		if(it == query_attr.end() ){
			
			relation.delete_column(attributes[i]);
		}
	} 
}

void SQLQueryBuilder::add_where(){
	vector<where_obj>::iterator wh_it;
	vector<SQLTuple>::iterator tup_it;
	vector<where_obj> not_where;
	bool to_delete = true;
	for(tup_it = relation.get_tuples().begin(); tup_it != relation.get_tuples().end(); ++tup_it){
		int flag = 0;
		for(wh_it = where.begin();wh_it != where.end();++wh_it){
			string data = tup_it->get_data(wh_it->attr);
			if(flag==0){
				where_obj temp_where(wh_it->attr,data);
				not_where.push_back(temp_where);
				++flag;
			}
			if(data == wh_it->where){
				not_where.pop_back();
				break;
			}
		}		
	}
	for(int i = 0;i<not_where.size();++i){
		relation.delete_row(not_where[i].attr,not_where[i].where);
	}		
}
 
 
 
void SQLQueryBuilder::run_select(bool unaltered){
	if(unaltered){
		cout<<"\n"<<relation;
	}
	else{
		add_select();
		add_where();
		cout<<"\n"<<relation;
		relation.load();
		
	}
		
}