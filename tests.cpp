#include <iostream>
#include <string>
#include <sqlite3.h>
#include "databaseWrapper.h"

using namespace std;

main()
{
    string testDBName; 
    char nextAction;

    cout << "Enter database name" << endl; 
    cin >> testDBName; 
    databaseWrapper testDB(testDBName);
    cout << "Select action " << endl;
    cin >> nextAction;
    if(nextAction == 'p')
    {
        testDB.printTable("inventoryTable");\
    }
    else if(nextAction == 's')
    {
        // cout << "Enter id to search" << endl; 
        // int searchId;
        // cin >> searchId;
        // testDB.searchId(searchId);
    }
    else if(nextAction == 'n')
    {
        cout << "Enter name to search" << endl; 
        string nameInput;
        cin >> nameInput;
        testDB.searchName(nameInput);
    }
    // testDB.addRecord("test product", "inventoryTable", 100);
    // testDB.printTable("inventoryTable");
    
    cout << "end of program" << endl;
}