
#ifndef SRC_DBMS_SQL_RELATION_H_
#define SRC_DBMS_SQL_RELATION_H_

using namespace std;

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

#endif
