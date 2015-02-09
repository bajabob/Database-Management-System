//testing jclass


#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
#include "jsonfunc.h"
#include "sql_attribute.h"
#include <map>


using namespace std;

jclass jsan("file2");


void attr_to_json(vector<SQLAttribute> &attr){
	for(int i = 0;i<attr.size();++i){
		jsan.to_json("attributes", "name", attr[i].name, i);	
		jsan.to_json("attributes", "kind", to_string(attr[i].kind), i);
		jsan.to_json("attributes", "length", to_string(attr[i].length), i);
		jsan.to_json("attributes", "default", to_string(attr[i].default_value), i);
		jsan.to_json("attributes", "index", to_string(attr[i].index), i);
		jsan.to_json("attributes", "is_auto_increment", to_string(attr[i].is_auto_increment), i);
		jsan.to_json("attributes", "auto_increment", to_string(attr[i].auto_increment), i);		
	}
	



};





int main(){




	attr_to_json(vector<SQLAttribute> &attr);
	map<int,string> at_map;
	at_map.insert(0,"name");
	at_map.insert(1,"kind");
	at_map.insert(2,"length");
	at_map.insert(3,"default");
	at_map.insert(4,"index");
	at_map.insert(5,"is_auto_increment");
	at_map.insert(6,"auto_increment");
	
	
	for(int j=0;j<7;++j)
		for(int k=0;k<4;++k)
			cout<<jsan.from_json(string &index, string label, int id);
	
	
	/*jclass jsan("file");
	string raf="raf";
	int two=2;
	string hh="2";
	jsan.to_json(raf,raf,"2",0);
	jsan.write_db();
	jsan.read_db();
	cout<<jsan.from_json(raf,raf,0)<<"\n\n\n"; 
	return 0;
*/


}
