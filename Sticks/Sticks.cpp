// Sticks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

int p1h[3] = { 1,1,1 };
int p2h[3] = { 1,1,1 };
int winCon = 0;
int x = 0;
int handInput;
int handAffector;

void combatA() {
	if (handInput == 1) {
		if (handAffector == 1) {
			p2h[1] = p1h[1] + p2h[1];
		}
		if (handAffector == 2) {
			p2h[2] = p1h[1] + p2h[2];
		}
	}
	if (handInput == 2) {
		if (handAffector == 1) {
			p2h[1] = p1h[2] + p2h[1];
		}
		if (handAffector == 2) {
			p2h[2] = p1h[2] + p2h[2];
		}
	}
	if (handInput == 3) {
		if (handAffector == 1) {
			p1h[2] = p1h[1] / 2;
			p1h[1] = p1h[1] / 2;
			if (p1h[1] % 2 == 1) p1h[1] = p1h[1] + 1;
		}
		if (handAffector == 2) {
			p1h[1] = p1h[2] / 2;
			p1h[2] = p1h[2] / 2;
			if (p1h[2] % 2 == 1) p1h[2] = p1h[2] + 1;
		}
	}
}

void combatB() {
	if (handInput == 1) {
		if (handAffector == 1) {
			p1h[1] = p2h[1] + p1h[1];
		}
		if (handAffector == 2) {
			p1h[2] = p2h[1] + p1h[2];
		}
	}
	if (handInput == 2) {
		if (handAffector == 1) {
			p1h[1] = p2h[2] + p2h[1];
		}
		if (handAffector == 2) {
			p1h[2] = p2h[2] + p1h[2];
		}
	}
	if (handInput == 3) {
		if (handAffector == 1) {
			p2h[2] = p2h[1] / 2;
			p2h[1] = p2h[1] / 2;
			if (p2h[1] % 2 == 1) p2h[1] = p2h[1] + 1;
		}
		if (handAffector == 2) {
			p2h[1] = p2h[2] / 2;
			p2h[2] = p2h[2] / 2;
			if (p2h[2] % 2 == 1) p2h[2] = p2h[2] + 1;
		}
	}
}

void handChoice() {
	cout << "Which hand will you use this turn?" << endl;
	cout << "1. Hand One" << endl << " 2. Hand Two" << endl << "3. Split" << endl;
	cin >> handInput;

}

void attackChoice() {
	cout << "Which hand will you use against this turn?" << endl;
	cout << "1. Hand One" << endl << " 2. Hand Two" << endl;
	cin >> handAffector;
}

void handRolloverLogic() {
	if (p1h[1] >= 5) {
		p1h[1] = 0;
	}
	if (p1h[2] >= 5) {
		p1h[2] = 0;
	}
	if (p2h[1] >= 5) {
		p2h[1] = 0;
	}
	if (p2h[2] >= 5) {
		p2h[2] = 0;
	}
}

void playerOne() { // player One's turn
	handChoice(); // Which hand will I use this turn
	attackChoice(); // on which hand will I use against this turn
	combatA();
	handRolloverLogic();
}

void playerTwo() {
	handChoice();
	attackChoice();
	combatB();
	handRolloverLogic();
}

void winCheck() { // does a check to see if either both of player one's hands have reached 0
	if (p1h[1] == 0 && p1h[2] == 0) { 
		winCon = 1;
		x = 1;
	} // check if both of player One's hands equal zero to see if player Two won
	if (p2h[1] == 0 && p2h[2] == 0) {
		winCon = 2;
		x = 1;
	} // vice versa of the previous statement
}

int main()
{
	
	while (x == 0) {
		winCheck(); // does a check to see if either both of player one's hands have reached 0
		cout << "   H1    H2" << endl;
		cout << "P1: " << p1h[1] << "     " << p1h[2] << "     " << "Player One's Turn" << endl;
		cout << "P2: " << p2h[1] << "     " << p2h[2] << endl;
		playerOne(); // Player one's turn
		system("cls");
		winCheck(); // does a check to see if either both of player one's hands have reached 0
		cout << "   H1    H2" << endl;
		cout << "P1: " << p1h[1] << "     " << p1h[2] << "     " << "Player Two's Turn" << endl;
		cout << "P2: " << p2h[1] << "     " << p2h[2] << endl;
		playerTwo(); // player two's turn
		system("cls");
	}

	if (winCon == 1) cout << "Player Two Wins" << endl;
	if (winCon == 2) cout << "Player One Wins" << endl;

	system("Pause");
    return 0;
}

