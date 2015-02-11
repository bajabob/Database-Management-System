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
#include "enum.h"

using namespace std;

jclass jsan("file2");


void attr_to_json(vector<SQLAttribute> &attr){
	for(int i = 0;i<attr.size();++i){
		jsan.to_json("attributes", "name", attr[i].name, i);	
		jsan.to_json("attributes", "kind", to_string(attr[i].kind), i);
		jsan.to_json("attributes", "length", to_string(attr[i].length), i);
		jsan.to_json("attributes", "default", attr[i].default_value, i);
		jsan.to_json("attributes", "index", to_string(attr[i].index), i);
		jsan.to_json("attributes", "is_auto_increment", to_string(attr[i].is_auto_increment), i);
		jsan.to_json("attributes", "auto_increment", to_string(attr[i].auto_increment), i);		
	}
}
//convert to proper types
void json_to_attr(vector<SQLAttribute> &attr){
	attr.clear();
	attr.reserve(4);
	for(int i = 0;i<attr.size();++i){
		attr[i].name = 
			jsan.from_json("attributes", "name", i);	
		attr[i].kind = 
			SQLType(stoi(jsan.from_json("attributes", "kind",  i)));
		attr[i].length = 
			stoi(jsan.from_json("attributes", "length", i));
		attr[i].default_value = 
			jsan.from_json("attributes", "default" , i);
		attr[i].index = 
			SQLIndex(stoi(jsan.from_json("attributes", "index",  i)));
		attr[i].is_auto_increment = 
			stoi(jsan.from_json("attributes", "is_auto_increment", i));
		attr[i].auto_increment = 
			stoi(jsan.from_json("attributes", "auto_increment", i));		
	}

}





int main(){
	vector<SQLAttribute> attr;
	attr.push_back(SQLAttribute( "id", INT, 8, "", PRIMARY, true, 3 ));
	attr.push_back(SQLAttribute( "username", VARCHAR, 25, "", UNIQUE, false,0 ));
	attr.push_back(SQLAttribute( "name_last", VARCHAR, 25, "", NONE, false,0 ));
	attr.push_back(SQLAttribute( "name_first", VARCHAR, 25, "", NONE, false,0 ));

	attr_to_json(attr);
	map<int,string> at_map;
	at_map.insert(make_pair(0,"name"));
	at_map.insert(make_pair(1,"kind"));
	at_map.insert(make_pair(2,"length"));
	at_map.insert(make_pair(3,"default"));
	at_map.insert(make_pair(4,"index"));
	at_map.insert(make_pair(5,"is_auto_increment"));
	at_map.insert(make_pair(6,"auto_increment"));
	
	json_to_attr(attr);
		
	for(int j=0;j<4;++j){
		for(int k=0;k<7;++k)
			cout<<jsan.from_json( "attributes", at_map[k], j)<<"\n";
		cout<<"\n\n\n";
	
	}
/*	
	jclass jsan("file");
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
