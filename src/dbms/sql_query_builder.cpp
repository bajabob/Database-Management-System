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
	vector<where_obj> not_where_2;
	vector<string> attributes;
	bool duplicate=false;
	bool  no_delete=false;
	
	
	for(int t=0;t<where.size();++t){
		duplicate=false;
		if(attributes.size()!=0)
		{
			for(int k =0;k<attributes.size();++k){
				if(attributes[k] == where[t].attr){
					duplicate =true;
					break;
				}
			}
		}
		if(!duplicate)
			attributes.push_back(where[t].attr);	
	}
	for(tup_it = relation.get_tuples().begin(); tup_it != relation.get_tuples().end(); ++tup_it){
		for(int j =0;j<attributes.size();++j){
			string data = tup_it->get_data(attributes[j]);
			where_obj temp_where(attributes[j],data); 
			not_where.push_back(temp_where);
		}
	}
	for(int g = 0;g < where.size();++g){
		int p = 0;
		for(;p<not_where.size(); ++p){
			if(where[g].where == not_where[p].where ) {
				not_where_2.push_back(not_where[p]);
				break;
			}
		}
	}	
	for(int i = 0;i<not_where_2.size();++i){
		relation.delete_row( not_where_2[i].attr, not_where_2[i].where);
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
 
SQLRelation SQLQueryBuilder::run_select(bool unaltered){
	if(unaltered){
	
		return relation;
	}
	else{
		query_attr = select.get_queries();
		where = select.get_wheres();
		non_where = select.get_not_wheres();
		subtract_where(non_where);
		add_where();
		add_select();
	}
	return relation;
}

