/*
author: jtr@BNU
date: 14.8.20
problem:
Sudoku Solver Total Accepted: 10736 Total Submissions: 51539 My Submissions
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
 -------------------------
|5 |3 |. |. |7 |. |. |. |. |
|6 |. |. |1 |9 |5 |. |. |. |
|. |9 |8 |. |. |. |. |6 |. |
 -------------------------
|8 |. |. |. |6 |. |. |. |3 |
|4 |. |. |8 |. |3 |. |. |1 |
|7 |. |. |. |2 |. |. |. |6 |
 -------------------------
|. |6 |. |. |. |. |2 |8 |. |
|. |. |. |4 |1 |9 |. |. |5 |
|. |. |. |. |8 |. |. |7 |9 |
 -------------------------
A sudoku puzzle...
 -------------------------
|5 |3 |4 |6 |7 |8 |9 |1 |2 |
|6 |7 |2 |1 |9 |5 |3 |4 |8 |
|1 |9 |8 |3 |4 |2 |5 |6 |7 |
 -------------------------
|8 |5 |9 |7 |6 |1 |4 |2 |3 |
|4 |2 |6 |8 |5 |3 |7 |9 |1 |
|7 |1 |3 |9 |2 |4 |8 |5 |6 |
 -------------------------
|9 |6 |1 |5 |3 |7 |2 |8 |4 |
|2 |8 |7 |4 |1 |9 |6 |3 |5 |
|3 |4 |5 |2 |8 |6 |1 |7 |9 |
 -------------------------
*/
//-------------------c o p y   o t h e r s...........................
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

bool isValidSudoku(vector<vector<char> > & board, int x, int y)
{
	int i, j;
	for (i = 0; i < 9; i++) 
		if (i != x && board[i][y] == board[x][y])
			return false;
	for (j = 0; j < 9; j++) 
		if (j != y && board[x][j] == board[x][y])
			return false;
	for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
		for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
			if ((i != x || j != y) && board[i][j] == board[x][y])
				return false;
	return true;
}


bool solveSudoku(vector<vector<char> >  & board)
{
	int lens = board.begin()->size();
	int rows = board.size();
	if (lens != 9 || rows != 9) return false;

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
		if (board[i][j] == '.') {
			for (int k = 0; k < 9; ++k) {
				board[i][j] = '1' + k;
				if (isValidSudoku(board,i , j) && solveSudoku(board))
				return true;
				board[i][j] = '.';
			}
		return false;
		}
	}
	return true;
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
			{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
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


	cout<<"The answer."<<endl;
	solveSudoku(board);

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

	return 0;
}