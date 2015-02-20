#ifndef SRC_DBMS_SQL_RELATION_H_
#define SRC_DBMS_SQL_RELATION_H_

#include <map>
#include <string>
#include <vector>

#include "sql_tuple.h"
#include "sql_attribute.h"
#include "sql_type_data.h"
#include "sql_error_manager.h"
#include "sql_storage_manager.h"

using namespace std;

class SQLRelation {

public:

	SQLRelation(string name) :
			name(name), storage_manager(name+".db") {
	}

	/**
	 * Add a new attribute to this relation (add new column)
	 */
	void add_attribute(SQLAttribute at);

	/**
	 * Add a new row to this relation (add row to table)
	 * This function fills in the table left to right, so the first element
	 *  in the vector assumes the leftmost column, and so on. The function
	 *  will automatically skip columns that can't accept data, like an
	 *  auto incrementing primary key.
	 */
	void add_tuple(vector<string> data);

	/**
	 * Test if a unique value exists in in the
	 *  list of tuples by the specified key
	 */
	bool has_unique(string key, string data);

	/**
	 * Get a vector of all the attribute names for this relation
	 */
	vector<string> get_attribute_names();
	
	vector<SQLTuple> get_tuples()const {
		return this->tuples;
	}
	/**
	 * Attempt to save this table to disk, if there are any
	 *  errors in the storage manager it will be prevented
	 */
	void save(){
		storage_manager.save(error_manager, attributes, tuples);
	}

	/**
	 * Attempt to find this table on disk, if it doen't exist on
	 *  disk, do nothing.
	 */
	void load(){
		storage_manager.load(error_manager, attributes, tuples);
	}

	/**
	*delete columns and rows associated with given attribute name
	*/
	void delete_column(string attr);  
	void delete_row(string attr, string data);
	
	friend ostream& operator<<(std::ostream& os, const SQLRelation& obj) {
		os << "\nRelation: " << obj.name << "\n";
		os << "----------------------------\n\n";
		os << "Attributes: " << obj.attributes.size() << "\n";
		for (int i = 0; i < obj.attributes.size(); ++i) {
			os << obj.attributes[i];
		}
		os << "----------------------------\n\n";
		os << "Tuples: " << obj.tuples.size() << "\n";
		for (int i = 0; i < obj.tuples.size(); ++i) {
			os << obj.tuples[i];
		}
		os << "----------------------------\n\n";
		os << obj.error_manager << endl;
		return os;
	}

	
private:
	string name; // name of this relation (table)
	vector<SQLAttribute> attributes;
	vector<SQLTuple> tuples;
	SQLErrorManager error_manager;
	SQLStorageManager storage_manager;

};

#endif
