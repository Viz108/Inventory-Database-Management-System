#include "db_comm_funcs.h"
#include <iostream>
#include <string>
#include <sqlite3.h>

using namespace std;

sqlite3* initDB(string dbName)
{
    sqlite3* returnPointer;
    int returnStatus;

    dbName = dbName + ".db";
    returnStatus = sqlite3_open(dbName.c_str(), &returnPointer);

    if(returnStatus)
    {
        cout << "Error opening database" << endl;
        cout << sqlite3_errmsg(returnPointer) << endl;
        sqlite3_close_v2(returnPointer);
        return nullptr;
    }
    else
    {
        cout << "Successfully opened " + dbName << endl; 
        return returnPointer;
    }
}