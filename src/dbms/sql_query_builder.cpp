#include "sql_query_builder.h"
#include <algorithm>

using namespace std;


SQLQueryBuilder::SQLQueryBuilder(SQLRelation &rel,SQLQuerySelect &sel):relation(rel), select(sel)  {
		query_attr = select.get_queries();
		where = select.get_wheres();
		non_where = select.get_not_wheres();
		subtract_where(non_where);
	}

bool SQLQueryBuilder::is_duplicate(where_obj& data ,vector<where_obj> &wher){
	if(wher.size()<1)
		return false;
	
	for(int i=0; i< wher.size();++i){
		if(wher[i] == data)
			return true;
	
	}
	return false;

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
	for(tup_it = relation.get_tuples().begin(); tup_it != relation.get_tuples().end(); ++tup_it){
		for(wh_it = where.begin();wh_it != where.end();++wh_it){
			string data = tup_it->get_data(wh_it->attr);		
			where_obj temp_where(wh_it->attr,data);
			if(!is_duplicate(temp_where,not_where)){
				not_where.push_back(temp_where);
			}
			if(data == wh_it->where){
				not_where.pop_back();
				break;
			}
		}		
	}
	for(int i = 0;i<not_where.size();++i){
		relation.delete_row( not_where[i].attr, not_where[i].where);
	}		
}
 
 void SQLQueryBuilder::subtract_where(vector<where_obj> not_wheres){
	vector<SQLTuple>tuples=relation.get_tuples();
	vector<SQLTuple>::iterator tup_it;
	vector<where_obj> temp_data;
	if(not_wheres.size()<1) 
		return;
	for(tup_it = tuples.begin(); tup_it != tuples.end(); ++tup_it){
		for(int i=0; i< not_wheres.size();++i){
			
				string data = tup_it->get_data(not_wheres[i].attr);
				
				where_obj temp_where(not_wheres[i].attr,data);
				if(!is_duplicate(temp_where,temp_data)){
					temp_data.push_back(temp_where);
			}	
		}			
	}	
	for(int i = 0;i<temp_data.size();++i){
		if(!is_duplicate(temp_data[i] ,non_where)){
			where.push_back(temp_data[i]);
		}
	}
}	
 
void SQLQueryBuilder::run_select(bool unaltered){
	if(unaltered){
		cout<<"\n"<<relation;
	}
	else{
		add_where();
		add_select();
		
		cout<<"\n"<<relation;
		relation.load();
		
	}
		
}