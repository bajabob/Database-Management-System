#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
 
using namespace std;
class jclass{
  
public:
  jclass(string file):fname(file){}
  string from_json();
  void to_json(string &index,string label,auto val, int index_2=-1);
  void  write_db();
  json::Value database;

private:
  string fname;

};
