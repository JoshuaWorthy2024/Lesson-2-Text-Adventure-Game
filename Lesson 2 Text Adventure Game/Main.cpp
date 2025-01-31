#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/*
Objective: Create a branching text-based adventure game set in a haunted house.

Instructions:

Design a game with at least 3 rooms or decision points.
Each room must present 2-3 choices, leading to different outcomes, such as:
Progressing to the next room.
A “gruesome demise.”
Successfully escaping the haunted house.
Use both if statements and switch statements to handle choices and outcomes.
Track the player’s progress using variables.
Requirements:

Include at least one nested condition (e.g., a switch inside an if).
Handle invalid input gracefully.
Ensure at least one path leads to a successful escape and one to a failure.
*/

/* Room planning:
Room 0:
Choices:
-Sealed exit
-Room 1
-Gruesome Demise

Room 1:
Choices:
-Room 0
-Gruesome Demise
-Room 2

Room 2:
Leads to:
-Room 0
-Room 1
-Successful escape
*/

int g_Choice = -1;

void selectChoice() {
	cout << "Please enter a choice (1-3): ";
	cin >> g_Choice;

	if (g_Choice < 1 || g_Choice > 3) {
		g_Choice = -1;
	}
	cout << endl << endl;
}

int main() {
	bool isRunning = true;
	int currentRoom = 0;

	while (isRunning) {
		cout << "Current Room: " << currentRoom << endl << endl;
		switch (currentRoom) {
		case 0:
			selectChoice();
			if (g_Choice == 1) {
				cout << "This exit is sealed." << endl << endl;
			}
			else if (g_Choice == 2) {
				currentRoom = 1;
				cout << "You navigate to a new room." << endl << endl;
			}
			else if (g_Choice == 3) {
				cout << "You meet a gruesome demise.." << endl << endl;
				isRunning = false;
			}
			break;
		case 1:
			selectChoice();
			if (g_Choice == 1) {
				currentRoom = 0;
				cout << "You navigate to a familiar room.." << endl << endl;
			}
			else if (g_Choice == 2) {
				currentRoom = 2;
				cout << "You navigate to a new room." << endl << endl;
			}
			else if (g_Choice == 3) {
				cout << "You meet a gruesome demise.." << endl << endl;
				isRunning = false;
			}
			break;
		case 2:
			selectChoice();
			if (g_Choice == 1) {
				currentRoom = 0;
				cout << "You navigate to a familiar room.." << endl << endl;
			}
			else if (g_Choice == 2) {
				currentRoom = 1;
				cout << "You navigate to a familiar room.." << endl << endl;
			}
			else if (g_Choice == 3) {
				cout << "You successfully escape the dungeon!" << endl << endl;
				isRunning = false;
			}
			break;
		}
	}

	return 0;
}