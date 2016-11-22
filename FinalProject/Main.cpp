// This is a game program that uses Sudoku puzzles

#include <iostream>
#include "Sudoku.h"
#include "Hard.h"
#include "Easy.h"
#include "VeryEasy.h"
#include "Medium.h"
#include <Windows.h>

using namespace std;

int Menu();	// Menu function prototype
void EasyPuzz(Easy);
void MedPuzz(Medium);
void HardPuzz(Hard);

// Global variable

/*Medium MPuzzle;
Hard HPuzzle; */

// Constants for the menu choices
const int EASY = 1,
		  MED = 2,
		  HARD = 3,
		  QUIT = 4;

int main()
{
	int Choice;


	cout << "\t\t\tWelcome to Hart Sudoku!\n\n" << endl;
	

	Choice = Menu();	// Calls the menu function
	if (Choice == 1)
	{
		cout << "You have chosen an easy puzzle. When doing the puzzle, you "
			 << "will enter an X and\nY coordinate to change an answer. If you "
			 << "enter a coordinate that is a clue, you will receive an error. " 
			 << "If you'd like to check to see if you've solved the puzzle "
			 << "type S instead of coordinates.\n" << endl;
		Easy EPuzzle(1);
		//EPuzzle.ShowPuzz();
		EasyPuzz(EPuzzle);
	}
	else if (Choice == 2)
	{
		cout << "You have chosen a medium puzzle. When doing the puzzle, you "
			 << "will enter an X and\nY coordinate to change an answer. If you "
			 << "enter a coordinate that is a clue, you will receive an error."
			 << "If you'd like to check to see if you've solved the puzzle "
			 << "type S instead of coordinates.\n"<< endl;
		Medium MPuzzle;
		MedPuzz(MPuzzle);
	}
	else if (Choice == 3)
	{
		cout << "You have chosen a hard puzzle. When doing the puzzle, you "
			 << "will enter an X and\nY coordinate to change an answer. If you "
			 << "enter a coordinate that is a clue, you will receive an error. "
			 << "You can get a hint by entering H instead of a number."
			 << "If you'd like to check to see if you've solved the puzzle "
			 << "type S instead of coordinates.\n"<< endl;
		Hard HPuzzle;
		HardPuzz(HPuzzle);
	}
	else if (Choice == 4)
	{
		cout << "Thank you for playing!" << endl;
		exit(0);
	}



	return 0;
}

int Menu()
{
	int Choice;
	cout << "Please choose from the following menu options to start a "
		 << "sudoku puzzle.\n"
		 << "1. Easy Puzzle\n"
		 << "2. Medium Puzzle\n"
		 << "3. Hard Puzzle\n"
		 << "4. Quit" << endl;
	cin >> Choice;
	while (Choice > 4 || Choice < 1)
	{
		cout << "Invalid option, please enter a valid number, 1 - 4: ";
		cin >> Choice;
	}
	return Choice;
}

void EasyPuzz(Easy EPuzzle)
{
	bool Solved = false;
	int X;
	int Y, Answer;

	while (!Solved)
	{
		cout << "Enter a number for an X coordinate to answer the puzzle (or S to solve): ";
		cin >> X;
		if (!isalpha(X))
		{
			cout << "Enter a number for a Y coordinate to answer the puzzle: ";
			cin >> Y;
			cout << "Enter the number you would like for the answer: ";
			cin >> Answer;
			EPuzzle.AddNum(X, Y, Answer);
		}
		else if (isalpha(X))	// If the user entered S to solve
		{
			X = static_cast<char> (X);
			if (X == 'S')
			{
				Solved = EPuzzle.Solve();
				if (Solved)
				{
					cout << "Congratulations, you solved the puzzle!" << endl;
					Menu();
				}
				else
				{
					cout << "You have not solved the puzzle. Please check your answers "
						 << "and try again." << endl;
				}
			}
		}
		else
		{
			cout << "Please enter only digits 1-9 or S to solve. Please try again." << endl;
		}
	}
}

void MedPuzz(Medium MPuzzle)
{
	bool Solved = false;

	int X;
	int Y, Answer;

	while (!Solved)
	{
		cout << "Enter a number for an X coordinate to answer the puzzle (or S to solve): ";
		cin >> X;
		if (!isalpha(X))
		{
			cout << "Enter a number for a Y coordinate to answer the puzzle: ";
			cin >> Y;
			cout << "Enter the number you would like for the answer: ";
		cin >> Answer;
		MPuzzle.AddNum(X, Y, Answer);
		}
		else if (isalpha(X))	// If the user entered S to solve
		{
			X = static_cast<char> (X);
			if (X == 'S' || X == 's')
			{
				Solved = MPuzzle.Solve();
				if (Solved)
				{
					cout << "Congratulations, you solved the puzzle!" << endl;
					Menu();
				}
				else
				{
					cout << "You have not solved the puzzle. Please check your answers "
						 << "and try again." << endl;
				}
			}
		}
	}	
}

void HardPuzz(Hard HPuzzle)
{
	bool Solved = false;

	int X;
	int Y, Answer;
	
	while (!Solved)
	{
		cout << "Enter a number for an X coordinate to answer the puzzle (or S to solve, H for hint): ";
		cin >> X;
		if (!isalpha(X))
		{
			cout << "Enter a number for a Y coordinate to answer the puzzle: ";
			cin >> Y;
			cout << "Enter the number you would like for the answer: ";
		cin >> Answer;
		HPuzzle.AddNum(X, Y, Answer);
		}
		else if (isalpha(X))	// If the user entered S to solve
		{
			X = static_cast<char> (X);

			if (X == 'S' || X == 's')
			{
				Solved = HPuzzle.Solve();
				if (Solved)
				{
					cout << "Congratulations, you solved the puzzle!" << endl;
					Menu();
				}
				else
				{
					cout << "You have not solved the puzzle. Please check your answers "
						 << "and try again." << endl;
				}
			}
			else if (X == 'H' || X == 'h')
			{
				cout << "Enter a number for an X coordinate to get a hint: ";
				cin >> X;
			cout << "Enter a number for a Y coordinate to get a hint: ";
			cin >> Y;

			HPuzzle.Hint(X, Y);
			}
				
		}
	}
}