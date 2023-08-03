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
}