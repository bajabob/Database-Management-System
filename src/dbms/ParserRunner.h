#ifndef PARSER_RUNNER
#define PARSER_RUNNER

 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "Parser.h"
#include "Lexer.h"

#include "enum.h"
#include "sql_type_data.h"
#include "sql_attribute.h"
#include "sql_tuple.h"
#include "sql_relation.h"
#include "sql_query_builder.h"
#include "sql_query_select.h"
#include "sql_command.h"

#define MAX_QUERY_SIZE 1000
#define MAX_AT_SIZE 1000
#define MAX_VALUE_SIZE 1000

using namespace std;

void ExecuteQuery(string query);


#endif