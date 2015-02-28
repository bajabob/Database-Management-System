#include "sql_command.h"

SQLCommand::SQLCommand(){}

SQLRelation SQLCommand::select(vector<string> ops, string name){
	open_table(name);
	SQLQuerySelect sel(*table);
	sel.select_cmd(ops, name);
	SQLQueryBuilder qb(*table,sel);
	qb.run_select(0);
	SQLRelation ret_table = *table;
	open_table(name);
	return ret_table
}

void SQLCommand::create_table(string name, vector<SQLAttribute> attrs){
	table = new SQLRelation(name);	
	for(int i = 0;i< attrs.size() ; ++i)
		table->add_attribute(attrs[i]);
}

void SQLCommand::assign_table(string name, SQLRelation assign_from){
	table = new SQLRelation(name);
	*table = assign_from;
	table->save();
}

void SQLCommand::open_table(string name){
  table = new SQLRelation(name);
  table->load();
}

void SQLCommand::show_table(string name){
	open_table(name);
	cout<<"\n"<<table;
	close_table();
}

void SQLCommand::save_table(){
	if(table != NULL)
		table->save();
}

void SQLCommand::close_table(){
	if(table != NULL)
		table = NULL;
}

void SQLCommand::delete_row(string col_name, string row_name){
	table->delete_row(col_name, row_name);
}

void SQLCommand::delete_column(string col_name){
	table->delete_column(col_name);
}

void SQLCommand::update_data(string col_name, string row_name){
	/*if(table != NULL){
		vector<SQLTuple> tups = table->get_tuples();
		for()
		
	}
	else{
		cout<<"\n table not open"
	}*/
}

void SQLCommand::insert_row(){}

void SQLCommand::print_attribute_type(){}

void SQLCommand::exit_all(){}