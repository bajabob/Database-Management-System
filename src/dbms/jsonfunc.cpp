#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
#include "jsonfunc.h"

using namespace std;

string jclass::from_json(){
  Json::Value data_j;
  fname+= ".db";
  fstream fs;
  fs.open(fname.c_str(),fstream::in);
  fs >> data_j;
  string buff;
  buff = data_j[id].get("val","unkown").asString();
  fs.close;
  return buff; 
}

void jclas::to_json(string &index,string label,auto val, int index_2=-1){
  if(index==-1)
    database[index][label] = val;
  else
    database[index[index_2][label] =val;

}
      
      
void jclass::write_db(){
  Json::Value data_j;
  fname+= ".db";
  fstream fs;
  fs.open(fname.c_str(),fstream::out,fstream::trunc);
  Json::StyledWriter styledWriter;
  fs << styledWriter.write(fromScratch);
  fs.close()
}
