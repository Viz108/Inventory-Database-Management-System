#include <iostream>
#include <string>
#include <sqlite3.h>
#include "databaseWrapper.h"

using namespace std;

main()
{
    string testDBName; 
    string nextAction = "a";

    cout << "Enter database name" << endl; 
    getline(cin, testDBName);
    databaseWrapper testDB(testDBName);

    while(nextAction != "q")
    {
        cout << "Select action " << endl;
        getline(cin, nextAction);
        cout << "Next action is " << nextAction << endl;
        if(nextAction == "p")
        {
            testDB.printTable("inventoryTable");\
        }
        else if(nextAction == "s")
        {
            cout << "Enter id to search" << endl; 
            string IdString;
            getline(cin, IdString);
            testDB.searchId(IdString);
        }
        else if(nextAction == "n")
        {
            cout << "Enter name to search: "; 
            string nameInput;
            getline(cin, nameInput);
            testDB.searchName(nameInput);
        }
    }
   
    // testDB.addRecord("test product", "inventoryTable", 100);
    // testDB.printTable("inventoryTable");
    
    cout << "end of program" << endl;
}