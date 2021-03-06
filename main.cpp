#include "header.h"

struct user {
int pointsForX, pointsForO;
string playerX, playerO;
};

int main() {
	user player;
    bool running;
    running = true;
	// Initializes the board
	char boardArray[][3] = { {}, {}, {} };
	// Initializes the option
	char option;
	OutputInstruct();
	//Gets the player's option
	option = MainMenu(option, player.playerX, player.playerO);
	// Ends the game if they want to exit
	if (option == 'a' || option == 'A') {
		system("pause");
		return 0;
	} else {
		// Starts the game if they want to play
        while (running) {
			// Fills the board with ' '
			system("cls");
			InitBoard(boardArray);
	        RunGame(boardArray, option, player.playerX, player.playerO, player.pointsForX, player.pointsForO, running);
        }
	}
} // End of main

// Start of RunGame
void RunGame(char boardArray[][3], char option, string& playerX, string& playerO, int& pointsForX, int& pointsForO, bool& stop) {
	if(option == 'c' || option == 'C') {
		OptionC(boardArray, option, playerX, playerO, pointsForX, pointsForO, stop);
	} else if (option == 'd' || option == 'D') {
		OptionD(boardArray, option, playerX, playerO, pointsForX, pointsForO, stop);
	} else {
		cout << "Invalid input." << endl << endl;
		stop = false;
	}
	
} // End of RunGame

void OptionC(char boardArray[][3], char option, string& playerX, string& playerO, int& pointsForX, int& pointsForO, bool& stop) {
	char token;
	char whoWon;
	int index = 0;
	int randomNum = rand() % 10 + 1;
	int computer;
	computer = 0;
    string response;
	if (randomNum % 2 == 0) {
		token = 'X';
	}
	else {
		token = 'O';
	}
	if (option == 'c' || option == 'C') {
		if (playerX == "" || playerO == "") {
			GetPlayers(playerX, playerO, computer);
		}
		//InitBoard(boardArray);
		bool run = true;
		for (int i = 0; i < 16; i++) {
			DisplayBoard(boardArray);
			GetAndCheckInp(boardArray, token, playerX, playerO);
			index++;
			token = SwitchToken(token);
			if (CheckWin(boardArray) == 'X' || CheckWin(boardArray) == 'O') {
				whoWon = CheckWin(boardArray);
				i = 16;
			}
			system("cls");
		}
		CheckWin(boardArray);
		DisplayBoard(boardArray);
		OutputWinner(whoWon, playerX, playerO);
        if(whoWon == 'X') {
            pointsForX += 5;
            cout << endl << playerX << "\'s points : " << pointsForX << endl;
        } else if(whoWon == 'O'){
            pointsForO += 5;
            cout << endl <<  playerO << "\'s points : " << pointsForO << endl;
        }
        cout << endl << "Would you like to play again? (Yes/No) : ";
        cin >> response;
        if (response == "yes" || response == "Yes") {
            stop = true;
        } else if(response == "no" || response == "No"){
            stop = false;
        }
		system("pause");
        system("cls");
	}	
}


void OptionD(char boardArray[][3], char option, string& playerX, string& playerO, int& pointsForX, int& pointsForO, bool& stop){
	playerO = "Computer";
	char token;
	char whoWon;
	int index = 0;
	int randomNum = rand() % 10 + 1;
    string response;

	int computer = 1;

	if (randomNum % 2 == 0) {
		token = 'X';
	}
	else {
		token = 'O';
	}
	 if (option == 'd' || option == 'D') {
		if (playerX == "" || playerO == "") {
			GetPlayers(playerX, playerO, computer);
		}
		//InitBoard(boardArray);
		bool run = true;
		for (int i = 0; i < 16; i++) {
			DisplayBoard(boardArray);
			GetAndCheckInpComputer(boardArray, token, playerX, playerO);
			index++;
			token = SwitchToken(token);
			if (CheckWin(boardArray) == 'X' || CheckWin(boardArray) == 'O') {
				whoWon = CheckWin(boardArray);
				i = 16;
			}
			system("cls");
		}
		CheckWin(boardArray);
		DisplayBoard(boardArray);
		OutputWinner(whoWon, playerX, playerO);
         if(whoWon == 'X') {
            pointsForX += 5;
        } else if(whoWon == 'O'){
            pointsForO += 5;
        }
        cout << endl << "Would you like to play again? (Yes/No) : ";
        cin >> response;
        if (response == "yes" || response == "Yes") {
            stop = true;
        } else if(response == "no" || response == "No"){
            stop = false;
        }
       
		system("pause");
		system("cls");
	}
}