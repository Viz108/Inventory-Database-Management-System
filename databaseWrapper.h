#ifndef DATABASEWRAPPER
#define DATABASEWRAPPER
#include <sqlite3.h>
#include <string>

using namespace std;

class databaseWrapper
{
    public: 
        databaseWrapper(string dbName); //Intializes new database and returns pointer
        void printTable(string tableName); //Print all contents of a database table
        void searchForRecord(int id); //Searches for a record using unique ID
        void addRecord(string productName, int initialQuantity); //Adds a new product to the database
        void removeRecord(string productName); //Removes a product from the database
        void changeInventory(string productName, int inventoryChange); //Adds/subtracts quantity of product from database

    private:
        sqlite3* dbPointer;
        static int printColNames(void *unused, int argc, char **argv, char**azColName);
        static int printTableHelper(void *unused, int argc, char **argv, char**azColName);



};


#endif