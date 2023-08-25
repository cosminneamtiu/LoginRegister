// LoginRegister.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

void registeringAccount(string newName, string newPassword) {
    fstream myDb;
    myDb.open("database.txt", ios::app | ios::out);
    myDb << "\nUSER:" << newName;
    myDb << "PASS:" << newPassword << ";";
    myDb.close();
}

void loggingAccount(string presumedName, string presumedPassword) {
    fstream myDb;
    myDb.open("database.txt", ios::in);
    string SearchedAccountCredentials;
    string word;
    SearchedAccountCredentials = "USER:" + presumedName + "PASS:" + presumedPassword + ";";
    cout << endl << SearchedAccountCredentials;
    while (myDb >> word) {
        if (word == SearchedAccountCredentials) {
            cout << "Login is Succesful!";
            break;
        }
    }

}

int main()
{
    int choiceAccount;
    string name;
    string password;
    fstream myDatabaseFile;
    cout << " Do you have an account?\n 1 for yes, 0 for no\n";
    cin >> choiceAccount;
    if (choiceAccount == 1) {
        cout << "Write your name:\n";
        cin >> name;
        cout << "write your password:\n";
        cin >> password;
        loggingAccount(name, password);
    }
    else if (choiceAccount == 0) {
        cout << "Lets get you an account!\nWrite your name:\n";
        cin >> name;
        cout << "write your password:\n";
        cin >> password;
        registeringAccount(name, password);
    }


    myDatabaseFile.close();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
