#include "ParserRunner.h"

int yyparse(char* out, yyscan_t scanner);

SQLCommand command;

char* runparser(char *str) {
	//cout<<strlen(str)<<endl;
	string temp(str);
	char *out = (char*)malloc(temp.length() * MAX_QUERY_SIZE * sizeof(char));
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

char* getrealation(char * Psql, vector<SQLRelation*> &tables) {
	char atname[MAX_AT_SIZE];
	char value[MAX_VALUE_SIZE];
	char aoper[MAX_AT_SIZE];
	//cout<<Psql<<endl;
	
	int start=0;
	int end=0;
	char* col = strstr(Psql, "(");
	while(col!=NULL){ //thing that makes the relation thing work
		start = col - Psql;
		end=1;
		int k=1;
		bool notliteral=true;
		while(k>0) {
			end++;
			if(col[end]=='(' && notliteral) {
				k++;
			}
			if(col[end]==')' && notliteral) {
				k--;
			}
			if(col[end]=='"') {
				notliteral = !notliteral;
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
		//cout<<Psql<<endl;
		col = strstr(Psql+1, "(");
	}
	
	col = strstr(Psql, "S1E2L3E4C5T"); // select
	if(col) {
		col = strstr(Psql, "1O2P3");
		vector<string> where;
		while(col!=NULL) {
			sscanf(col, "%s", atname);
			if(strcmp(atname, "1O2P3") == 0) {
				string op1, op2, op3;
				int i=6;
				if(col[i]=='\"') {
					op1+='\"';
					i++;
					while(col[i]!='\"') {
						op1+=col[i];
						i++;
					}
					op1+='\"';
					i++;
					i++;
				} else {
					while(col[i]!=' ') {
						op1+=col[i];
						i++;
					}
					i++;
				}
				while(col[i]!=' ') {
						op2+=col[i];
						i++;
				}
				i++;
				if(col[i]=='\"') {
					op3+='\"';
					i++;
					while(col[i]!='\"') {
						op3+=col[i];
						i++;
					}
					op3+='\"';
					i++;
					i++;
				} else {
					while(col[i]!=' ') {
						op3+=col[i];
						i++;
					}
					i++;
				}
				string temp = op1+" "+op2+" "+op3+" ";
				where.push_back(temp);
				col = strstr(col, (" "+op3+" ").c_str());
				col = col + op3.length() + 2;
			} else if(strcmp(atname, "||") == 0 || strcmp(atname, "&&") == 0) {
				string temp(atname);
				where.push_back(atname);
				col = col + 3;
			} else {
				break;
			}
		}
		col = strstr(Psql, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc=-1;
		sscanf(atname, "%d", &loc);
		SQLRelation *table=tables[loc];
		SQLRelation *newtable = command.select(table, where);
		tables.push_back(newtable);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "P1R2O3J4E5CT"); // project
	if(col) {
		col = strstr(Psql, " A1T2T3N4A5ME ");
		vector<string> atra;
		atra.push_back(" ");
		while(col!=NULL) {
			sscanf(col, "%*s %s", atname);
			string temp(atname);
			atra.push_back(temp);
			col = strstr(col+1, " A1T2T3N4A5ME ");
		}
		col = strstr(Psql, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc=-1;
		sscanf(atname, "%d", &loc);
		SQLRelation *table=tables[loc];
		SQLRelation *newtable = command.project(table, atra);
		tables.push_back(newtable);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "R1E2N3A4M5E"); // rename
	if(col) {
		col = strstr(Psql, " R1E2A3T4T5NAME ");
		vector<string> atra;
		atra.push_back(" ");
		while(col!=NULL) {
			sscanf(col, "%*s %s", atname);
			string temp(atname);
			atra.push_back(temp);
			col = strstr(col+1, " R1E2A3T4T5NAME ");
		}
		col = strstr(Psql, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc=-1;
		sscanf(atname, "%d", &loc);
		SQLRelation *table=tables[loc];
		SQLRelation *newtable = command.rename_attr(table, atra);
		tables.push_back(newtable);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "+"); // union
	if(col) {
		col = strstr(Psql, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc1=-1;
		sscanf(atname, "%d", &loc1);
		SQLRelation *table1=tables[loc1];
		col = strstr(col+1, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc2=-1;
		sscanf(atname, "%d", &loc2);
		SQLRelation *table2=tables[loc2];
		SQLRelation *newtable = command.union_tables(table1, table2);
		tables.push_back(newtable);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "-"); // differance
	if(col) {
		col = strstr(Psql, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc1=-1;
		sscanf(atname, "%d", &loc1);
		SQLRelation *table1=tables[loc1];
		col = strstr(col+1, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc2=-1;
		sscanf(atname, "%d", &loc2);
		SQLRelation *table2=tables[loc2];
		SQLRelation *newtable = command.difference(table1, table2);
		tables.push_back(newtable);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "*"); // product
	if(col) {
		col = strstr(Psql, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc1=-1;
		sscanf(atname, "%d", &loc1);
		SQLRelation *table1=tables[loc1];
		col = strstr(col+1, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc2=-1;
		sscanf(atname, "%d", &loc2);
		SQLRelation *table2=tables[loc2];
		SQLRelation *newtable = command.product(table1, table2);
		tables.push_back(newtable);
		string str="TABLEAT "+to_string(tables.size()-1);
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	col = strstr(Psql, "R1E2L3A4T5ION"); // Just a table name
	if(col) {
		sscanf(col, "%*s %s", atname);
		string temp(atname);
		SQLRelation *table = command.get_table(temp);
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
	char atname[MAX_AT_SIZE];
	char value[MAX_VALUE_SIZE];
	char aoper[MAX_AT_SIZE];
	char *ptr = strstr(Psql, "C1R2E3A4T5E"); //Create
	if(ptr) {
		char *col = strstr(Psql, "1T2Y3P4E5");
		int size = -1;
		vector<string> atra;
		while(col!=NULL) {
			int index = col-Psql;
			index+=10;
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
			col = strstr(col+1, "1T2Y3P4E5");
		}
		col = strstr(Psql, "K1E2Y3N4A5ME");
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
			col = strstr(col+1, "K1E2Y3N4A5ME");
		}
		vector<SQLAttribute> sqlatra;
		SQLAttribute at1 = SQLAttribute( " ", INT, 8, "", PRIMARY, true, 0 );
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
					SQLAttribute at2 = SQLAttribute( temp, VARCHAR, size, "", NONE, false, 0 );
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
					SQLAttribute at2 = SQLAttribute( temp, INT, 32, "", NONE, false, 0 );
					sqlatra.push_back(at2);
				}
				else {
					SQLAttribute at2 = SQLAttribute( temp, INT, 32, "", NONE, false, 0 );
					sqlatra.push_back(at2);
				}
			}
		}
		col = strstr(Psql, "R1E2L3A4T5ION");
		sscanf(col, "%*s %s", atname);
		string temp2(atname);
		command.create_table( temp2, sqlatra );
		return;
	}
	ptr = strstr(Psql, "I1N2S3E4R5T"); // Insert
	if(ptr) {
		char *col = strstr(Psql, "1L2I3T4");
		if(col) {
			vector<string> values;
			while(col!=NULL) {
				sscanf(col, "%*s %s", value);
				string temp(value);
				if(temp[0]== '\"') {
					if(temp[temp.length()-1]!='\"') {
						int i=0;
						while(col[i]!='\"') {
							i++;
						}
						i++;
						temp="\"";
						while(col[i]!='\"') {
							temp+=col[i];
							i++;
						}
						temp+='\"';
					}
					temp=temp.substr(1,temp.length()-2);
				}
				values.push_back(temp);
				col = strstr(col+1, "1L2I3T4");
			}
			col = strstr(Psql, "R1E2L3A4T5ION");
			sscanf(col, "%*s %s", atname);
			string temp(atname);
			SQLRelation *table = command.get_table(temp);
			command.insert_row(table, values);
			return;
		}
		else {
			char* col = strstr(Psql, "R1E2L3A4T5ION");
			vector<SQLRelation*> tables;
			char* table=getrealation(col+1, tables);
			col = strstr(table, "TABLEAT");
			sscanf(col, "%*s %s", atname);
			int loc=-1;
			sscanf(atname, "%d", &loc);
			SQLRelation *newtable=tables[loc];
			col = strstr(Psql, "I1N2S3E4R5T");
			sscanf(col, "%*s %s", atname);
			command.insert_table(atname, newtable);
			return;
		}
	}
	ptr = strstr(Psql, "S1H2O3W"); // Show
	if(ptr) { 
		char* col = strstr(Psql, "S1H2O3W");
		vector<SQLRelation*> tables;
		char* table=getrealation(col+1, tables);
		col = strstr(table, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc=-1;
		sscanf(atname, "%d", &loc);
		SQLRelation *newtable=tables[loc];
		command.show_table(newtable);
		return;
	}
	ptr = strstr(Psql, "W1R2I3T4E"); // Write
	if(ptr) {
		char *col = strstr(Psql, "R1E2L3A4T5ION");
		sscanf(col, "%*s %s", atname);
		string temp(atname);
		command.save_table(temp);
		return;
	}
	ptr = strstr(Psql, "O1P2E3N"); // Open
	if(ptr) {
		char *col = strstr(Psql, "R1E2L3A4T5ION");
		sscanf(col, "%*s %s", atname);
		string temp(atname);
		command.open_table(temp);
		return;
	}
	ptr = strstr(Psql, "C1L2O3S4E"); // Close
	if(ptr) {
		char *col = strstr(Psql, "R1E2L3A4T5ION");
		sscanf(col, "%*s %s", atname);
		string temp(atname);
		command.close_table(temp);
		return;
	}
	ptr = strstr(Psql, "E1X2I3T"); // Exit
	if(ptr) {
		command.clear_command();
		return;
	}
	ptr = strstr(Psql, "D1E2L3E4T5E"); // Delete
	if(ptr) {
		char *col = strstr(Psql, "1O2P3");
		vector<string> where;
		while(col!=NULL) {
			sscanf(col, "%s", atname);
			if(strcmp(atname, "1O2P3") == 0) {
				string op1, op2, op3;
				int i=6;
				if(col[i]=='\"') {
					op1+='\"';
					i++;
					while(col[i]!='\"') {
						op1+=col[i];
						i++;
					}
					op1+='\"';
					i++;
					i++;
				} else {
					while(col[i]!=' ') {
						op1+=col[i];
						i++;
					}
					i++;
				}
				while(col[i]!=' ') {
						op2+=col[i];
						i++;
				}
				i++;
				if(col[i]=='\"') {
					op3+='\"';
					i++;
					while(col[i]!='\"') {
						op3+=col[i];
						i++;
					}
					op3+='\"';
					i++;
					i++;
				} else {
					while(col[i]!=' ') {
						op3+=col[i];
						i++;
					}
					i++;
				}
				string temp = op1+" "+op2+" "+op3+" ";
				where.push_back(temp);
				col = strstr(col, (" "+op3+" ").c_str());
				col = col + op3.length() + 2;
			} else if(strcmp(atname, "||") == 0 || strcmp(atname, "&&") == 0) {
				string temp(atname);
				where.push_back(atname);
				col = col + 3;
			} else {
				break;
			}
		}
		col = strstr(Psql, "R1E2L3A4T5ION");
		sscanf(col, "%*s %s", atname);
		string temp(atname);
		command.delete_row(temp, where);
		return;
	}
	ptr = strstr(Psql, "U1P2D3A4T5E"); // Update
	if(ptr) {
		char *col = strstr(Psql, "1S2E3T4");
		vector<string> where;
		vector<where_obj>setss;
		while(col!=NULL) {
			sscanf(col, "%*s %s %*s %s", atname, value);
			string temp(value);
			if(temp[0]== '\"') {
				if(temp[temp.length()-1]!='\"') {
					int i=0;
					while(col[i]!='\"') {
						i++;
					}
					i++;
					temp="\"";
					while(col[i]!='\"') {
						temp+=col[i];
						i++;
					}
					temp+='\"';
				}
				temp=temp.substr(1,temp.length()-2);
			}
			setss.push_back(where_obj(atname, temp));
			col = strstr(col+1, "1S2E3T4");
		}
		col = strstr(Psql, "1O2P3");
		while(col!=NULL) {
			sscanf(col, "%s", atname);
			if(strcmp(atname, "1O2P3") == 0) {
				string op1, op2, op3;
				int i=6;
				if(col[i]=='\"') {
					op1+='\"';
					i++;
					while(col[i]!='\"') {
						op1+=col[i];
						i++;
					}
					op1+='\"';
					i++;
					i++;
				} else {
					while(col[i]!=' ') {
						op1+=col[i];
						i++;
					}
					i++;
				}
				while(col[i]!=' ') {
						op2+=col[i];
						i++;
				}
				i++;
				if(col[i]=='\"') {
					op3+='\"';
					i++;
					while(col[i]!='\"') {
						op3+=col[i];
						i++;
					}
					op3+='\"';
					i++;
					i++;
				} else {
					while(col[i]!=' ') {
						op3+=col[i];
						i++;
					}
					i++;
				}
				string temp = op1+" "+op2+" "+op3+" ";
				where.push_back(temp);
				col = strstr(col, (" "+op3+" ").c_str());
				col = col + op3.length() + 2;
			} else if(strcmp(atname, "||") == 0 || strcmp(atname, "&&") == 0) {
				string temp(atname);
				where.push_back(atname);
				col = col + 3;
			} else {
				break;
			}
		}
		col = strstr(Psql, "R1E2L3A4T5ION");
		sscanf(col, "%*s %s", atname);
		string temp(atname);
		command.update_data(temp, where, setss);
		SQLRelation *table = command.get_table(temp);
		return;
	}
	ptr = strstr(Psql, "A1S2S3I4G5N"); //Assign
	if(ptr) {
		char* col = strstr(Psql, ">");
		vector<SQLRelation*> tables;
		char* table=getrealation(col+1, tables);
		col = strstr(table, "TABLEAT");
		sscanf(col, "%*s %s", atname);
		int loc=-1;
		sscanf(atname, "%d", &loc);
		SQLRelation *newtable=tables[loc];
		col = strstr(Psql, "A1S2S3I4G5N");
		sscanf(col, "%*s %*s %s", atname);
		string temp(atname);
		command.assign_table(newtable, temp);
		return;
	}
	
	
	
	cout<<"Not Implemented"<<endl;
	return;
}

void ExecuteQuery(string query) {

	char *str = new char[query.length() + 1];
	strcpy(str, query.c_str());
	char* temp = runparser(str);
	if(strcmp(temp,"ERROR") == 0) {
		cout<<"Bad Query"<<endl;
		return;
	}
	queryDB(temp);
}