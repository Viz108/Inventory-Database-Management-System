#include <iostream>
#include <string>
#include <sqlite3.h>
#include "db_comm_funcs.h"

using namespace std;

main()
{
    string testDBName; 
    cout << "Enter database name" << endl; 
    cin >> testDBName; 
    sqlite3* testDB = initDB(testDBName);
}