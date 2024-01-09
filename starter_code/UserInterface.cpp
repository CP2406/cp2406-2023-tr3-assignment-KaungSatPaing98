// CP2406 Assignment - Kaung Sat Paing - 14399033

#include "Debugger.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <vector>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db); // No criteria for use of this function in the assignemnt
Database generateNewDB(Database& db);
Database loadDBfromFile();
const string checkFileName();
void editEmployee(Database& db);
void searchEmployee(Database& db);

int main()
{
    log("entered"); // Enable or disable debugging in Debugger.h
    Database employeeDB;
    string dbFileName;

	bool done = false;
	while (!done) {

        int selection = displayMenu();

		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
        case 7:
            employeeDB = generateNewDB(employeeDB);
            break;
        case 8:
            dbFileName = checkFileName();
            employeeDB.saveDBtoFile(dbFileName);
            break;
        case 9:
            employeeDB = loadDBfromFile();
            break;
        case 10:
            editEmployee(employeeDB);
            break;
        case 11:
            searchEmployee(employeeDB);
            break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}
    
    log("exited");
	return 0;
}

int displayMenu()
{
	// Note:
	//		One important note is that this code assumes that the user will
	//		"play nice" and type a number when a number is requested.
	//		When you read about I/O in Chapter 13, you will learn how to
	//		protect against bad input.

    log("entered");
    int selection;

    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) List all employees" << endl;
    cout << "5) List all current employees" << endl;
    cout << "6) List all former employees" << endl;
    cout << "7) Generate new database" << endl;
    cout << "8) Save database to file" << endl;
    cout << "9) Load database from file" << endl;
    cout << "10) Edit employee" << endl;
    cout << "11) Search employee" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    
	cin >> selection;

	return selection;
    log("exited");
}
void doHire(Database& db)
{
    string firstName;
    string lastName;

    cout << "First name? ";
    cin >> firstName;
    cout << "Last name? ";
    cin >> lastName;
    
    db.addEmployee(firstName, lastName);
}

void doFire(Database& db)
{
    int employeeNumber;

    cout << "Employee number? ";
    cin >> employeeNumber;

    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } catch (const std::logic_error& exception) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void doPromote(Database& db)
{
    int employeeNumber;
    int raiseAmount;

    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "How much of a raise? ";
    cin >> raiseAmount;

    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
    } catch (const std::logic_error& exception) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}
