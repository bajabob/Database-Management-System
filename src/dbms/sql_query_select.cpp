#include "sql_query_select.h"



SQLQuerySelect::SQLQuerySelect(vector<string> attributes) 
	 {
	 
	 
		
		select.push_back("id");	
		select.push_back("name_last");
		vector<string>  id;
		vector<string> last = {"Timm", "Salas"};
		where.push_back(id);
		where.push_back(last);
	//	cout<<"\nHellooooooo:"<< where.size();
	}