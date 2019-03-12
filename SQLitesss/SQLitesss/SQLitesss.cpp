
#include "pch.h"
#include <iostream>
#include "sqlite3.h"
#include <string>

static int zwrot(void *data, int argc, char** argv, char** azColName) {
	int i;

	for (i = 0; i < argc; i++) {
		
		cout << azColName[i] << " = " << (argv[i] ? argv[]);
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	return 0;
}

using namespace std;

int main()
{
	string sql;
	sqlite3 *db;
	char *error;
	sqlite3_open("pliczek.sqlite", &db);

	sql = "create table data(id int, dane varchar(10));";
	sqlite3_exec(db,sql.c_str(),NULL,NULL,&error);


	sql = "insert into data(id dane) values(1,'cos');";
	sqlite3_exec(db, sql.c_str(), NULL, NULL, &error);

	sql = "insert into data(id dane) values(2,'nic');";
	sqlite3_exec(db, sql.c_str(), NULL, NULL, &error);

	sql = "insert into data(id dane) values(3,'a moze');";
	sqlite3_exec(db, sql.c_str(), NULL, NULL, &error);



	string data("CALLBACK FUNCTION")
	sql = "select * from data;";
	sqlite3_exec(db, sql.c_str(), zwrot, (void*)data.c_str(), NULL);

	sqlite3_close(db);

	system("pause");
	return 0;
}
