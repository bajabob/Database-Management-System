
#ifndef SRC_DBMS_SQL_COMMAND_H_
#define SRC_DBMS_SQL_COMMAND_H_

#include <string>
#include <vector>
#include "sql_relation.h"
#include "sql_query_select.h"
#include "sql_query_select.h"

class SQLCommand{

public:
	SQLCommand(){
	
	
	
	}

	
	void delete_row();
	void delete_column();
	void create_table();
	void open_table();
	void save_table();//write table to db
	void show_table();
	void close_table();
	void update();
	void insert();
	void print_attribute_type();	
	void exit_all();
	
	

private:
	SQLRelation *table;

};




#endif