#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"


using namespace std;



void displayMenu() {													//function to display menu with output statements to display formated menu
	cout << setfill('*') << setw(26) << "" << endl;
	cout << setfill(' ');
	cout << setw(25) << left << "* 1 - Add One Hour" << "*" << endl;
	cout << setw(25) << left << "* 2 - Add One Minute" << "*" << endl;
	cout << setw(25) << left << "* 3 - Add One Second" << "*" << endl;
	cout << setw(25) << left << "* 4 - Exit Program" << "*" << endl;
	cout << setfill('*') << setw(26) << "" << endl;
	cout << setfill(' ');
}
