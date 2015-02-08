//testing jclass


#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "json/json.h"
#include "jsonfunc.h"

using namespace std;

main(){
	jclass jsan("file");
	string raf="raf";
	jsan.to_json(raf,raf,2);
	jsan.write_db();
	cout<<jsan.from_json(raf,raf); 
	return 0;




}
