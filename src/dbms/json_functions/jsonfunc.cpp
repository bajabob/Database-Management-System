#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
#include "jsonfunc.h"

using namespace std;

string jclass::from_json(string &index, string label, int index_2){
  Json::Value data_j;
  fname+= ".db";
  ifstream fs;
  fs.open(fname.c_str());
  fs >> data_j;
  string buff;
  if(index_2==-1)
    buff = data_j[index].get(label,"unkown").asString();
  else
    buff = data_j[index][index_2].get(label,"unkown").asString();
  fs.close();
  return buff; 
}

void jclass::to_json(string &index, string label,string val, int index_2){
  if(index_2==-1)
    database[index][label] = val;
  else
    database[index][index_2][label] =val;

}
      
      
void jclass::write_db(){
  Json::Value data_j;
  fname+= ".db";
  ofstream fs;//output stream to file
  fs.open(fname, ios::out | ios::trunc); 
  Json::StyledWriter styledWriter;
  fs << styledWriter.write(database);
  fs.close();
}
