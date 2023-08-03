#include "databaseWrapper.h"
#include <iostream>
#include <string>
#include <sqlite3.h>

using namespace std;

databaseWrapper::databaseWrapper(string dbName)
{
    int status;

    dbName = dbName + ".db";
    status = sqlite3_open(dbName.c_str(), &dbPointer);

    if(status)
    {
        cout << "Error opening database" << endl;
        cout << sqlite3_errmsg(dbPointer) << endl;
        sqlite3_close_v2(dbPointer);
    }
    else
    {
        cout << "Successfully opened " + dbName << endl; 
    }
}

void databaseWrapper::printTable(string tableName)
{
    string query = "SELECT * FROM " + tableName;
    char* errorMessage = 0;

    sqlite3_exec(dbPointer, query.c_str(), printTableHelper, 0, &errorMessage);
}

static int printTableHelper(void *unused, int argc, char **argv, char**azColName)
{
    
}
