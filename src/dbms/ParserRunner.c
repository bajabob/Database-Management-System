#include "ParserRunner.h"

int yyparse(char* out, yyscan_t scanner);

char* runparser(char *str) {
	//cout<<strlen(str)<<endl;
	char *out = (char*)malloc(MAX_QUERY_SIZE * sizeof(char));
	strcpy(out,"");

	yyscan_t scanner;
	
	YY_BUFFER_STATE state;
    if (yylex_init(&scanner)) {
        // couldn't initialize
        return NULL;
    }
    state = yy_scan_string(str, scanner);
	if (yyparse(out, scanner)) {
        // error parsing
        return NULL;
    }
    yy_delete_buffer(state, scanner);
    yylex_destroy(scanner);
	return out;
}

char * strrstr(char *string, char *find)
{
	size_t stringlen, findlen;
	char *cp;

	findlen = strlen(find);
	stringlen = strlen(string);
	if (findlen > stringlen)
		return NULL;

	for (cp = string + stringlen - findlen; cp >= string; cp--)
		if (strncmp(cp, find, findlen) == 0)
			return cp;

	return NULL;
}

bool endsWith (char* base, char* str) {
    int blen = strlen(base);
    int slen = strlen(str);
    return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}

char* getrealation(char * Psql, vector<int> &tables) {
	SQLCommand command;
	char atname[MAX_AT_SIZE];
	char value[MAX_VALUE_SIZE];
	char aoper[MAX_AT_SIZE];
	vector<string> where;
	cout<<Psql<<endl;
	
	int start=0;
	int end=0;
	char* col = strstr(Psql, "(");
	while(col!=NULL){
		start = col - Psql;
		end=1;
		int k=1;
		while(k>0) {
			end++;
			if(col[end]=='(') {
				k++;
			}
			if(col[end]==')') {
				k--;
			}
		}
		char *temp = (char*)malloc(end+2 * sizeof(char));
		strncpy(temp, col+1, end);
		temp[end-1] = 0;
		char *result = getrealation(temp, tables);
		int i;
		for(i=start;i-start<strlen(result);++i) {
			Psql[i]=result[i-start];

		}
		for(i;i<end+start+1;++i) {
			Psql[i]=' ';
		}
		cout<<Psql<<endl;
		col = strstr(Psql+1, "(");
	}
	
	col = strstr(Psql, "SELECT");
	if(col) {
		col = strstr(Psql, "OP");
		while(col!=NULL) {
			sscanf(col, "%s", atname);
			if(strcmp(atname, "OP") == 0) {
				sscanf(col, "%*s %s %s %s", atname, aoper, value);
				string temp(atname);
				temp = temp + aoper;
				temp = temp + value;
				where.push_back(temp);
				string str(value);
				col = strstr(col, (" "+str+" ").c_str());
				col = col + str.length() + 1;
			} else if(strcmp(atname, "||") == 0 || strcmp(atname, "&&") == 0) {
				string temp(atname);
				where.push_back(atname);
				col = col + 3;
			} else {
				int i;
				for(i=0;i<where.size();++i) {
					cout<<where[i]<<", ";
				}
				cout<<endl;
				break;
			}
		}
		cout<<col<<endl;
		col = strstr(Psql, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc=-1;
		sscanf(atname, "%d", &loc);
		int table=tables[loc];
		cout<<"TABLE "<<atname<<endl;
		tables.push_back(table);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "PROJECT");
	if(col) {
		col = strstr(Psql, " ATTNAME ");
		while(col!=NULL) {
			sscanf(col, "%*s %s", atname);
			cout<<"ATTNAME "<<atname<<endl;
			col = strstr(col+1, " ATTNAME ");
		}
		col = strstr(Psql, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc=-1;
		sscanf(atname, "%d", &loc);
		int table=tables[loc];
		cout<<"TABLE "<<atname<<endl;
		tables.push_back(table);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "RENAME");
	if(col) {
		col = strstr(Psql, " REATTNAME ");
		while(col!=NULL) {
			sscanf(col, "%*s %s", atname);
			cout<<"REATTNAME "<<atname<<endl;
			col = strstr(col+1, " REATTNAME ");
		}
		col = strstr(Psql, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc=-1;
		sscanf(atname, "%d", &loc);
		int table=tables[loc];
		cout<<"TABLE "<<atname<<endl;
		tables.push_back(table);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "+");
	if(col) {
		col = strstr(Psql, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc1=-1;
		sscanf(atname, "%d", &loc1);
		cout<<"TABLE "<<atname<<endl;
		int table1=tables[loc1];
		col = strstr(col+1, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc2=-1;
		sscanf(atname, "%d", &loc2);
		int table2=tables[loc2];
		cout<<"TABLE "<<atname<<endl;
		int table = table1 + table2;
		tables.push_back(table);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "-");
	if(col) {
		col = strstr(Psql, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc1=-1;
		sscanf(atname, "%d", &loc1);
		cout<<"TABLE "<<atname<<endl;
		int table1=tables[loc1];
		col = strstr(col+1, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc2=-1;
		sscanf(atname, "%d", &loc2);
		int table2=tables[loc2];
		cout<<"TABLE "<<atname<<endl;
		int table = table1 + table2;
		tables.push_back(table);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "*");
	if(col) {
		col = strstr(Psql, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc1=-1;
		sscanf(atname, "%d", &loc1);
		cout<<"TABLE "<<atname<<endl;
		int table1=tables[loc1];
		col = strstr(col+1, "TABLEAT");
		cout<<col<<endl;
		sscanf(col, "%*s %s", atname);
		int loc2=-1;
		sscanf(atname, "%d", &loc2);
		int table2=tables[loc2];
		cout<<"TABLE "<<atname<<endl;
		int table = table1 + table2;
		tables.push_back(table);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "RELATION");
	if(col) {
		sscanf(col, "%*s %s", atname);
		cout<<"TABLE "<<atname<<endl;
		int table=1;
		tables.push_back(table);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	return Psql;
}

///////////////////////////////////////////////////////////////////////////

void queryDB(char * Psql) {
	SQLCommand command;
	char atname[MAX_AT_SIZE];
	char value[MAX_VALUE_SIZE];
	char aoper[MAX_AT_SIZE];
	vector<string> where;
	char *ptr = strstr(Psql, "CREATE");
	if(ptr) {
		char *col = strstr(Psql, "TYPE");
		int size = -1;
		vector<string> atra;
		while(col!=NULL) {
			int index = col-Psql;
			index+=5;
			if(Psql[index]=='V') {
				sscanf(col, "%*s %*s %*s %d %*s %s", &size, atname);
				string temp(atname);
				string str="VARCHAR "+to_string(size)+" "+temp;
				atra.push_back(str);
			}
			if(Psql[index]=='I') {
				sscanf(col, "%*s %*s %*s %s", atname);
				string temp(atname);
				string str="INTEGER "+temp;
				atra.push_back(str);
			}
			col = strstr(col+1, "TYPE");
		}
		col = strstr(Psql, "KEYNAME");
		while(col!=NULL) {
			int index = col-Psql;
			sscanf(col, "%*s %s", atname);
			string temp(atname);
			int i;
			for(i=0;i<atra.size();++i) {
				if(string::npos != atra[i].find(temp)) {
					atra[i]+=" KEY";
				}
			}
			col = strstr(col+1, "KEYNAME");
		}
		vector<SQLAttribute> sqlatra;
		SQLAttribute at1 = SQLAttribute( "id", INT, 8, "", PRIMARY, true, 0 );
		sqlatra.push_back(at1);
		int i;
		for(i=0;i<atra.size();++i) {
			string temps=atra[i];
			int size;
			char name[MAX_AT_SIZE];
			if(string::npos != temps.find("VARCHAR")) {
				sscanf(temps.c_str(), "%*s %d %s", &size, name);
				string temp(name);

				if(string::npos != temps.find("KEY")) {
					SQLAttribute at2 = SQLAttribute( temp, VARCHAR, size, "", UNIQUE, false, 0 );
					sqlatra.push_back(at2);
				}
				else {
					SQLAttribute at2 = SQLAttribute( temp, VARCHAR, size, "", NONE, false, 0 );
					sqlatra.push_back(at2);
				}
			}
			else {
				sscanf(temps.c_str(), "%*s %s", name);
				string temp(name);
				if(string::npos != temps.find("KEY")) {
					SQLAttribute at2 = SQLAttribute( temp, INT, 32, "", UNIQUE, false, 0 );
					sqlatra.push_back(at2);
				}
				else {
					SQLAttribute at2 = SQLAttribute( temp, INT, 32, "", NONE, false, 0 );
					sqlatra.push_back(at2);
				}
			}
		}
		col = strstr(Psql, "RELATION");
		sscanf(col, "%*s %s", atname);
		string temp2(atname);
		SQLRelation *table = command.create_table( temp2, sqlatra );
		cout<<*table;
		return;
	}
	ptr = strstr(Psql, "INSERT");
	if(ptr) {
		char *col = strstr(Psql, "LIT");
		if(col) {
			while(col!=NULL) {
				int size = NULL;
				sscanf(col, "%*s %s", value);
				sscanf(value, "%d", &size);
				if(size!=NULL) {
					cout<<"NUM "<<size<<endl;
				} else {
					cout<<"LIT "<<value<<endl;
				}
				col = strstr(col+1, "LIT");
			}
			col = strstr(Psql, "RELATION");
			sscanf(col, "%*s %s", atname);
			cout<<"TABLE "<<atname<<endl;
			return;
		}
		else {
			char* col = strstr(Psql, "RELATION");
			vector<int> tables;
			char* table=getrealation(col+1, tables);
			col = strstr(Psql, "INSERT");
			sscanf(col, "%*s %s", atname);
			col = strstr(table, "TABLEAT");
			cout<<"INSERT "<<atname<<" "<<col<<endl;	
			return;
		}
	}
	ptr = strstr(Psql, "SHOW");
	if(ptr) {
		char* col = strstr(Psql, "SHOW");
		vector<int> tables;
		char* table=getrealation(col+1, tables);
		col = strstr(table, "TABLEAT");
		cout<<"SHOW "<<col<<endl;	
		return;
	}
	ptr = strstr(Psql, "WRITE");
	if(ptr) {
		char *col = strstr(Psql, "RELATION");
		sscanf(col, "%*s %s", atname);
		cout<<"WRITE "<<atname<<endl;
		return;
	}
	ptr = strstr(Psql, "OPEN");
	if(ptr) {
		char *col = strstr(Psql, "RELATION");
		sscanf(col, "%*s %s", atname);
		cout<<"OPEN "<<atname<<endl;
		return;
	}
	ptr = strstr(Psql, "CLOSE");
	if(ptr) {
		char *col = strstr(Psql, "RELATION");
		sscanf(col, "%*s %s", atname);
		cout<<"CLOSE "<<atname<<endl;
		return;
	}
	ptr = strstr(Psql, "EXIT");
	if(ptr) {
		return;
	}
	ptr = strstr(Psql, "DELETE");
	if(ptr) {
		char *col = strstr(Psql, "OP");
		while(col!=NULL) {
			sscanf(col, "%s", atname);
			if(strcmp(atname, "OP") == 0) {
				sscanf(col, "%*s %s %s %s", atname, aoper, value);
				string temp(atname);
				temp = temp + " " + aoper + " ";
				temp = temp + value ;
				where.push_back(temp);
				string str(value);
				col = strstr(col, (" "+str+" ").c_str());
				col = col + str.length() + 1;
			} else if(strcmp(atname, "||") == 0 || strcmp(atname, "&&") == 0) {
				string temp(atname);
				where.push_back(atname);
				col = col + 3;
			} else {
				int i;
				for(i=0;i<where.size();++i) {
					cout<<where[i]<<", ";
				}
				cout<<endl;
				break;
			}
		}
		col = strstr(Psql, "RELATION");
		sscanf(col, "%*s %s", atname);
		cout<<"TABLE "<<atname<<endl;
		return;
	}
	ptr = strstr(Psql, "UPDATE");
	if(ptr) {
		char *col = strstr(Psql, "SET");
		while(col!=NULL) {
			int size = NULL;
			sscanf(col, "%*s %s %*s %s", atname, value);
			sscanf(value, "%d", &size);
			if(size!=NULL) {
				cout<<"SET "<<atname<<" = "<<size<<endl;
			} else {
				cout<<"SET "<<atname<<" = "<<value<<endl;
			}
			col = strstr(col+1, "SET");
		}
		col = strstr(Psql, "OP");
		while(col!=NULL) {
			sscanf(col, "%s", atname);
			if(strcmp(atname, "OP") == 0) {
				sscanf(col, "%*s %s %s %s", atname, aoper, value);
				string temp(atname);
				temp = temp + " " + aoper + " ";
				temp = temp + value ;
				where.push_back(temp);
				string str(value);
				col = strstr(col, (" "+str+" ").c_str());
				col = col + str.length() + 1;
			} else if(strcmp(atname, "||") == 0 || strcmp(atname, "&&") == 0) {
				string temp(atname);
				where.push_back(atname);
				col = col + 3;
			} else {
				int i;
				for(i=0;i<where.size();++i) {
					cout<<where[i]<<", ";
				}
				cout<<endl;
				break;
			}
		}
		col = strstr(Psql, "RELATION");
		sscanf(col, "%*s %s", atname);
		cout<<"TABLE "<<atname<<endl;
		return;
	}
	ptr = strstr(Psql, "ASSIGN");
	if(ptr) {
		char* col = strstr(Psql, ">");
		vector<int> tables;
		char* table=getrealation(col+1, tables);
		col = strstr(Psql, "ASSIGN");
		sscanf(col, "%*s %*s %s", atname);
		cout<<"ASSIGN TO "<<atname<<" "<<table<<endl;	
		return;
	}
	
	
	
	cout<<"Not Implemented"<<endl;
	return;
}

void ExecuteQuery(string query) {

	char *str = new char[query.length() + 1];
	strcpy(str, query.c_str());
	char* temp = runparser(str);
	cout<<temp<<endl;
	queryDB(temp);
}