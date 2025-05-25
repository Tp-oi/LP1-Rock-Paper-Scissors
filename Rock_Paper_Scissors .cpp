// This is a rock paper scissors game.
//Tyler Parnell

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

class game {
private:
	int userWinCount = 0;  // user's wins
	int compWinCount = 0; // computer's wins

public:
	void incrementUserWin() { userWinCount++; }
	void incrementCompWin() { compWinCount++; }

	void displayWins() {
		cout << "\nYour winnings: " << userWinCount << " Computer winnings: " << compWinCount
			<< "\n**********************************\n";
	}
};


class tool : public game {
private:
	struct toolNumber { // a structure is used instead of an array in order to assign a value to each tool. The tool number is used to calculate the winner or loser
		int number;
		string tool;
	};
	toolNumber tools[3] = {
		{1, "Rock"},
		{2, "Paper"},
		{4, "Scissors"},
		// By assigning scissors a value of 4 there will be 3 unique win outcome values and 3 unique lose outcome values. 
		// If scissors = 3 win and lose outcomes would share a value. 
	};

	int playerTool;
	int computerTool;

public:

	void setPlayerTool() {
		char userTool;
		cout << "\nEnter a tool (r,p,s): ";
		cin >> userTool;
		userTool = tolower(userTool);

		if (userTool != 'r' && userTool != 'p' && userTool != 's' && userTool != 'e') {
			cout << "\nTool choice is not valid, please try again." << endl;
			setPlayerTool(); //use recursive loop to ensure user enters a valid choice
		}

		if (userTool == 'r') { playerTool = 1; }
		if (userTool == 'p') { playerTool = 2; }
		if (userTool == 's') { playerTool = 4; } // For the system of equations to work scissors can not = 3, therefore change to 4.
		if (userTool == 'e') { playerTool = 0; } // Needed to quit the game.
	}

	int getPlayerTool() { return playerTool; } // Use to quit the game.

	void setComputerTool() {
		int choices[] = { 1, 2, 4 }; // Valid tool numbers. Can not use 3 for the scissors for the system of equations to work.
		computerTool = choices[rand() % 3]; // Assign a tool number from the array of valid numbers. 
	}

	string getToolName(int toolNum) {
		for (int i = 0; i < 3; i++) { // Because the tool index numbers and their values are not the same use a for loop to cycle through the tool numbres.
			if (tools[i].number == toolNum) {
				return tools[i].tool;
			}
		}
		return "Unknown"; // This should never execute. 
	}

	void toolReport() {
		cout << "You chose " << getToolName(playerTool) << endl;
		cout << "Computer chose " << getToolName(computerTool) << endl;
	}

	void choseWinner() {
		int diff = playerTool - computerTool; //if R=1, P=2, S=4 the relationship is playerTool-computerTool there will be 3 unique win values and 3 unique lose values.

		if (diff == 0) {
			cout << "It is a tie." << endl;
		}
		else if (diff == -3 || diff == 1 || diff == 2) {
			cout << "You win!" << endl;
			incrementUserWin();
		}
		else if (diff == 3 || diff == -1 || diff == -2) {
			cout << "The computer wins." << endl;
			incrementCompWin();
		}
	}
};


int main() {
	// Problem 2 - Rock Paper Scissors game 
	tool rpsGame;
	cout << "\n***Enter e to end***" << endl;
	while (bool run = true) {
		rpsGame.setPlayerTool();

		if (rpsGame.getPlayerTool() == 0) {
			cout << "Thank you for playing." << endl;
			run = false;
			break;
		}

		rpsGame.setComputerTool();
		rpsGame.toolReport();
		rpsGame.choseWinner();
		rpsGame.displayWins();

	}

}