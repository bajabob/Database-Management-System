#include "sql_tuple.h"


void SQLTuple::add_attribute( SQLAttribute &attr, string data,
		SQLErrorManager &em ) {
	this->data.insert(
			pair<string, SQLTypeData>( attr.get_name(),
					SQLTypeData( attr, em, data ) ) );
	this->keys.push_back( attr.get_name() );
}


bool SQLTuple::has_matching_data( string key, string data ) {
	SQLTypeData s = this->data.find( key )->second;
	return data == s.data;
}
