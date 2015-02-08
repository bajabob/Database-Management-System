//testing jclass


#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
#include "jsonfunc.h"

using namespace std;

int main(){
	jclass jsan("file");
	string raf="raf";
	int two=2;
	string hh="2";
	jsan.to_json(raf,raf,hh);
	jsan.write_db();
	cout<<jsan.from_json(raf,raf); 
	return 0;




}
