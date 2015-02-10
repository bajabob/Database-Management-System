#ifndef SRC_DBMS_SQL_TYPE_DATA_H_
#define SRC_DBMS_SQL_TYPE_DATA_H_

#include <string>

#include "enum.h"
#include "sql_error.h"
#include "sql_attribute.h"
#include "sql_error_manager.h"

using namespace std;

class SQLTypeData {

public:
	string data;

	SQLTypeData(SQLAttribute attr, SQLErrorManager &em, string data) {
		if (data.size() > attr.get_length()) {
			em.add_error(
					SQLError(WARNING,
							"Specified data, '" + data
									+ "' is being truncated because it is too "
									+ "long for the defined attribute '"
									+ attr.get_name()+"'."));
			data.resize(attr.get_length());
		}
		this->data = string(data);
	}

	friend ostream& operator<<(std::ostream& os, const SQLTypeData& obj) {
		os << obj.data;
		return os;
	}
};

#endif
