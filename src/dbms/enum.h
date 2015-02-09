
#ifndef SRC_DBMS_ENUM_H_
#define SRC_DBMS_ENUM_H_


enum SQLType
{
	VARCHAR, INT
};

enum SQLIndex
{
	NONE, PRIMARY, UNIQUE
};

enum SQLStorageOptions
{
	SKIP, STORE, AUTO_INCREMENT
};


#endif
