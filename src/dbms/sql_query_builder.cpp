#include "sql_query_build"

void SQLQueryBuilder::add_select(SQLQuerySelect &sel){ 
	query_attr = sel.get_queries();
	attributes = relation->get_attribute_names();
	vector<string>::iterator it;
	for(int i = 0;i < attributes.size(); ++i){
		it = find(query_attr.begin(), query_attr.end(),attributes[i]);
		if(*it != attributes[i] ){
			relation->delete_column(attributes[i]);
		}
	}
	show_new_table();
}