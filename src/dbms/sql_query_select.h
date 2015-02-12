#ifndef SRC_DBMS_SQL_QUERY_SELECT_H_
#define SRC_DBMS_SQL_QUERY_SELECT_H_

#include <string>
#include <vector>

using namespace std;

class SQLQuerySelect {

public:

	SQLQuerySelect() {
	}

	SQLQuerySelect(vector<string> attributes) :
			select(select) {

	}

private:
	vector<string> select;

};

#endif
