#include "databaseWrapper.h"
#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>

using namespace std;

vector<string> databaseWrapper::currColNames;
int databaseWrapper::largestID = 0;

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

    //Check if new (empty) database
    string query = "SELECT name FROM PRAGMA_TABLE_INFO('inventoryTable');";
    char* errorMessage = 0;
    sqlite3_exec(dbPointer, query.c_str(), pullColNames, 0, &errorMessage);
    if(currColNames.empty())
    {
        cout << "New database, creating table" << endl; 
        string newTableQuery = "CREATE TABLE inventoryTable (id INT, productName VARCHAR, quantity INT);";
        sqlite3_exec(dbPointer, newTableQuery.c_str(), nullptr, 0, &errorMessage);
        sqlite3_exec(dbPointer, query.c_str(), pullColNames, 0, &errorMessage);

    }
    else
    {
        //Pull largest ID
        string largestIdQuery = "SELECT MAX(Id) FROM inventoryTable";
        sqlite3_exec(dbPointer, largestIdQuery.c_str(),assignLargestID,0,nullptr);
    }
}

int databaseWrapper::assignLargestID(void *unused, int argc, char **argv, char**azColName)
{
    largestID = stoi(argv[0]);
    nextID = largestID + 1;
    return 0;
}

void databaseWrapper::printTable(string tableName)
{
    string colNames = "SELECT name FROM PRAGMA_TABLE_INFO('inventoryTable');";
    string query = "SELECT * FROM " + tableName;
    char* errorMessage = 0;

    for(int i = 0; i < currColNames.size(); i++)
    {
        cout << currColNames.at(i) << "    "; 
    }
    cout << endl;
    sqlite3_exec(dbPointer, query.c_str(), printHelper, 0, &errorMessage);
    cout << "End of print" << endl;
}

int databaseWrapper::pullColNames(void *unused, int argc, char **argv, char**azColName)
{
    for(int i = 0; i < argc; i++)
    {
        if(argv[i] == NULL)
        {
            currColNames.push_back("NULL");
        }
        else
        {
            currColNames.push_back(argv[i]);
        }
    }
    return 0;
}

int databaseWrapper::printHelper(void *unused, int argc, char **argv, char**azColName)
{
    for(int i = 0; i < argc; i++)
    {
        if(argv[i] == NULL)
        {
            cout << "NULL" << "    ";
        }
        else
        {
            cout << argv[i] << "    ";
        }
    }
    cout << endl;
    return 0;
}

int databaseWrapper::addRecord(string productName, string tableName, int initialQuantity)
{
    cout << "adding record" << endl; 
    string query = "INSERT INTO " + tableName + " (id, productName, quantity) VALUES (" + to_string(nextID) + ", '" + productName + "', " + to_string(initialQuantity) + ");";
    char* errorMessage = 0;
    sqlite3_exec(dbPointer, query.c_str(), nullptr, 0, &errorMessage);
    nextID++;
    return 0;
};

void databaseWrapper::searchId(int id)
{
    string query = "SELECT * FROM inventoryTable WHERE id = " + to_string(id);
    
    for(int i = 0; i < currColNames.size(); i++)
    {
        cout << currColNames.at(i) << "    "; 
    }
    cout << endl;
    sqlite3_exec(dbPointer, query.c_str(), printHelper, 0, nullptr); 
}