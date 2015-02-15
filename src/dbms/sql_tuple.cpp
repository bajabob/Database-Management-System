#include "sql_tuple.h"

SQLTuple::SQLTuple( Json::Value node, vector<SQLAttribute> &attributes,
		SQLErrorManager &em ) {
	vector<string> j_keys = node.getMemberNames();
	for ( int i = 0; i < j_keys.size(); ++i ) {

		for ( int j = 0; j < attributes.size(); ++j ) {
			SQLAttribute &at = attributes[j];
			if ( at.get_name() == j_keys[i] ) {
				keys.push_back( j_keys[i] );
				this->data.insert(
						pair<string, SQLTypeData>( j_keys[i],
								SQLTypeData( at, em,
										node[j_keys[i]].asString() ) ) );
				break;
			}
		}
	}
}

void SQLTuple::add_attribute( SQLAttribute &attr, string data,
		SQLErrorManager &em ) {
	this->data.insert(
			pair<string, SQLTypeData>( attr.get_name(),
					SQLTypeData( attr, em, data ) ) );
	this->keys.push_back( attr.get_name() );
}

bool SQLTuple::has_matching_data( string key, string data ) {
	SQLTypeData s = this->data.find( key )->second;
	return data == s.get_data();
}

Json::Value SQLTuple::to_json() {
	Json::Value node;
	for ( auto &col : this->keys ) {
		node[col] = this->data.find( col )->second.get_data();
	}
	return node;
}

/*void SQLTuple::delete_data(string attr){
	std::map<string, SQLTypeData>::iterator it;
	std::vector<string>::iterator it_2;
	it = data.find(attr);
	data.erase(it);
	it_2 = find(keys.begin(), keys.end(), attr);
	keys.erase(it_2);
}
*/




