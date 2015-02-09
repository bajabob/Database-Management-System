#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
#include "jsonfunc.h"

using namespace std;
/* json object structure index:id:label, id may not be used for every entry
such as is the case with the Table entry. The id value in the data section corresponds 
with id in the json functions seen below. id has a default arguement if not used. */
string jclass::from_json(string &index, string label, int id){
  Json::Value data_j;
  Json::Reader reader;// will parse json file
  ifstream fs((fname+".db").c_str());
  bool parsingSuccessful = reader.parse( fs, data_j, false );
  if(!parsingSuccessful) {
	cout<< "problem with input from db";
    return "0";  //primitive error catching
  }
  string buff;
  if(id==-1)
    buff = data_j[index].get(label,"unkown").asString();//need to find a way to convert to other types
  else
    buff = data_j[index][id].get(label,"unkown").asString();
  fs.close();
  return buff; //returns a string may look at returning an auto based on data types
}

//id must be 0 or greater. It is the callers responsibility to ensure this.
void jclass::to_json(string &index, string label,string val, int id){					//need to find a way to pass in different types of val
  if(id == -1)//make json object that does not hav and id(-1 is a default)
    database[index][label] = val;
  else
    database[index][id][label] =val;

}
      
      
void jclass::write_db(){
  ofstream fs;//output stream to file
  fs.open(fname+".db", ios::out | ios::trunc); 
  Json::StyledWriter styledWriter; 
  fs << styledWriter.write(database);//write into json format
  fs.close();
}
