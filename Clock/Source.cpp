#include <iostream>
#include <chrono>
#include <ctime>
#include "Header.h"
#include "Header1.h" 
#include <thread>

using namespace std;
char userKey = '0';
bool running = true;

int main() {
	getTime();
	displayClocks();
	do {
		userKey = 0;
		runningClock();
		if (_kbhit()) {
			running = false;
			userKey = _getch();
		}
		else {
			continue;
		}
		if (userKey == '1') {
			addHour();
			running = true;
		}
		else if (userKey == '2') {
			addMin();
			running = true;
		}
		else if (userKey == '3') {
			addMin();
			running = true;
		}
		else if (userKey == '4') {
			cout << "You have now exited the program";
			running = false;
		}
		else {
			running = true;
			continue;

		}
	} while (running == true);

	return 0;
}

