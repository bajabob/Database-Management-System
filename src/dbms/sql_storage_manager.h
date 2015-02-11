#ifndef SRC_DBMS_SQL_STORAGE_MANAGER_H_
#define SRC_DBMS_SQL_STORAGE_MANAGER_H_

#include <vector>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

#include "sql_error.h"
#include "sql_tuple.h"
#include "sql_attribute.h"
#include "sql_type_data.h"
#include "sql_error_manager.h"
#include "json/json.h"
#include "jsonfunc.h"

using namespace std;

class SQLStorageManager {

public:

	SQLStorageManager( string filename ) :
			filename( filename ) {
		// intentionally blank
	}

	void load( SQLErrorManager &em, vector<SQLAttribute> &attributes , vector<SQLTuple> &tuples) {

		cout << "Loading '" << filename << "'..." << endl;

		// if the db file exists on disk, load it
		if ( this->file_exists( this->filename ) ) {
			cout << " - Found on disk, loading..." << endl;

			ifstream config_doc( this->filename, ifstream::binary );

			Json::Value root;   // will contains the root value after parsing
			Json::Reader reader;
			bool parsingSuccessful = reader.parse( config_doc, root );
			if ( !parsingSuccessful ) {
				// report to the user the failure and their locations in the document.
				std::cout << "Failed to parse " << this->filename << endl
						<< reader.getFormattedErrorMessages();
				return;
			}

			// load attributes into table
			Json::Value j_attributes = root.get( "attributes", 0 );
			for ( int i = 0; i < j_attributes.size(); ++i ) {
				SQLAttribute *at = new SQLAttribute( j_attributes[i] );
				attributes.push_back( *at );
			}

			// load tuples into table
			Json::Value j_tuples = root.get( "tuples", 0 );
			for ( int i = 0; i < j_tuples.size(); ++i ) {
				SQLTuple *t = new SQLTuple( j_tuples[i], attributes, em );
				tuples.push_back( *t );
			}

		} else {
			cout << " - No DB by that name exists on disk, creating new DB..."
					<< endl;

		}

	}

	void save( SQLErrorManager &em, vector<SQLAttribute> &attributes,
			vector<SQLTuple> tuples ) {

		cout << "Saving '" << filename << "' to disk..." << endl;

		// check for no-save errors
		if ( em.has_no_save_flagged() ) {
			cout << "Can not save '" << filename << "', errors detected"
					<< endl;
			return;
		}

		// remove old db file
		if ( file_exists( filename ) ) {
			remove( filename.c_str() );
		}

		Json::Value j_root;

		// add attributes to json structure
		Json::Value j_attributes( Json::arrayValue );
		for ( auto &a : attributes ) {
			j_attributes.append( a.to_json() );
		}
		j_root["attributes"] = j_attributes;

		// add tuples to json structure
		Json::Value j_tuples( Json::arrayValue );
		for ( auto &t : tuples ) {
			j_tuples.append( t.to_json() );
		}
		j_root["tuples"] = j_tuples;

		// Make a new JSON document for the configuration. Preserve original comments
		Json::StyledWriter writer;
		string outputConfig = writer.write( j_root );

		std::ofstream out( filename );
		out << outputConfig;
		out.close();
	}

private:

	void load_attribute();
	void save_attribute();
	jclass json_manager;
	string filename;

	/**
	 * Does the specified file exist?
	 */
	inline bool file_exists( const string& name ) {
		struct stat buffer;
		return (stat( name.c_str(), &buffer ) == 0);
	}
}
;



void SQLStorageManager::save_attribute(vector<SQLAttribute> &attributes){
	for(int i = 0;i<attributes.size();++i){
		json_db->to_json("attributes", "name", attributes[i].get_name(), i);	
		json_db->to_json("attributes", "kind", to_string(attributes[i].get_kind()), i);
		json_db->to_json("attributes", "length", to_string(attributes[i].get_length()), i);
		json_db->to_json("attributes", "default", attributes[i].get_default_value(), i);
		json_db->to_json("attributes", "index", to_string(attributes[i].get_index()), i);
		json_db->to_json("attributes", "is_auto_increment",	\
			to_string(attributes[i].has_auto_increment()), i);
		json_db->to_json("attributes", "auto_increment",	\
			to_string(attr[i].get_auto_increment()), i);		
	}
}


void SQLStorageManager::load_attribute(vector<SQLAttribute> &attributes){
	attributes.clear();
	vector<string> at_name, at_default;
	vector<SQLType> at_kind;
	vector<int> at_length, at_bauto, at_auto;
	vector<SQLIndex> at_indx;
	Json::Value j_attributes = json_db.get( "attributes", 0 );
	for(int i = 0;i<j_attributes.size();++i){
		at_name.push_back(json_db->from_json("attributes", "name", i));	
		at_kind.push_back(	
			SQLType(stoi(json_db->from_json("attributes", "kind", i))));	
		at_length.push_back(stoi(json_db->from_json("attributes", "length", i)));
		at_default.push_back(json_db->from_json("attributes", "default" , i));
		at_indx.push_back(SQLIndex(stoi(json_db->from_json("attributes", "index", i))));
		at_bauto.push_back(	
			stoi(json_db->from_json("attributes", "is_auto_increment", i))); 
		at_auto.push_back(stoi(json_db->from_json("attributes", "auto_increment", i)));		
	}
	for(int j = 0;j<j_attributes.size();++j){
		attributes.push_back(	SQLAttribute(at_name[j], at_kind[j], at_length[j],
		at_default[j], at_indx[j], at_bauto[j], at_auto[j]));
	}
}












#endif
