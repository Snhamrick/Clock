#pragma once
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <string>
#include <cstdlib>
#include <thread>
#include "conio.h"
#include "Header1.h"


using namespace std::chrono;

tm rawTime;																	//declaration of tm type variable
char twelveString[20] = "";													//declartion of empty string to store time for 12 hour clock
char twentyFourString[20] = "";												//declation of empty string to store time for 24 hour clock
std::string relationToNoon = "A M";											//declation of varible abbreviation for AM or PM

tm getTime() {																//function to get system clock time
	auto time = system_clock::to_time_t(system_clock::now());				//retrieve sytem clock save as auto-typed variable
	localtime_s(&rawTime, &time);											//convert time to useable tm data type
	return rawTime;															//return tm data type of current time
}
/*FIXME: need to debug all time scenarios when program runs correctly. Ensure that top of hour
top of minute function correctly. Ensure 24 hour clock and 12 hour clock have corect hour displayed
and correct AM PM on 12 hour clock*/


void setClock24() {															//function to set time for 24 hour clock								
	strftime(twentyFourString, 20, "%T", &rawTime);							//set 24 hour clock
}
void setClock12() {															//function to set time for 12 hour clock
	if (rawTime.tm_hour >= 12) {
		relationToNoon = "P M";
	}
	if (rawTime.tm_hour == 0) {
		rawTime.tm_hour = 12;
		relationToNoon = "A M";
		strftime(twelveString, 20, "%T", &rawTime);
		rawTime.tm_hour = 0;
	}
	else if (rawTime.tm_hour > 12) {												//if statement to adjust 12 hour clock for hours over 12														
		rawTime.tm_hour = rawTime.tm_hour - 12;								//subtract 12 from hours
		strftime(twelveString, 20, "%T", &rawTime);							//set 12 hour clock
		rawTime.tm_hour = rawTime.tm_hour + 12;								//reset hour to original time for further use
	}
	else {																	//else statement to set clock if hour is less than 12
		strftime(twelveString, 20, "%T", &rawTime);							//set 12 hour clock
	}
}
void displayClocks() {														//function to display clocks in desired format
	setClock24();															//set 24 hour clock prior to display
	setClock12();															//set 12 hour clock prior to display
	std::cout << std::setw(51) << std::left << "*************************\t*************************" << std::endl;
	std::cout << std::setw(45) << std::left << "*    12-Hour Clock\t*\t*     24-Hour Clock" << "*" << std::endl;
	std::cout << "*     " << twelveString << " " << relationToNoon << "\t*\t*\t" << twentyFourString << "\t*" << std::endl;
	std::cout << std::setw(51) << std::left << "*************************\t*************************" << std::endl;

}



void addHour() {														//function to add 1 hour
	rawTime.tm_hour = rawTime.tm_hour + 1;
	if (rawTime.tm_hour > 23) {										//if statement to prevent illegal parameter in time
		rawTime.tm_hour = 0;											//reset hour to 0 after hour 23
	}
	system("cls");														//clear screen
	displayClocks();													//display clocks
	displayMenu();														//display menu
}

void addMin() {															//function to add 1 minute
	rawTime.tm_min = rawTime.tm_min + 1;
	if (rawTime.tm_min == 60) {											//if statement to prevent illegal parameter in time
		rawTime.tm_min = 0;												//reset minute to 0 after minute 59
		addHour();														//add hour
	}
	else {																//else statement for when time is not at the top of the hour
		system("cls");													//clear screen
		displayClocks();												//display clocks
		displayMenu();													//display menu
	}
}
void addSec() {															//function to add 1 minute
	rawTime.tm_sec = rawTime.tm_sec + 1;
	if (rawTime.tm_sec == 60) {											//if statement to prevent illegal parameter in time
		rawTime.tm_sec = 0;												//reset seconds to 0 after second 59
		addMin();														//add minute
	}
	else {																//else statement for when second is not top of the minute
		system("cls");													//clear screen
		displayClocks();												//display clocks
		displayMenu();													//display menu
	}
}
char halt;
void runningClock() {													//function for refreshing clokc FIXME: requires while loop to properly run
	seconds ss(1);
	std::this_thread::sleep_for(ss);
	system("cls");
	addSec();
}
