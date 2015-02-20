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
	//added for testing
	//table.delete_column("name_last");
	//table.delete_row("name_last", "Salas");
	//vector<string> row1 = { "newguy56", "bell", "taco" };
	//table.add_tuple( row1 );
	//cout << table;
}

int main() {

	/*table_with_errors();
	cout << endl << endl;

	table_with_no_errors();
	cout << endl << endl;*/

	load_no_error_table();
	
	
	
	
	
	cout << endl << endl;

}
