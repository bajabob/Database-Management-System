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

int main()
{
	/**
	 * Trying to mimic the JSON file in the design docs! Refer to it
	 *  when looking at the following code
	 */

	// create table
	SQLRelation table("test_table");

	// define all the attributes for the table
	SQLAttribute at1 = SQLAttribute( "id", INT, 8, "", PRIMARY, true, 3 );
	SQLAttribute at2 = SQLAttribute( "username", VARCHAR, 25, "", UNIQUE, false,
			0 );
	SQLAttribute at3 = SQLAttribute( "name_last", VARCHAR, 25, "", NONE, false,
			0 );
	SQLAttribute at4 = SQLAttribute( "name_first", VARCHAR, 25, "", NONE, false,
			0 );

	// add the actual attributes to the table (defined above)
	table.add_attribute( at1 );
	table.add_attribute( at2 );
	table.add_attribute( at3 );
	table.add_attribute( at4 );

	/**
	 * What would be a good way to automatically skip the ID column
	 * and let it auto increment when a tuple is added?
	 * Is there another way to add data and just say "you pick a value for me"
	 * If no default value is supplied, refer to auto-increment if possible,
	 * THEN throw an error.
	 */

	// not specifying an ID! need's to figure one out
	string row1[] = { "bob12", "timm", "robert" };
	table.add_tuple( row1 );

	// can someone override << operator so we can print some output?

	cout << table;

}
