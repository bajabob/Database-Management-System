#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

#include "enum.h"
#include "sql_type_data.h"
#include "sql_attribute.h"
#include "sql_tuple.h"
#include "sql_relation.h"
#include "sql_query_builder.h"
#include "sql_query_select.h"
#include "sql_command.h"

using namespace std;

/**
 * General table with errors
 */
void table_with_errors() {
	// create table
	SQLRelation table( "error_table" );

	// define all the attributes for the table
	SQLAttribute at1 = SQLAttribute( "id", INT, 8, "", PRIMARY, true, 0 );
	SQLAttribute at2 = SQLAttribute( "username", VARCHAR, 8, "", UNIQUE, false,
			0 );
	SQLAttribute at3 = SQLAttribute( "name_last", VARCHAR, 25, "", NONE, false,
			0 );
	SQLAttribute at4 = SQLAttribute( "name_first", VARCHAR, 25, "", NONE, false,
			0 );

	// add attributes to relation
	table.add_attribute( at1 );
	table.add_attribute( at2 );
	table.add_attribute( at3 );
	table.add_attribute( at4 );
	table.add_attribute( at1 ); // error, duplicate attribute name

	// define data for table
	vector<string> row0 = { "bob27", "Timm", "Robert" };
	vector<string> row1 = { "raf28", "Salas", "Raf" };
	vector<string> row2 = { "nikki22", "Schreier", "Nicolette" };
	vector<string> row3 = { "mike20", "Turner", "Michael" };
	vector<string> dupUser = { "bob27", "Man", "12th" };
	vector<string> tooLong = { "this-is-too-long", "Loftin", "Bowtie" };

	// add data to table
	table.add_tuple( row0 );
	table.add_tuple( row1 );
	table.add_tuple( row2 );
	table.add_tuple( row3 );
	table.add_tuple( dupUser ); // error, username is unique! (contains duplicate)
	table.add_tuple( tooLong ); // warning, username is too long! (gets truncated)

	cout << table;
}

/**
 * General table with no errors
 * Save table to disk
 */
void table_with_no_errors() {
	// create table
	SQLRelation table( "error_free_table" );

	// define all the attributes for the table
	SQLAttribute at1 = SQLAttribute( "id", INT, 8, "", PRIMARY, true, 0 );
	SQLAttribute at2 = SQLAttribute( "username", VARCHAR, 8, "", UNIQUE, false,
			0 );
	SQLAttribute at3 = SQLAttribute( "name_last", VARCHAR, 25, "NO_NAME", NONE,
			false, 0 );
	SQLAttribute at4 = SQLAttribute( "name_first", VARCHAR, 25, "NO_NAME", NONE,
			false, 0 );

	// add attributes to relation
	table.add_attribute( at1 );
	table.add_attribute( at2 );
	table.add_attribute( at3 );
	table.add_attribute( at4 );

	// define data for table
	vector<string> row0 = { "bob27", "Timm" };
	vector<string> row1 = { "raf28", "Salas" };
	vector<string> row2 = { "nikki22", "", "Nicolette" };
	vector<string> row3 = { "mike20", "Turner", "Michael" };

	// add data to table
	table.add_tuple( row0 );
	table.add_tuple( row1 );
	table.add_tuple( row2 );
	table.add_tuple( row3 );

	cout << table;

	table.save();
}

/**
 * Attempt to load a table from disk
 */

void load_no_error_table() {
	SQLRelation table( "error_free_table" );
	table.load();
	// add some more data
	vector<string> row0 = { "newguy55", "Alabama", "BTHO" };
	table.add_tuple( row0 );

	//qb.run_select(0);  

	cout << table;

}

void select_test() {
	SQLCommand command;
	vector<string> ops;
	ops.push_back( "name_last == \"Timm\"" );
	ops.push_back( "name_first != \"NO_NAME\"" );
	ops.push_back( "username != \"newguy55\"" );
	ops.push_back( "&&" );
	ops.push_back( "||" );
	SQLRelation table( "error_free_table" );
	table.load();
	//vector<string> row0 = { "newguy55", "Alabama", "BTHO" };
	//table.add_tuple( row0 );
	table.save();
	//SQLRelation table_2 = command.select(ops, "error_free_table" );
	where_obj wh( "name_last", "awesome" );
	vector<where_obj> updata;
	updata.push_back( wh );
	command.update_data( "error_free_table", ops, updata );
	//command.delete_row("error_free_table", ops);
	//cout<<command.select("error_free_table", ops);
}

void create_test() {
	string tname = "tabletable";
	SQLCommand command;
	vector<string> ops;

	SQLAttribute at1 = SQLAttribute( "id", INT, 8, "", PRIMARY, true, 0 );
	SQLAttribute at2 = SQLAttribute( "username", VARCHAR, 8, "", UNIQUE, false,
			0 );
	SQLAttribute at3 = SQLAttribute( "name_last", VARCHAR, 25, "", NONE, false,
			0 );
	SQLAttribute at4 = SQLAttribute( "name_first", VARCHAR, 25, "", NONE, false,
			0 );
	vector<SQLAttribute> atties { at1, at2, at3, at4 };
	SQLRelation table = command.create_table( tname, atties );
	vector<string> row0 = { "bob27", "Timm", "Robert" };
	table.add_tuple( row0 );
	command.save_table();
	cout << table;
}

void product_test() {
	string left = "lefttable";
	string right = "righttable";

	SQLCommand command;
	SQLAttribute at1 = SQLAttribute( "id", INT, 8, "", PRIMARY, true, 0 );
	SQLAttribute at2 = SQLAttribute( "name", VARCHAR, 8, "", UNIQUE, false, 0 );
	SQLAttribute at3 = SQLAttribute( "age", VARCHAR, 25, "", NONE, false, 0 );

	vector<SQLAttribute> atties1 { at1, at2, at3 };
	SQLRelation lefttable = command.create_table( left, atties1 );
	vector<string> row0 = { "bob", "27" };
	lefttable.add_tuple( row0 );
	vector<string> row1 = { "raf", "28" };
	lefttable.add_tuple( row1 );
	vector<string> row2 = { "mike", "21" };
	lefttable.add_tuple( row2 );

	cout << lefttable << endl;

	SQLAttribute at4 = SQLAttribute( "oid", INT, 8, "", PRIMARY, true, 0 );
	SQLAttribute at5 = SQLAttribute( "amount", VARCHAR, 8, "", UNIQUE, false,
			0 );

	vector<SQLAttribute> atties2 { at4, at5 };
	SQLRelation righttable = command.create_table( right, atties2 );

}

int main() {
	//select_test();
	create_test();
	product_test();
	/*table_with_errors();
	 cout << endl << endl;

	 table_with_no_errors();
	 cout << endl << endl;*/

	//load_no_error_table();
	cout << endl << endl;
	return 0;
}
