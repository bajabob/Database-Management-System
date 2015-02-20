#include "sql_query_build"

void SQLQueryBuilder::add_select(){ 
	attributes = relation->get_attribute_names();
	vector<string>::iterator it;
	for(int i = 0;i < attributes.size(); ++i){
		it = find(query_attr.begin(), query_attr.end(),attributes[i]);
		if(*it != attributes[i] ){
			relation->delete_column(attributes[i]);
		}
	}
}

void SQLQueryBuilder::add_where(){
	vector<string>::iterartor it;
	vector<string> not_where;
	bool is_where = false;
	for(it = query_attr() ;it != query_attr.end(); ++it){
		for( int i = 0;i < relation->get_tuples().size(); ++i){
			string data = relation->get_tuples().get_data(it->get_name());
			vector<string>::iterartor it_2 = find(where.begin(), where.end(),data);
			if(it_2 != where.end())
				relation->delete_row(*it, data);			
			}	
		}
	}
}

void run_select(bool unaltered){
	if(unaltered){
		cout<<"\n"<<relation;
	}
	else{
		add_select();
		add_where();
		cout<<"\n"<<relation;
		relation->load();
		
	}
		
}