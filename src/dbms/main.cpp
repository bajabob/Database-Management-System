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

using namespace std;

int main() {
	/**
	 * Trying to mimic the JSON file in the design docs! Refer to it
	 *  when looking at the following code
	 */

	// create table
	SQLRelation table("test_table");

	// define all the attributes for the table
	SQLAttribute at1 = SQLAttribute("id", INT, 8, "", PRIMARY, true, 0);
	SQLAttribute at2 = SQLAttribute("username", VARCHAR, 25, "", UNIQUE, false,
			0);
	SQLAttribute at3 = SQLAttribute("name_last", VARCHAR, 25, "", NONE, false,
			0);
	SQLAttribute at4 = SQLAttribute("name_first", VARCHAR, 25, "", NONE, false,
			0);

	// add attributes to relation
	table.add_attribute(at1);
	table.add_attribute(at2);
	table.add_attribute(at3);
	table.add_attribute(at4);
	table.add_attribute(at1); // error, duplicate attribute name

	// define data for table
	string row0[] = { "bob27", "Timm", "Robert" };
	string row1[] = { "raf28", "Salas", "robert" };
	string row2[] = { "nikki22", "Schreier", "Nicolette" };
	string row3[] = { "mike20", "Turner", "Michael" };
	string dupUser[] = {"bob27", "Man", "12th"};

	// add data to table
	table.add_tuple(row0);
	table.add_tuple(row1);
	table.add_tuple(row2);
	table.add_tuple(row3);
	table.add_tuple(dupUser); // error, username is unique! (contains duplicate)

	cout << table;

}
