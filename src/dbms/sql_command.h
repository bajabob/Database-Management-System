
#ifndef SRC_DBMS_SQL_COMMAND_H_
#define SRC_DBMS_SQL_COMMAND_H_

#include <string>
#include <vector>
#include "sql_relation.h"
#include "sql_query_select.h"
#include "sql_query_builder.h"
#include "sql_attribute.h"
#include "sql_tuple.h"
#include "sql_storage_manager.h"

class SQLCommand{

public:
	SQLCommand();

	SQLRelation select(vector<string> ops, string name);
	void create_table(string name, vector<SQLAttribute> attrs);
	void assign_table(string name, SQLRelation assign_from);
	void open_table(string name);
	void save_table();//write table to db
	void show_table(string name);
	void close_table();
	void delete_row(string col_name, string row_name);
	void delete_column(string col_name);
	void update_data(string col_name, string row_name);
	void insert_row();
	void print_attribute_type();	
	void exit_all();
	
	

private:
	SQLRelation *table;
	SQLErrorManager error_manager;
};




#endif