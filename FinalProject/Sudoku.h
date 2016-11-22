/* 
This is the class for Sudoku, it holds the 2 dimensional array for each
puzzle and checks the user's input for correctness.

The link where I found the code to change the console text color:
http://stackoverflow.com/questions/4053837/c-colors-in-console-different-colors-in-different-text
*/


#ifndef Sudoku_h
#define Sudoku_h

#include <iostream>
#include <Windows.h>	// Header file needed to change the text color of console
using namespace std;

class Sudoku
{
protected:
	struct Puzz {
		int Ans;
		bool IsClue;
	};
public:
	
	Sudoku() {};		// Default constructor
	Sudoku(Puzz [][9]);	// Constructor
	 ~Sudoku()	{};	// Destructor
	bool IsCorrect(int [][9], Puzz [][9]);		// Checks the puzzle to determine accuracy
	void ShowBoard(Puzz [][9]) const;
	void ShowBoardAns(Puzz [][9]) const;
};


/* Constructor
Each puzzle array is initalized here with the complete numbers.
*/
Sudoku::Sudoku(Puzz Arr[9][9])
{
	ShowBoard(Arr);
}

bool Sudoku::IsCorrect(int Comp[][9], Puzz Arr[9][9])
{
	bool Correct = false;	// Init to false
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (Comp[x][y] != Arr[x][y].Ans)				/******************************* CHECK IF SOLVE WORKS*/
				return Correct = false;
			else
				Correct = false;
		}
	}

	return Correct;
}

/*
ShowBoard displays the incomplete puzzle to the user the first time that
they see it. After they have started entering answers, ShowBoardAns is called
to show the user different text colors.
*/
void Sudoku::ShowBoard(Puzz Arr[][9]) const
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 450, TRUE);
	HANDLE hConsole;
	int Color = 7;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// I got this off the internet, I don't know how it works
	SetConsoleTextAttribute(hConsole, Color);	// Or this.
	int x, y;
	cout << "  ";
	for (int c = 1 ; c <= 9; c++)
	{
		cout << "   " << c;
	}
	cout << "\n   _____________________________________\n" << endl;
		for (x = 0; x < 9; x++)
		{
			cout << x+1 << "  | ";
			for (y = 0; y < 9; y++)
			{
				// To assign the colors, if the element is a clue, it is green,
				// otherwise, 0s are white.
				if (Arr[x][y].IsClue == true)
				{
					Color = 10;
					SetConsoleTextAttribute(hConsole, Color);
					cout << Arr[x][y].Ans;
					Color = 7;
					SetConsoleTextAttribute(hConsole, Color);
					cout << " | ";
				}
				else 
				{
					Color = 15;
					SetConsoleTextAttribute(hConsole, Color);
					cout << Arr[x][y].Ans;
					Color = 7;
					SetConsoleTextAttribute(hConsole, Color);
					cout << " | ";
				}
			}
			cout << "\n   _____________________________________\n" << endl;
		}
}

void Sudoku::ShowBoardAns(Puzz Arr[][9]) const
{
	HANDLE hConsole;
	int Color = 7;	// 7, in the color scheme is 'light white'
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// I got this off the internet, I don't know how it works
	SetConsoleTextAttribute(hConsole, Color);	// Or this.
	int x, y;
	cout << "  ";
	for (int c = 1 ; c <= 9; c++)
	{
		cout << "   " << c;
	}
	cout << "\n   _____________________________________\n" << endl;
		for (x = 0; x < 9; x++)
		{
			cout << x+1 << "  | ";
			for (y = 0; y < 9; y++)
			{
				// To assign the colors, if the element is a clue, it is green, if it is a user answer, it is bright yello
				// otherwise, the 0s are bright white to emphasize which blocks need an answer still
				if (Arr[x][y].IsClue == true)
				{
					Color = 10;	// 10 in the color scheme is bright green
					SetConsoleTextAttribute(hConsole, Color);
					cout << Arr[x][y].Ans;
					Color = 7;
					SetConsoleTextAttribute(hConsole, Color);
					cout << " | ";
				}
				else if (Arr[x][y].Ans != 0 && Arr[x][y].IsClue == false)
				{
					Color = 14;	// 14 in the color scheme is bright yellow
					SetConsoleTextAttribute(hConsole, Color);
					cout << Arr[x][y].Ans;
					Color = 7;
					SetConsoleTextAttribute(hConsole, Color);
					cout << " | ";
				}				
				else if (Arr[x][y].Ans == 0 && Arr[x][y].IsClue == false)
				{
					Color = 15;	// 15 in the color scheme is bright white
					SetConsoleTextAttribute(hConsole, Color);
					cout << Arr[x][y].Ans;
					Color = 7;
					SetConsoleTextAttribute(hConsole, Color);
					cout << " | ";
				}
			}
			cout << "\n   _____________________________________\n" << endl;
		}
}

#endif