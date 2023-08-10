#ifndef DATABASEWRAPPER
#define DATABASEWRAPPER
#include <sqlite3.h>
#include <string>
#include <vector>

using namespace std;

class databaseWrapper
{
    public: 
        databaseWrapper(string dbName); //Intializes new database and returns pointer
        void printTable(string tableName); //Print all contents of a database table
        int addRecord(string productName, string tableName, int initialQuantity); //Adds a new product to the database, returns product ID
        void searchForRecord(int id); //Searches for a record using unique ID
        void removeRecord(string productName); //Removes a product from the database
        void changeInventory(string productName, int inventoryChange); //Adds/subtracts quantity of product from database

    private:
        sqlite3* dbPointer;
        inline static int nextID = 1; 
        static vector<string> currColNames; //Note - needs to be static and emptied when current db is closed
        string testString;

        //Potential to do - implement buffers in these functions so they can be reused elsewhere
        static int pullColNames(void *unused, int argc, char **argv, char**azColName); 
        static int printTableHelper(void *unused, int argc, char **argv, char**azColName);



};


#endif