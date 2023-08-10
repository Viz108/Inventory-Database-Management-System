#include <iostream>
#include <string>
#include <sqlite3.h>
#include "databaseWrapper.h"

using namespace std;

main()
{
    string testDBName; 
    cout << "Enter database name" << endl; 
    cin >> testDBName; 
    databaseWrapper testDB(testDBName);
    testDB.printTable("inventoryTable");
    testDB.addRecord("test product", "inventoryTable", 100);
    testDB.printTable("inventoryTable");
    cout << "Enter id to search" << endl; 
    int searchId;
    cin >> searchId;
    testDB.searchId(searchId);
    cout << "end of program" << endl;
}