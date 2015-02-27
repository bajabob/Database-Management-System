#include "sql_query_select.h"



SQLQuerySelect::SQLQuerySelect(vector<string> attributes) 
	 {
	 
	 
	
		select.push_back("id");	
		select.push_back("name_last");
		where_obj wh1("name_last","Salas");
		where_obj wh2("name_last","Timm");
		where_obj wh3("name_last","NO_NAME");
		where_obj wh4("name_last","Turner");
		where_obj wh5("name_last","Alabama");
		not_where.push_back(wh1);
		not_where.push_back(wh2);
		not_where.push_back(wh3);
		//where.push_back(wh4);
		//where.push_back(wh5);
	} 