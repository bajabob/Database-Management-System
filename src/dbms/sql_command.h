
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

	SQLRelation *select(SQLRelation *tab, vector<string> ops);
	void delete_row(string name, vector<string> constraint);
	void update_data(string name, vector<string> constraint,vector<where_obj> updata);
	SQLRelation *get_table(string name);
	SQLRelation *project(SQLRelation *tab, vector<string> colnames);
	SQLRelation *rename_attr(SQLRelation *tab,vector<string> colnames);
	SQLRelation *create_table(string name, vector<SQLAttribute> attrs);
	void i_dont_give_a_damn(SQLRelation *tab, string name);
	void insert_row(SQLRelation *relation, vector<string> tuples);
	void insert_table(string name, SQLRelation *assign_from);
	void open_table(string name);
	void save_table(string name);//write table to db
	void show_table(SQLRelation *relation);
	void close_table(string name);
	
	void clear_command();
	
	SQLRelation* product(SQLRelation *table_left, SQLRelation *table_right);
	SQLRelation* union_tables(SQLRelation *table_left, SQLRelation *table_right);
	SQLRelation* difference(SQLRelation *table_left, SQLRelation *table_right);

private:
	vector<SQLRelation*> tables; 
	SQLErrorManager error_manager;
};


#endif
