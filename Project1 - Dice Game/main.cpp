// main.cpp
#include <iostream>
#include "rolldice.h"
#include <ctime>

using namespace std;

int main() {
	//declaring variables:
	srand(time(NULL));
    	int diceValue = roll();
        int diceValue2 = roll();
	string player1Name;
	string player2Name;
	string shooter;
	string fader;

	//Initializing the game:
	cout << "--Gliese dice-rolling game with two players--" << endl;
	cout << "Player 1, please enter your name: ";
	cin >> player1Name;
	cout << "Playe 2, please enter your name: ";
	cin >> player2Name;

	cout << "Welcome, " << player1Name << " and " << player2Name << endl;

	//First roll (deciding who starts the game):
	cout << "Let's decide who starts!" << endl;

	do {


		cout << player1Name << ", press enter to roll: ";
		cin.get();
		cin.get();
		cout << "Number Rolled: " << diceValue << endl;
		cout << player2Name << ", press enter to roll: ";
		cin.get();
		cout << "Number Rolled: " << diceValue2 << endl;

		if (diceValue2 < diceValue) {
			shooter = player1Name;
			fader = player2Name;
		} else if (diceValue2 > diceValue) {
			fader = player1Name;
			shooter = player2Name;
		}

	} while (diceValue == diceValue2);
	//adding some decoration so the game looks a bit nicer on the terminal	
	cout << "-----+ " << shooter << " starts! +-----" << endl;
	
	// Had to declare two new dice rolls inside the loop so they can be random each loop
	// Using a round counting variable to limit the number of possible rounds 
	bool gameover = false;
	int roundCount = 0;

	while (gameover == false) {
		//declared dice variable for each dice for them to be compared later
		int shooterDice = roll(); 
		int shooterDice2 = roll();
		int faderDice = roll();
		int faderDice2 = roll();
	
		// SHOOTER TURN
		cout << shooter << ", press enter to roll: ";
		cin.get();
		cout << "Numbers Rolled: " << shooterDice << " - " << shooterDice2 << endl;
		if ((shooterDice == shooterDice2) && (shooterDice < 5)) {
			cout << fader << " won!" << endl;
			gameover = true;
			break;		
		} else if ((shooterDice == shooterDice2) && (shooterDice > 4)) {
			cout << shooter << " won!" << endl;
			gameover = true;
			break;
		}

		//FADER TURN (if the shooter does not wins)
		cout << fader << ", press enter to roll: ";
		cin.get();
		cout << "Numbers Rolled: " << faderDice << " - " << faderDice2 << endl;
		if ((faderDice == faderDice2) && (faderDice < 5)){
			cout << shooter << " won!" << endl;
			gameover = true;
			break;
		} else if ((faderDice == faderDice2) && (faderDice > 4)) {
			cout << fader << " won!" << endl;
			gameover = true;
			break;	
		}


		roundCount++;
		if (roundCount == 3) {
			cout << "We got a tie!" << endl;
			gameover = true;
			break;
		}
		cout << "+=+=+=+=+=+=+=+=+=+=+=+" << endl;

	}



    	return 0;
}
