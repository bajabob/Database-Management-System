#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void ExecuteQuery(string query);

int main() {
	
	string query = "CREATE TABLE animals (name VARCHAR(20), kind VARCHAR(8), years INTEGER) PRIMARY KEY (name, kind);";

	ExecuteQuery(query);

	query = "INSERT INTO animals VALUES FROM (\"Joe\", \"cat\", 4);";

	ExecuteQuery(query);

	query = "SHOW animals;";

	ExecuteQuery(query);
	
	cout << "test" << endl;
	
	return 0;
}
