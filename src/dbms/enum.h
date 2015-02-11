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
 *
 *  Also Note:
 *   If you want to alert to the user to an error but don't want to
 *   kill the query be sure to use the WARNING error code.
 */
enum SQLErrorCode {
	WARNING, LOGIC, SYNTAX, DUPLICATE
};

#endif
