#include "sql_attribute.h"

string SQLAttribute::get_name() {
	return this->name;
}

SQLType SQLAttribute::get_kind() {
	return this->kind;
}

int SQLAttribute::get_length() {
	return this->length;
}

string SQLAttribute::get_default_value() {
	return this->default_value;
}

SQLIndex SQLAttribute::get_index() {
	return this->index;
}

bool SQLAttribute::has_auto_increment() {
	return this->is_auto_increment;
}

int SQLAttribute::get_auto_increment() {
	return this->auto_increment;
}

void SQLAttribute::on_auto_increment() {
	++this->auto_increment;
}

bool SQLAttribute::compare_for_errors( SQLAttribute attr,
		SQLErrorManager &em ) {

	// no two attributes can have the same name
	if ( attr.get_name() == this->name ) {
		em.add_error(
				SQLError( DUPLICATE,
						"Duplicate attribute name specified, '" + this->name
								+ "' already exists." ) );
		return true;
	}

	// there can only be one primary key in an SQL table
	if ( attr.index == PRIMARY && this->index == PRIMARY ) {
		em.add_error(
				SQLError( SYNTAX,
						this->name
								+ " is already defined as the primary key for "
								+ "the table. There can not be two primary keys." ) );
		return true;
	}
	return false;
}
