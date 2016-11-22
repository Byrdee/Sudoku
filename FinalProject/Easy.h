/* 
This is the class for Easy puzzles.
*/

#include <iostream>
#include "Sudoku.h"

using namespace std;


class Easy : protected Sudoku
{
private:
	int Comp[9][9];		// Comp is the completed puzzle
	Puzz Puzzle[9][9];	// Puzzle is what the user sees
	
public:
	Easy();
	Easy(int);
	~Easy()
	{ delete [] &Puzzle; }
	void AddNum(int, int, int);	// Add a number to solve the puzzle
	bool Solve();
	void ShowPuzz();
};

Easy::Easy()
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			Comp[x][y] = 0;
			Puzzle[x][y].Ans = 0;
			Puzzle[x][y].IsClue = false;
		}
	}
}

/*
The default constructor initializes the arrays to hold the
completed and partial puzzles.
*/
Easy::Easy(int A): Comp(),
	Puzzle()
{
	int Comp[][9] = { {3, 7, 6, 1, 4, 2, 9, 5, 8},
	{5, 8, 4, 6, 7, 9, 2, 1, 3},
	{9, 1, 2, 8, 3, 5, 4, 7, 6},
	{6, 9, 1, 2, 5, 4, 3, 8, 7},
	{8, 4, 5, 3, 6, 7, 1, 9, 2},
	{2, 3, 7, 9, 1, 8, 5, 6, 4},
	{4, 6, 9, 5, 8, 3, 7, 2, 1},
	{7, 2, 8, 4, 9, 1, 6, 3, 5},
	{1, 5, 3, 7, 2, 6, 8, 4, 9} };


	Puzz Puzzle[][9] = { {{0, false}, {0, false}, {0, false}, {0, false}, {4, true},  {0, false}, {9, true},  {0, false}, {0, false}},
	{{0,  false},  {8,  true},   {0,  false},  {6,  true},   {7,  true},   {0,  false},  {0,  false},  {0,  false},  {0,  false}},
	{{9,  true},   {0,  false},  {2,  true},   {8,  true},   {0,  false},  {0,  false},  {4,  true},   {0,  false},  {0,  false}},
	{{0,  false},  {9,  true},   {1,  true},   {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false}},
	{{0,  false},  {4,  true},   {0,  false},  {3,  true},   {6,  true},   {0,  false},  {0,  false},  {0,  false},  {2,  true }},
	{{0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {5,  true},   {0,  false},  {4,  true }},
	{{0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {7,  true},   {0,  false},  {1,  true }},
	{{0,  false},  {2,  true},   {8,  true},   {0,  false},  {0,  false},  {1,  true},   {0,  false},  {3,  true},   {0,  false}},
	{{1,  true},   {0,  false},  {3,  true},   {7,  true},   {0,  false},  {6,  true},   {8,  true},   {0,  false},  {0,  false}} };

	Sudoku EasyPuzzle(Puzzle);
}

/*
AddNum lets a user select the X and Y coordinates of where
they would like to enter a new number and, after checking to 
make sure it is not one of the hint numbers, will assign answer
to the correct element of the Puzzle array
*/
void Easy::AddNum(int X, int Y, int Answer)
{
	// Subtract one from both X and Y to look at the correct subscript.
	X-= 1;
	Y-= 1;
	if (Puzzle[X][Y].IsClue == true) 
	{
			cout << "Cannot change a puzzle clue. Please try again." << endl;
			return;
	}
	else
	{
		Puzzle[X][Y].Ans = Answer;
		ShowBoardAns(Puzzle);
	}
}

bool Easy::Solve()
{
	bool Solved = IsCorrect(Comp, Puzzle);
	return Solved;
}

void Easy::ShowPuzz()
{
	ShowBoard(Puzzle);	// Sends the puzzle to the Sudoku class, which will then display it
}