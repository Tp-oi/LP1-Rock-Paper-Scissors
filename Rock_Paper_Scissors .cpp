// This is a rock paper scissors game.
// Tyler Parnell

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

class game {
 private:
  int userWinCount = 0;  // user's wins
  int compWinCount = 0;  // computer's wins

 public:
  void incrementUserWin() { userWinCount++; }
  void incrementCompWin() { compWinCount++; }

  void displayWins() {
    std::cout << "\nYour winnings: " << userWinCount
              << " Computer winnings: " << compWinCount
              << "\n**********************************\n";
  }
};

class tool : public game {
 private:
  struct toolNumber {  // a structure is used instead of an array in order to
                       // assign a value to each tool. The tool number is used
                       // to calculate the winner or loser
    int number;
    std::string tool;
  };
  toolNumber tools[3] = {
      {1, "Rock"}, {2, "Paper"}, {4, "Scissors"},
      // By assigning scissors a value of 4 there will be 3 unique win outcome
      // values and 3 unique lose outcome values. If scissors = 3 win and lose
      // outcomes would share a value.
  };

  int playerTool;
  int computerTool;

 public:
  void setPlayerTool() {
    char userTool;
    std::cout << "\nEnter a tool (r,p,s): ";
    std::cin >> userTool;
    userTool = tolower(userTool);

    if (userTool != 'r' && userTool != 'p' && userTool != 's' &&
        userTool != 'e') {
      std::cout << "\nTool choice is not valid, please try again." << std::endl;
      setPlayerTool();  // use recursive loop to ensure user enters a valid
                        // choice
    }

    if (userTool == 'r') {
      playerTool = 1;
    }
    if (userTool == 'p') {
      playerTool = 2;
    }
    if (userTool == 's') {
      playerTool = 4;
    }  // For the system of equations to work scissors can not = 3, therefore
       // change to 4.
    if (userTool == 'e') {
      playerTool = 0;
    }  // Needed to quit the game.
  }

  int getPlayerTool() { return playerTool; }  // Use to quit the game.

  void setComputerTool() {
    int choices[] = {1, 2, 4};  // Valid tool numbers. Can not use 3 for the
                                // scissors for the system of equations to work.
    computerTool =
        choices[rand() %
                3];  // Assign a tool number from the array of valid numbers.
  }

  std::string getToolName(int toolNum) {
    for (int i = 0; i < 3;
         i++) {  // Because the tool index numbers and their values are not the
                 // same use a for loop to cycle through the tool numbres.
      if (tools[i].number == toolNum) {
        return tools[i].tool;
      }
    }
    return "Unknown";  // This should never execute.
  }

  void toolReport() {
    std::cout << "You chose " << getToolName(playerTool) << std::endl;
    std::cout << "Computer chose " << getToolName(computerTool) << std::endl;
  }

  void choseWinner() {
    int diff = playerTool -
               computerTool;  // If R=1, P=2, S=4 and the relationship is
                              // playerTool-computerTool there will be 3 unique
                              // win values and 3 unique lose values.

    if (diff == 0) {
      std::cout << "It is a tie." << std::endl;
    } else if (diff == -3 || diff == 1 || diff == 2) {
      std::cout << "You win!" << std::endl;
      incrementUserWin();
    } else if (diff == 3 || diff == -1 || diff == -2) {
      std::cout << "The computer wins." << std::endl;
      incrementCompWin();
    }
  }
};

int main() {
  tool rpsGame;
  std::cout << "\n***Enter e to end***" << std::endl;
  bool run = true;
  while (run) {
    rpsGame.setPlayerTool();

    if (rpsGame.getPlayerTool() == 0) {
      std::cout << "Thank you for playing." << std::endl;
      run = false;
      break;
    }

    rpsGame.setComputerTool();
    rpsGame.toolReport();
    rpsGame.choseWinner();
    rpsGame.displayWins();
  }
}