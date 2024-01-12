// LogIn and Sign-Up system
// CP2406 Assignment - Kaung Sat Paing - 14399033

#include <iostream>
#include <stdexcept>
#include <exception>
#include <vector>
#include "LogInDataBase.h"

using namespace std;
using namespace Records;

int employeeDisplayMenu();
void signUp(LogInDataBase& logInDB);
void validate(LogInDataBase& logInDB);

// int main()
// {

// string user, pass;
// bool manager = false;
//LogIn employee;
//int selection;

// bool done = false;
// while (!done) {

//     selection = employeeDisplayMenu();
    
//     switch(selection){
// 		case 0:
// 			done = true;
// 			break;
// 		case 1:
//             signUp();
//             break;
//         case 2:
//             validate(employee);
//             break;
//         default:
//             cerr << "Unknown command." << endl;
// 			break;
//     }

// }

// LogInDataBase employee;

// cout << "TESTING: signUp()" << endl;
// signUp(employee);
// signUp(employee);
// signUp(employee);

// cout << "TESTING: displayAll()" << endl;
// employee.displayAll();

// cout << "TESTING: validate()" << endl;
// validate(employee);


//}


int employeeDisplayMenu()
{
    int userSelection;

    cout << endl;
    cout << "Select from the following options: " << endl;
    cout << "1) Sign-up" << endl;
    cout << "2) Log-in" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> userSelection;

    return userSelection;
}

void signUp(LogInDataBase& logInDB)
{
    string user, pass;
    bool manager = false;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;
    cout << "Are you a manager 'true' or 'false': ";
    cin >> manager;
    cout << endl;

    logInDB.addNewUser(user, pass, manager);
    cout << "Welcome " << user << endl;
}

void validate(LogInDataBase& logInDB)
{
    string user, pass;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    LogIn& userToCheck = logInDB.getUser(user, pass);

}