#ifndef SRC_DBMS_SQL_RELATION_H_
#define SRC_DBMS_SQL_RELATION_H_

/*	We can create the data base and entries by using the jclass here.
 By initializing the jclass here we can have access to its Json::Value
 and jclass' functions to build and get a table from the DB

 */

using namespace std;

class SQLRelation
{
private:
	string name; // name of this ralation (table)
	vector<SQLAttribute> attr;
	vector<SQLTuple> tuples;

public:

	SQLRelation( string name ) :
			name( name )
	{
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

		for ( int i = 0; i < attr.size(); ++i )
		{
			// this is an ID column, and is auto incrementing (skip data[])
			if ( attr[i].index == PRIMARY && attr[i].auto_increment )
			{
				tuple->add_attribute( attr[i].name,
						to_string( attr[i].auto_increment ) );
				attr[i].auto_increment++;
				continue;
			}

			// this column is UNIQUE, check table for pre-existing data
			//...

			// Fall through - this is not a fancy column, just add it
			tuple->add_attribute( attr[i].name, data[data_offset] );
			data_offset++;
		}

		// test for errors (need error reporting class within this table)
		// then add tuple to table
		this->tuples.push_back( *tuple );
	}

	friend ostream& operator<<( std::ostream& os, const SQLRelation& obj )
	{
		os << "Relation: " << obj.name << "\n";
		os << "Attributes:\n";
		for ( int i = 0; i < obj.attr.size(); ++i )
		{
			os << obj.attr[i];
		}
		os << "Tuples:\n";
		for ( int i = 0; i < obj.tuples.size(); ++i )
		{
			os << obj.tuples[i];
		}
		return os;
	}

};

#endif
