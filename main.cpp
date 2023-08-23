#include <iostream>
#include <string>
#include <sqlite3.h>
#include "databaseWrapper.h"

using namespace std;

main()
{
    cout << "C++ Inventory Management v 0.1" << endl << endl;

    cout << "Enter the name of the database file you wish to open. If it doesn't exist, a new file will be created." << endl;
    string databaseName;
    getline(cin, databaseName);
    databaseWrapper database(databaseName);

    //Enter main loop
    string nextCommand = "placeholder";

    while(nextCommand != "q" && nextCommand != "quit")
    {
        cout << "Select next command (type h for help): " << endl;
        getline(cin, nextCommand);
    }
}