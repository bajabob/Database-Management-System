#include "sql_query_builder.h"
#include <algorithm>

using namespace std;

void SQLQueryBuilder::add_select(){ 
	attributes = relation->get_attribute_names();
	vector<string>::iterator it;
	for(int i = 0;i < attributes.size(); ++i){	
		it = find(query_attr.begin(), query_attr.end(),attributes[i]);
		if(it == query_attr.end() ){
			
			relation->delete_column(attributes[i]);
		}
	} 
}

void SQLQueryBuilder::add_where(){
	map<string,string> not_where;
	for(int j =0 ;j < query_attr.size(); ++j){
		if (where[j].size()>0){	
			for( vector<SQLTuple>::iterator  tup_it = relation->get_tuples().begin(); tup_it != relation->get_tuples().end(); ++tup_it){
				string data = tup_it->get_data(query_attr[j]);
				//cout<<"\n row"<<*tup_it;
				cout<<"\nin add where "<<data<<" "<<query_attr[j];
				vector<string>::iterator it = find(where[j].begin(), where[j].end(),data);
				if(it != where[j].end()){
					not_where.insert(std::pair<string,string>(query_attr[j],data));
					//relation->delete_row(query_attr[j], data);			
				}
			}
		}
	}
	for(map<string,string>::iterator mapit= not_where.begin();mapit !=not_where.end();++mapit ){
		relation->delete_row(mapit->first, mapit->second);
	
	}
}
 
void SQLQueryBuilder::run_select(bool unaltered){
	if(unaltered){
		cout<<"\n"<<*relation;
	}
	else{
		add_select();
		add_where();
		cout<<"\n"<<*relation;
		relation->load();
		
	}
		
}