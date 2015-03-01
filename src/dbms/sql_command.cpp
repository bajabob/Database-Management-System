#include "sql_command.h"

SQLCommand::SQLCommand(){}

SQLRelation SQLCommand::select( SQLRelation tab, vector<string> ops){
	SQLQuerySelect sel(tab);
	sel.select_cmd(ops);
	SQLQueryBuilder qb(tab,sel);
	SQLRelation ret_table = qb.run_select(0);
	tab.load();
	ret_table.change_name( tab.get_name()+ "1" );
	return ret_table;
}

void SQLCommand::delete_row(string name, vector<string> ops){
	if(table == NULL || table->get_name()== name)
		open_table(name);
	SQLQuerySelect sel(*table);
	sel.delete_cmd(name, ops);
	SQLQueryBuilder qb(*table,sel);
	*table = qb.run_select(0);
}

void SQLCommand::update_data(string name, vector<string> constraint,vector<where_obj> updata){
	if(table == NULL || table->get_name()== name)
		open_table(name);
	SQLQuerySelect sel(*table);
	*table = sel.update_cmd(constraint, updata);
}

SQLRelation get_table(string name){
	for(int i = 0;i < tables.size();++i){
		if(tables[i]->)
	
	
	
	}
}

SQLRelation SQLCommand::create_table(string name, vector<SQLAttribute> attrs){
	table = new SQLRelation(name);	
	for(int i = 0;i< attrs.size() ; ++i)
		table->add_attribute(attrs[i]);
	return *table;
}

void SQLCommand::insert_row(SQLRelation &relation, vector<string> tuples){
		relation.add_tuple(tuples);
}

void SQLCommand::assign_table(string name, SQLRelation assign_from){

	table = new SQLRelation(name);
	*table = assign_from;
	table->save();
	
}
//needs work
void SQLCommand::open_table(string name){
  table = new SQLRelation(name);
  table->load();
}
//needs work
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
