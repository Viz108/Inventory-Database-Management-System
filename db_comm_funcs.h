#ifndef DB_COMM_FUNCS
#define DB_COMM_FUNCS

#include <sqlite3.h>
#include <string>

using namespace std;

sqlite3* initDB(string dbName); //Intializes new database and returns pointer
void printDB(); //Print all contents of database
void searchForRecord(int id); //Searches for a record using unique ID
void addRecord(string productName, int initialQuantity); //Adds a new product to the database
void removeRecord(string productName); //Removes a product from the database
void changeInventory(string productName, int inventoryChange); //Adds/subtracts quantity of product from database

#endif