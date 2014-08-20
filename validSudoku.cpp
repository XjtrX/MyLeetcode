/*
author: jtr@BNU
date: 14.8.20
problem:
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

|3 4 5 | 6 7 8 | . 1 . |
|. . . | . . . | . . . |
|9 8 . | 4 2 1 | 3 4 5 |
 ----------------------
|2 . 5 | 6 . 8 | 9 . . |
|. . . | . . . | . . . |
|7 9 . | 4 . 1 | 2 4 5 |
 ----------------------
|3 . 5 | 6 9 8 | . . 2 |
|. . . | . . . | . . . |
|. 6 7 | 4 . 1 | 8 4 . |
 ----------------------
A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

bool isValidSudoku(vector<vector<char> > & board)
{
	bool res = true;
	int rows = board.size();
	int cols = board.begin()->size();
	if (rows != 9 || cols != 9)
	{
		return false;
	}
	vector<map<char, int > > mpl(9);
	vector<map<char, int > > mpc(9);
	vector<map<char, int > > mpb(9);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			char c = board[i][j];
			if (c != '.')
			{
				mpl[i][c]++;
				mpc[j][c]++;
				int tem = (i/3) * 3 + j/3;
				mpb[tem][c]++;
				if (mpl[i][c] > 1 || mpc[j][c] > 1 || mpb[tem][c] > 1)
				{
					return false;
				}
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	// std::vector<std::vector<char> > board = {
	// 	{'3', '4', '5',  '6', '7', '8',  '.', '1', '.' },
	// 	{'.', '.', '.',  '.', '.', '.',  '.', '.', '.' },
	// 	{'9', '8', '.',  '.', '2', '.',  '3', '.', '5' },
	// 	{'2', '.', '8',  '.', '.', '.',  '9', '.', '.' },
	// 	{'.', '.', '.',  '.', '.', '.',  '.', '.', '.' },
	// 	{'7', '9', '.',  '4', '.', '3',  '2', '6', '7' },
	// 	{'.', '.', '6',  '.', '9', '.',  '.', '.', '2' },
	// 	{'.', '.', '.',  '.', '.', '.',  '.', '.', '.' },
	// 	{'.', '6', '7',  '.', '.', '1',  '8', '4', '.' }
	// };
	vector<vector<char> > board = {
			{'.','.','4','.','.','.','6','3','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'5','.','.','.','.','.','.','9','.'},
			{'.','.','.','5','6','.','.','.','.'},
			{'4','.','3','.','.','.','.','.','1'},
			{'.','.','.','7','.','.','.','.','.'},
			{'.','.','.','5','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'}
		};

	cout<<endl<<" -------------------------"<<endl;
	for (std::vector<std::vector<char> >::iterator itr = board.begin(); itr != board.end(); ++itr)
	{
		cout<<"|";
		for (std::vector<char>::iterator i = itr->begin(); i != itr->end(); ++i )
		{
			cout<< *i << " |";
		}
		
		if ((itr - board.begin()) % 3 == 2)
		{
			cout<<endl<<" -------------------------"<<endl;
		}
		else
			cout<<endl;
		
	}


	cout<<(isValidSudoku(board) ? "valid." : "not valid.")<<endl;
	return 0;
}