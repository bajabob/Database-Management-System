#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum SQLType
{
	VARCHAR, INT
};

enum SQLIndex
{
	NONE, PRIMARY, UNIQUE
};

enum SQLStorageOptions
{
	SKIP, STORE, AUTO_INCREMENT
};

class SQLTypeData
{

public:
	string data;

	SQLTypeData( string data )
	{
		this->data = string( data );
	}
};

class SQLAttribute
{
public:
	string name;
	SQLType kind;
	int length;
	string default_value;
	SQLIndex index;
	bool auto_increment;

	SQLAttribute( string name, SQLType kind, int length, string default_value,
			SQLIndex index, bool auto_increment )
	{
		this->name = string( name );
		this->kind = SQLType( kind );
		this->length = int( length );
		this->default_value = string( default_value );
		this->index = SQLIndex( index );
		this->auto_increment = bool( auto_increment );
	}

};

class SQLTuple
{
private:
	map<string, SQLTypeData> data;

public:
	SQLTuple()
	{
	}
	void add_attribute( string name, string data )
	{
		this->data.insert(
				pair<string, SQLTypeData>( name, SQLTypeData( data ) ) );
	}
};

class SQLRelation
{
private:
	int auto_increment;
	vector<SQLAttribute> attr;
	vector<SQLTuple> tuples;
public:

	SQLRelation()
	{
		auto_increment = 0;
	}

	void set_auto_increment( int inc )
	{
		this->auto_increment = inc;
	}

	void add_attribute( SQLAttribute at )
	{
		this->attr.push_back( at );
	}

	void add_tuple( string data[] )
	{
		int data_offset = 0;
		bool had_auto_increment = false;
		SQLTuple* tuple = new SQLTuple();

		for ( int i = 0; i <  attr.size(); ++i)
		{
			// this is an ID column, and is auto incrementing (skip data[])
			if(attr[i].index == PRIMARY && attr[i].auto_increment)
			{
				tuple->add_attribute(attr[i].name, to_string(auto_increment));
				auto_increment++;
				continue;
			}

			// this column is UNIQUE, check table for pre-existing data
			//...

			// Fall through - this is not a fancy column, just add it
			tuple->add_attribute(attr[i].name, data[data_offset]);
			data_offset++;
		}

		// test for errors (need error reporting class within this table)
		// then add tuple to table
		this->tuples.push_back(*tuple);
	}

};

int main()
{
	/**
	 * Trying to mimic the JSON file in the design docs! Refer to it
	 *  when looking at the following code
	 */

	// create table
	SQLRelation table;

	// define all the attributes for the table
	SQLAttribute at1 = SQLAttribute( "id", INT, 8, "", PRIMARY, true );
	SQLAttribute at2 = SQLAttribute( "username", VARCHAR, 25, "", UNIQUE,
			false );
	SQLAttribute at3 = SQLAttribute( "name_last", VARCHAR, 25, "", NONE,
			false );
	SQLAttribute at4 = SQLAttribute( "name_first", VARCHAR, 25, "", NONE,
			false );

	table.set_auto_increment( 3 );

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

}
