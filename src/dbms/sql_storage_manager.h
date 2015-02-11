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

using namespace std;

class SQLStorageManager {

public:

	SQLStorageManager(string filename) :
			filename(filename) {
		// intentionally blank
	}

	void load(vector<SQLAttribute> &attributes) {

		cout << "Loading '" << filename << "'..." << endl;

		// if the db file exists on disk, load it
		if (this->file_exists(this->filename)) {
			cout << " - Found on disk, loading..." << endl;

			ifstream config_doc(this->filename, ifstream::binary);

			Json::Value root;   // will contains the root value after parsing
			Json::Reader reader;
			bool parsingSuccessful = reader.parse(config_doc, root);
			if (!parsingSuccessful) {
				// report to the user the failure and their locations in the document.
				std::cout << "Failed to parse " << this->filename << endl
						<< reader.getFormattedErrorMessages();
				return;
			}

			// load attributes into table
			Json::Value j_attributes = root.get("attributes", 0);
			for (int i = 0; i < j_attributes.size(); ++i) {
				attributes.push_back( SQLAttribute( j_attributes[i] ) );
			}

		} else {
			cout << " - No DB by that name exists on disk, creating new DB..."
					<< endl;

		}

	}

	void save(SQLErrorManager &em, vector<SQLAttribute> &attributes,
			vector<SQLTuple> tuples) {

		// check for no-save errors
		if (em.has_no_save_flagged()) {
			cout << "Can not save '" << filename << "', errors detected"
					<< endl;
			return;
		}

		// remove old db file
		if (file_exists(filename)) {
			remove(filename.c_str());
		}

		Json::Value j_root;

		// add attributes to json structure
		Json::Value j_attributes(Json::arrayValue);
		for (auto &a : attributes) {
			j_attributes.append(a.to_json());
		}
		j_root["attributes"] = j_attributes;

		// add tuples to json structure
		Json::Value j_tuples(Json::arrayValue);
		for (auto &t : tuples) {
			j_tuples.append(t.to_json());
		}
		j_root["tuples"] = j_tuples;

		// Make a new JSON document for the configuration. Preserve original comments
		Json::StyledWriter writer;
		string outputConfig = writer.write(j_root);

		std::ofstream out(filename);
		out << outputConfig;
		out.close();
	}

private:

	string filename;

	/**
	 * Does the specified file exist?
	 */
	inline bool file_exists(const string& name) {
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	}

}
;

#endif
