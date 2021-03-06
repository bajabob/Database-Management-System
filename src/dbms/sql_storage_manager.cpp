#include "sql_storage_manager.h"

using namespace std;

void SQLStorageManager::load_from_value(Json::Value root, vector<SQLAttribute> &attributes,
		vector<SQLTuple> &tuples, SQLErrorManager &em) {
	// load attributes into table
	Json::Value j_attributes = root.get("attributes", 0);
	for (int i = 0; i < j_attributes.size(); ++i) {
		SQLAttribute *at = new SQLAttribute(j_attributes[i]);
		attributes.push_back(*at);
	}

	// load tuples into table
	Json::Value j_tuples = root.get("tuples", 0);
	for (int i = 0; i < j_tuples.size(); ++i) {
		SQLTuple *t = new SQLTuple(j_tuples[i], attributes, em);
		tuples.push_back(*t);
	}

}

void SQLStorageManager::load(SQLErrorManager &em, vector<SQLAttribute> &attributes,
		vector<SQLTuple> &tuples) {

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

		load_from_value(root, attributes, tuples, em); // goto a helper function

	} else {
		cout << " - No DB by that name exists on disk, creating new DB..."
				<< endl;
	}
}

Json::Value SQLStorageManager::save_to_value(vector<SQLAttribute> &attributes,
		vector<SQLTuple> tuples) {

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

	return j_root;
}

void SQLStorageManager::save(SQLErrorManager &em, vector<SQLAttribute> &attributes,
		vector<SQLTuple> tuples) {
	cout << "Saving '" << filename << "' to disk..." << endl;
	// check for no-save errors
	if (em.has_no_save_flagged()) {
		cout << "Can not save '" << filename << "', errors detected"
				<< endl;
		return;
	}
	Json::Value j_root = save_to_value(attributes, tuples);
	// Make a new JSON document for the configuration. Preserve original comments
	Json::StyledWriter writer;
	string outputConfig = writer.write(j_root);
	std::ofstream out(filename, ios::trunc);
	out << outputConfig;
	out.close();
}
