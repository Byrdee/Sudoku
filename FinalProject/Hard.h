// This is the class for Hard difficulty puzzles

#include <iostream>
#include "Sudoku.h"

using namespace std;


class Hard : protected Sudoku
{
private:
	int Comp[9][9];		// Comp is the completed puzzle
	Puzz Puzzle[9][9];	// Puzzle is what the user sees
	Sudoku HardPuzzle;

public:
	Hard();
	void AddNum(int, int, int);	// Add a number to solve the puzzle
	void Hint(int, int);		// The user can enter X and Y to get an answer
	bool Solve();
};

Hard::Hard()
{
	int Comp[][9] = { {2, 4, 7, 1, 5, 8, 3, 6, 9}, 
	{5, 9, 1, 6, 2, 3, 4, 7, 8}, 
	{3, 6, 8, 7, 9, 4, 5, 1, 2}, 
	{7, 1, 4, 2, 6, 5, 9, 8, 3}, 
	{6, 3, 2, 8, 1, 9, 7, 4, 5}, 
	{8, 5, 9, 3, 4, 7, 1, 2, 6}, 
	{9, 7, 5, 4, 8, 6, 2, 3, 1}, 
	{1, 8, 3, 5, 7, 2, 6, 9, 4} };

	Puzz Puzzle[][9] = {{ {2, true},  {4, true},  {0, false},  {0, false},  {0, false},  {8, true},   {0, false},  {0, false},  {0, false} },
	{ {0, false},  {0, false},  {0, false},  {0, false},  {0, false},  {0, false},  {4, true},  {7, true},   {0, false} },
	{ {0, false},  {0, false},  {8, true},   {0, false},  {9, true},   {0, false},  {0, false},  {0, false},  {0, false} },
	{ {7, true},   {0, false},  {0, false},  {0, false},  {6, true},   {5, true},   {9, true},   {8, true},   {0, false} },
	{ {6, true},   {0, false},  {2, true},   {0, false},  {0, false},  {0, false},  {0, false},  {0, false},  {0, false} },
	{ {0, false},  {0, false},  {0, false},  {0, false},  {4, true},   {0, false},  {1, true},   {0, false},  {0, false} },
	{ {9, true},   {7, true},   {0, false},  {0, false},  {0, false},  {6, true},   {0, false},  {3, true},   {0, false} },
	{ {0, false},  {0, false},  {0, false},  {9, true},   {0, false},  {0, false},  {0, false},  {0, false},  {0, false} },
	{ {1, true},   {0, false},  {0, false},  {0, false},  {0, false},  {2, true},   {0, false},  {0, false},  {0, false} }};

	//Sudoku HardPuzzle(Puzzle);
} 

/*
AddNum lets a user select the X and Y coordinates of where
they would like to enter a new number and, after checking to 
make sure it is not one of the hint numbers, will enter it

I had to manually enter what the hint numbers were. They are the
numbers that were already given on the partially filled out puzzle.

This way, the user can change an answer once submitted, rather than if
the code was that if the x and y answer was != 0.
*/
void Hard::AddNum(int X, int Y, int Answer)
{
	// Subtract one from both X and Y to look at the correct subscript.
	X-= 1;
	Y-= 1;
	if (Puzzle[X][Y].IsClue == true)
	{
		cout << "Cannot change a puzzle clue. Please try again." << endl;
	}
	else
	{
		Puzzle[X][Y].Ans = Answer;
		HardPuzzle.ShowBoardAns(Puzzle);
	}
}

void Hard::Hint(int X, int Y)
{

	X -= 1;
	Y -= 1;
	if (Puzzle[X][Y].Ans == 0)
	{
		Puzzle[X][Y].Ans = Comp[X][Y];
	}
	else
	{
		cout << "Invalid coordinates. Try again." << endl;
		return;
	}
	HardPuzzle.ShowBoardAns(Puzzle);
}

bool Hard::Solve()
{
	bool Solved = HardPuzzle.IsCorrect(Comp, Puzzle);
	return Solved;
}