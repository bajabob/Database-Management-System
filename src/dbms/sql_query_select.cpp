#include "sql_query_select.h"



SQLQuerySelect::SQLQuerySelect(vector<string> attributes) 
	 {
	 
	 
	
		select.push_back("id");	
		select.push_back("name_last");
		where_obj wh1("name_last","Salas");
		where_obj wh2("name_last","Timm");
	
		where.push_back(wh1);
		where.push_back(wh2);
	}