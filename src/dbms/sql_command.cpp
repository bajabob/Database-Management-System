#include "sql_command.h"

SQLCommand::SQLCommand(){}

SQLRelation *SQLCommand::select( SQLRelation *tab, vector<string> ops){
	if(tab==NULL) {
		return NULL;
	}
	SQLQuerySelect sel(*tab);
	sel.select_cmd(ops);
	SQLQueryBuilder qb(*tab,sel);
	SQLRelation *ret_table = new SQLRelation(tab->get_name()+"1");
	 *ret_table = qb.run_select(0);
	ret_table->change_name( tab->get_name()+ "1" );
	return ret_table;
}

void SQLCommand::delete_row(string name, vector<string> ops){
	SQLRelation *table = get_table(name);
	if(table==NULL) {
		return;
	}
	SQLQuerySelect sel(*table);
	sel.delete_cmd(name, ops);
	SQLQueryBuilder qb(*table,sel);
	*table = qb.run_select(0);
}

void SQLCommand::update_data(string name, vector<string> constraint,vector<where_obj> updata){
	SQLRelation *table = get_table(name);
	if(table==NULL) {
		return;
	}
	SQLQuerySelect sel(*table);
	*table = sel.update_cmd(constraint, updata);
}

SQLRelation *SQLCommand::get_table(string name){
	for(int i = 0;i < tables.size();++i){
		if(tables[i]->get_name() == name ){
			return tables[i];
		}
	}
	cout<<"\nerror table  does not exist";
	return NULL;
}

SQLRelation *SQLCommand::project(SQLRelation *tab, vector<string> colnames){
	if(tab==NULL) {
		return NULL;
	}
	SQLRelation *table = new SQLRelation(tab->get_name()+" Projection");	
	SQLQuerySelect sel(*tab);
	sel.projet_cmd(colnames);
	SQLQueryBuilder qb(*tab,sel);
	*table = qb.run_select(1);
	table->change_name(tab->get_name()+" Projection");
	return table;
}

SQLRelation *SQLCommand::rename_attr(SQLRelation *tab, vector<string> colnames){
	if(tab==NULL) {
		return NULL;
	}
	SQLRelation *table = new SQLRelation(tab->get_name());
	vector<vector<string>> rows;
	vector<SQLAttribute> att = tab->rename_attributes( colnames, rows);
	for(auto &at : att){
		table->add_attribute(at);
	}
	for(auto &row : rows){
		table->add_tuple( row);
	}
	table->fix_auto_increment();
	return table;
}

SQLRelation *SQLCommand::create_table(string name, vector<SQLAttribute> attrs){
	SQLRelation *table = new SQLRelation(name);	
	for(int i = 0;i< attrs.size() ; ++i)
		table->add_attribute(attrs[i]);
	tables.push_back(table);	
	return table;
}

void SQLCommand::insert_row(SQLRelation *relation, vector<string> tuples){	
	if(relation==NULL) {
		cout<<"\nerror table  does not exist";
		return;
	}
	relation->add_tuple(tuples);
}


void SQLCommand::assign_table(SQLRelation *tab, string name){
	if(tab==NULL) {
		cout<<"\nerror table  does not exist";
		return;
	}
	SQLRelation *table = new SQLRelation(name);
	*table = *tab;
	table->change_name(name);
	tables.push_back(table);

}

void SQLCommand::insert_table(string name, SQLRelation *assign_from){
	if(assign_from==NULL) {
		cout<<"\nerror table  does not exist";
		return;
	}
	SQLRelation *table ;
	table = get_table(name);
	if(table==NULL) {
		return;
	}
	table->insert_table(*assign_from);
}

void SQLCommand::open_table(string name){
	SQLRelation *table = new SQLRelation(name);
	table->load();
	tables.push_back(table);
}

void SQLCommand::show_table(SQLRelation *relation){
	if(relation==NULL) {
		cout<<"\nerror table  does not exist";
		return;
	}
	cout<<"\n"<<*relation;
}

void SQLCommand::save_table(string name){
	SQLRelation *table = get_table(name);
	if(table==NULL) {
		return;
	}
	table->save();
}

void SQLCommand::close_table(string name){
	vector<SQLRelation*>::iterator it = find(tables.begin(),tables.end(),get_table(name));
	tables.erase(it);
}

void SQLCommand::clear_command() {
	tables.clear();
}

SQLRelation* SQLCommand::product(SQLRelation *table_left, SQLRelation *table_right){
	if(table_left==NULL || table_right==NULL) {
		return NULL;
	}
	return table_left->product(table_right);
}

SQLRelation* SQLCommand::union_tables(SQLRelation *table_left, SQLRelation *table_right){
	if(table_left==NULL || table_right==NULL) {
		return NULL;
	}
	return table_left->union_tables(table_right);
}

SQLRelation* SQLCommand::difference(SQLRelation *table_left, SQLRelation *table_right){
	if(table_left==NULL || table_right==NULL) {
		return NULL;
	}
	return table_left->difference(table_right);
}
