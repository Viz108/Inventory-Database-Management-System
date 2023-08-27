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
        cout << "\nSelect next command (type h for help): " << endl;
        getline(cin, nextCommand);

        if(nextCommand == "h")
        {
            cout << "Options:\n"  
                     "p - print table\n"
                     "i - search by id\n"
                     "n - search by name\n"
                     "a - add record\n"
                     "d - delete record\n"
                     "m - modify record quantity\n"
                     "q - quit\n";
        }
        else if(nextCommand == "p")
        {
            database.printTable("inventoryTable");
        }
        else if(nextCommand == "i")
        {
            cout << "Enter id to search: "; 
            string IdString;
            getline(cin, IdString);
            database.searchId(IdString);
        }
        else if(nextCommand == "n")
        {
            cout << "Enter name to search: "; 
            string nameInput;
            getline(cin, nameInput);
            database.searchName(nameInput);
        }
        else if(nextCommand == "a")
        {
            cout << "Enter new record's product name: ";
            string newName;
            getline(cin, newName);
            cout << "Enter initial quantity: ";
            string initQuantity; 
            getline(cin, initQuantity);
            database.addRecord(newName, "inventoryTable", stoi(initQuantity));
            cout << "Record added" << endl; 
        }
        else if(nextCommand == "d")
        {
            cout << "Enter name of product to delete: ";
            string deleteName; 
            getline(cin, deleteName);
            database.removeRecord(deleteName);
            cout << "Record removed" << endl; 
        }
        else if(nextCommand == "m")
        {
            cout << "Enter name of product to modify quantity: ";
            string modifyName;
            getline(cin, modifyName);
            cout << "Enter new quantity: ";
            string modifyQuantity;
            getline(cin, modifyQuantity);
            database.changeInventory(modifyName, stoi(modifyQuantity));
        }
        else if(nextCommand == "q")
        {
            cout << "Exiting program..." << endl;
        }
        else if(nextCommand != "q")
        {
            cout << "Command not recongized, enter a valid command (type h for help)" << endl; 
        }
    }
}