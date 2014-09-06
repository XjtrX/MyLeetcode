/*
author: jtr@BNU
date: 14.9.6
problem:
Surrounded Regions Total Accepted: 12826 Total Submissions: 90644 My Submissions
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include "myIncs.h"

void printB(vector<vector<char> > &board)
{
	cout<<"---------------"<<endl;
	for (std::vector<vector<char> >::iterator itr = board.begin(); itr != board.end(); ++itr)
	{
		for (std::vector<char>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i;
		}
		cout<<endl;
	}
	cout<<"---------------"<<endl;
}
void solve(vector<vector<char> > &board)
{
	int row = board.size();
	if(row == 0) return;
	int len = board[0].size();
	if(len == 0) return;
	queue<pair<int, int> > Q;

	for (int i = 0; i < len; ++i)
	{
		if(board[0][i] == 'O')
		{
			board[0][i] = 'S';
			Q.push(make_pair(0,i));
		}
		if(board[row - 1][i] == 'O')
		{
			board[row - 1][i] = 'S';
			Q.push(make_pair(row - 1, i));
		}
	}
	for (int i = 0; i < row; ++i)
	{
		if(board[i][0] == 'O')
		{
			board[i][0] = 'S';
			Q.push(make_pair(i,0));
		}
		if(board[i][len - 1] == 'O')
		{
			board[i][len - 1] = 'S';
			Q.push(make_pair(i, len - 1));
		}
	}

	while(!Q.empty())
	{

		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		if(x > 0 && board[x - 1][y] == 'O')
		{
			Q.push({x-1,y});
			board[x-1][y] = 'S';
			// printB(board);
		}
		if(x < row - 1 && board[x + 1][y] == 'O') 
		{
			Q.push({x+1,y});
			board[x + 1][y] = 'S';
			// printB(board);
		}
		if(y > 0 && board[x][y - 1] == 'O')
		{
			Q.push({x,y-1});
			board[x][y-1] = 'S';
			// printB(board);
		}
		if(y < len - 1 && board[x][y + 1] == 'O')
		{
			Q.push({x,y+1});
			board[x][y+1] = 'S';
			// printB(board);
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if(board[i][j] == 'X') continue;
			if(board[i][j] == 'O') board[i][j] = 'X';
			if(board[i][j] == 'S') board[i][j] = 'O';
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<char> > board = {
		{'X','O','X','O','X','O','O','O','X','O',},
		{'X','O','O','X','X','X','O','O','O','X',},
		{'O','O','O','O','O','O','O','O','X','X',},
		{'O','O','O','O','O','O','X','O','O','X',},
		{'O','O','X','X','O','X','X','O','O','O',},
		{'X','O','O','X','X','X','O','X','X','O',},
		{'X','O','X','O','O','X','X','O','X','O',},
		{'X','X','O','X','X','O','X','O','O','X',},
		{'O','O','O','O','X','O','X','O','X','O',},
		{'X','X','O','X','X','X','X','O','O','O',},
	};
	for (std::vector<vector<char> >::iterator itr = board.begin(); itr != board.end(); ++itr)
	{
		for (std::vector<char>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i;
		}
		cout<<endl;
	}

	cout<<"---------------"<<endl;
	solve(board);
	for (std::vector<vector<char> >::iterator itr = board.begin(); itr != board.end(); ++itr)
	{
		for (std::vector<char>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i;
		}
		cout<<endl;
	}

	return 0;
}