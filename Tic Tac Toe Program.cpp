// Tic Tac Toe Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int row;
int column;

void initializeBoard(char array[3][3])
{

	for (int a = 0; a <= 2; a++)
	{
		for (int b = 0; b <= 2; b++)
		{
			array[a][b] = '*';
		}
	}
}

void displayBoard(char array[3][3])
{
	//Numbers on top Row
	cout << setw(5) << left << " " << setw(3) << left << "1" << setw(3) << left << "2" << setw(3) << left << "3" << endl;

	//Dashed Line
	cout << setw(4) << left << "  " << "---------" << endl;

	// Tic tac toe grid
	for (int x = 0; x <= 2; x++)
	{
		cout << "|" << x + 1 << "|" << setw(2) << left << " ";

		for (int y = 0; y <= 2; y++)
		{
			cout << setw(3) << left << array[x][y];
		}

		cout << endl;

	}
	cout << endl;
	cout << "(Hit enter to continue)" << endl;
	cout << endl;
}

void getLocation(int &row, int &column)
{
		cout << "Enter Row Number (must be 1, 2, or 3): ";
		cin >> row;
		while (row < 0 || row > 3)
		{
			cout << "Must enter a row value from 1 to 3" << endl;
			cin >> row;
		}

		cout << "Enter Column Number (must be 1, 2, or 3): ";
		cin >> column;

		while (0>column || column>3)
		{
			cout << "Must enter a column value from 1 to 3" << endl;
			cin >> column;
		}

}
string checkForWinner(char token, char board[3][3])
{
	string output;
	int three = 0;
	int counter = 0;
	//int across = 0;
	//int down = 0;

	if (token == board[0][0] && board[0][0] == board[0][1] && board[0][0] == board[0][2])
	{
		three = 1;
		output = "WIN";
		return output;
	}

	else if (token == board[1][0] && board[1][0] == board[1][1] && board[1][0] == board[1][2])
	{
		three = 1;
		output = "WIN";
		return output;
	}
	else if (token == board[2][0] && board[2][0] == board[2][1] && board[2][0] == board[2][2])
	{
		three = 1;
		output = "WIN";
		return output;
	}
	else if (token == board[0][0] && board[0][0] == board[1][0] && board[0][0] == board[2][0])
	{
		three = 1;
		output = "WIN";
		return output;
	}
	else if (token == board[0][1] && board[0][1] == board[1][1] && board[0][1] == board[2][1])
	{
		three = 1;
		output = "WIN";
		return output;
	}
	else if (token == board[0][2] && board[0][2] == board[1][2] && board[0][2] == board[2][2])
	{
		three = 1;
		output = "WIN";
		return output;
	}
	else if (token == board[0][0] && board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		three = 1;
		output = "WIN";
		return output;
	}
	else if (token == board[0][2] && board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		three = 1;
		output = "WIN";
		return output;
	}

	while (three == 0 && counter <= 9)
	{
		for (int a = 0; a <= 2; a++)
		{
			for (int b = 0; b <= 2; b++)
			{
				if (board[a][b] == '*')
				{
					output = "SPACE_LEFT";
					return output;
				}
				else
				{
					counter++;
				}
			}
		}
	}

	if (counter == 9)
	{
		output = "NO_SPACE";
		return output;
	}
}

string getBoardState(char token, char array[3][3])
{
	string STATE = checkForWinner(token, array);

	if (STATE == "SPACE_LEFT")
	{
		return "PLAY";
	}
	else if (STATE == "NO_SPACE")
	{
		return "TIE";
	}
	else if (STATE == "WINNER")
	{
		if (token == 'X')
		{
			return "X_WINS";
		}

		else if (token == 'O')
		{
			return "O_WINS";
		}

	}

}

void placeToken(char token, char array[3][3])
{
	getLocation(row, column);

	while(array[row-1][column-1] != '*')
	{
		cout << "This space is already filled. Pick a new space." << endl;
		getLocation(row, column);
	}

	array[row - 1][column - 1] = token;
}


int main()
{
	char empty[3][3];
	int turn = 1;
	bool nowin = true;
	char player1_token = 'X';
	char player2_token = 'O';
	string boardstate = "PLAY";


	initializeBoard(empty);
	displayBoard(empty);

	while (boardstate == "PLAY")
	{

			cout << "Player 1's turn." << endl;
			placeToken(player1_token, empty);
			displayBoard(empty);
			boardstate = getBoardState(player1_token, empty);

			if (boardstate == "PLAY")
			{
				cout << "Player 2's turn." << endl;
				placeToken(player2_token, empty);
				displayBoard(empty);
			}
	}


	cout << boardstate << endl;

	if (boardstate == "X_WINS")
	{
		cout << "Player 1 wins" << endl;
	}
	
	else if (boardstate == "O_WINS")
	{
		cout << "Player 2 wins" << endl;
	}

	else if (boardstate == "TIE")
	{
		cout << "Tie" << endl;
	}

}


