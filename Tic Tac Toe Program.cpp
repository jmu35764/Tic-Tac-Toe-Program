// Tic Tac Toe Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

void initializeBoard(char array[3][3])
{
	//array[3][3] = {'*','*','*'};

	for (int a = 0; a <= 2; a++)
	{
		//cout << "|" << a + 1 << "|" << setw(2) << left << " ";

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


int main()
{
	char empty[3][3];

	initializeBoard(empty);
	displayBoard(empty);

	// placeToken function
	int row;
	int column;

	cout << "Player 1's turn" << endl;
	cout << "Enter row number (must be 1, 2, or 3): ";


	//getlocation()

	cin >> row;

	while (empty[row][column] != '*')
	{
		while (row != 1 || row != 2 || row != 3)
		{
			cout << "Must enter a value from 1 to 3" << endl;
			cin >> row;
		}

		cout << "Enter Column Number (must be 1, 2, or 3): ";
		cin >> column;

		while (column != 1 || column != 2 || column != 3)
		{
			cout << "Must enter a value from 1 to 3" << endl;
			cin >> column;
		}

		if (empty[row][column] != '*')
		{
			cout << "This space is already filled. Pick a new space." << endl;
		}

	}

}


