#ifndef SRC_DBMS_ENUM_H_
#define SRC_DBMS_ENUM_H_

enum SQLType {
	VARCHAR, INT
};

enum SQLIndex {
	NONE, PRIMARY, UNIQUE
};

/**
 * WARNING is the only error code that allows the system
 *  to keep working. Everything else flags a kill query.
 */
enum SQLErrorCode {
	WARNING, LOGIC, SYNTAX, DUPLICATE, LENGTH
};

#endif
