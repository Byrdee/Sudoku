// This is the class for medium difficulty puzzles

#include <iostream>
#include "Sudoku.h"

using namespace std;

class Medium : protected Sudoku
{
private:
	int Comp[9][9];		// Comp is the completed puzzle
	Puzz Puzzle[9][9];	// Puzzle is what the user sees
	Sudoku MediumPuzzle;

public:
	Medium();	// Constructor
	void AddNum(int, int, int);	// Add a number to solve the puzzle
	bool Solve();

};

Medium::Medium()
{
	int Comp[][9] = { {5, 1, 7, 2, 4, 8, 6, 9, 3},
	{6, 2, 9, 7, 5, 3, 1, 8, 4}, 
	{8, 3, 4, 9, 1, 6, 5, 2, 7}, 
	{4, 5, 6, 3, 9, 2, 7, 1, 8}, 
	{7, 8, 3, 4, 6, 1, 9, 5, 2}, 
	{1, 9, 2, 8, 7, 5, 3, 4, 6}, 
	{3, 4, 5, 1, 2, 7, 8, 6, 9}, 
	{9, 6, 8, 5, 3, 4, 2, 7, 1}, 
	{2, 7, 1, 6, 8, 9, 4, 3, 5} };

	Puzz Puzzle[][9] = 	{ {{0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false}},
		{{0,  false},  {0,  false},  {9,  true},   {0,  false},  {0,  false},  {3,  true},   {1,  true},   {0,  false},  {0,  false}}, 
		{{0,  false},  {0,  false},  {4,  true},   {9,  true},   {0,  false},  {0,  false},  {5,  true},   {0,  false},  {7,  true }}, 
		{{4,  true},   {0,  false},  {0,  false},  {0,  false},  {9,  true},   {0,  false},  {0,  false},  {0,  false},  {0,  false}}, 
		{{0,  false},  {0,  false},  {3,  true},   {0,  false},  {6,  true},   {1,  true},   {9,  true},   {0,  false},  {0,  false}}, 
		{{0,  false},  {0,  false},  {0,  false},  {0,  false},  {7,  true},   {0,  false},  {0,  false},  {4,  true},   {6,  true }}, 
		{{0,  false},  {0,  false},  {0,  false},  {1,  true},   {0,  false},  {0,  false},  {8,  true},   {0,  false},  {0,  false}},  
		{{0,  false},  {6,  true},   {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false}},  
		{{2,  true},   {7,  true},   {0,  false},  {0,  false},  {0,  false},  {0,  false},  {0,  false},  {3,  true},   {0,  false}} }; 

	Sudoku MediumPuzzle(Puzzle);
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
void Medium::AddNum(int X, int Y, int Answer)
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
		MediumPuzzle.ShowBoardAns(Puzzle);
	}
}

bool Medium::Solve()
{
	bool Solved = MediumPuzzle.IsCorrect(Comp, Puzzle);
	return Solved;
}