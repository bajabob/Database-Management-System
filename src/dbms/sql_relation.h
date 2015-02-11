#ifndef SRC_DBMS_SQL_RELATION_H_
#define SRC_DBMS_SQL_RELATION_H_

#include <map>
#include <string>
#include <vector>

#include "sql_tuple.h"
#include "sql_attribute.h"
#include "sql_type_data.h"
#include "sql_error_manager.h"
#include "jsonfunc.h"

using namespace std;

/**
*By convention private is usually listed after public. It makes it 
*easier for users to see what the public functions are first.
*I'm not trying to be knit picky I promise :). -Raf
*/
class SQLRelation {
private:
	string name; // name of this relation (table)
	vector<SQLAttribute> attr;
	vector<SQLTuple> tuples;
	SQLErrorManager error_manager;
	/**
	 *We are going to need to pass in db file name into this.
	 */
	jclass *json_db;//json class
	
	/**
	 *Adding these functions as private for internal use.
	 *Another function will use these to load the whole table.
	 *Do not call these before jclass::read_db is called or else 
	 *we will get an exception.
	 */	 
	void attr_to_json();// load attributes from a Json::Value
	
	void json_to_attr();// load attr to Json::Value
	
public:

	SQLRelation( string name ) :
			name( name ) {
		/**need destructor now*/	
		json_db = new jclass("file");
	}

	/**
	 * Add a new attribute to this relation (add new column)
	 */
	void add_attribute( SQLAttribute at );

	/**
	 * Add a new row to this relation (add row to table)
	 */
	void add_tuple( string data[], int size );

	/**
	 * Test if a unique value exists in in the
	 *  list of tuples by the specified key
	 */
	bool has_unique( string key, string data );

	

	friend ostream& operator<<( std::ostream& os, const SQLRelation& obj ) {
		os << "\nRelation: " << obj.name << "\n";
		os << "----------------------------\n\n";
		os << "Attributes: " << obj.attr.size() << "\n";
		for ( int i = 0; i < obj.attr.size(); ++i ) {
			os << obj.attr[i];
		}
		os << "----------------------------\n\n";
		os << "Tuples: " << obj.tuples.size() << "\n";
		for ( int i = 0; i < obj.tuples.size(); ++i ) {
			os << obj.tuples[i];
		}
		os << "----------------------------\n\n";
		os << obj.error_manager << endl;
		return os;
	}

};

#endif
