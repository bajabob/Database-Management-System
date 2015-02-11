#ifndef SRC_DBMS_jclass_H_
#define SRC_DBMS_jclass_H_

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
 
using namespace std;
class jclass{
  
public:
	jclass(string file):fname(file){}	//intialize constructor and file name
  
  //returns json object in form of string
	string from_json(string index, string label, int id=-1);
  
  //formats arguements into json 
	void to_json( string index, string label,string val,int id=-1);
  
 //read from database
	void read_db();
	
//writes to the database file. Caution this will truncate the file
	void write_db();
   
 // json object. Append labels and values to to get the json architecture
	Json::Value database;
  
private:
	string fname; //database name

};

#endif