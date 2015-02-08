#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
#include "jsonfunc.h"

using namespace std;

string jclass::from_json(string &index, string &label, int index_2=-1){
  Json::Value data_j;
  fname+= ".db";
  fstream fs;
  fs.open(fname.c_str(),fstream::in);
  fs >> data_j;
  string buff;
  if(index_2==-1)
    buff = data_j[index].get(label,"unkown").asString();
  else
    buff = data_j[index][index_2].get(label,"unkown").asString();
  fs.close;
  return buff; 
}

void jclas::to_json(string &index,string label,auto val, int index_2=-1){
  if(index_2==-1)
    database[index][label] = val;
  else
    database[index][index_2][label] =val;

}
      
      
void jclass::write_db(){
  Json::Value data_j;
  fname+= ".db";
  fstream fs;
  fs.open(fname.c_str(),fstream::out,fstream::trunc);
  Json::StyledWriter styledWriter;
  fs << styledWriter.write(database);
  fs.close()
}
