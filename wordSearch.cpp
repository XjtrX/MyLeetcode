/*
author: jtr@BNU
date: 14.9.1
problem:
Word Search Total Accepted: 13888 Total Submissions: 69845 My Submissions
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

void DFS(vector<vector<char> > & board,bool & res, string & path, string & word, 
	vector<vector<bool> >& flags, int row, int len)
{
	if (path == word || res)
	{
		res = true;
		return;
	}
	if (path.size() > word.size()) return;

	//up
	if (row - 1 >=0 && row - 1 < board.size())
	{
		if (word[path.size()] == board[row - 1][len] && flags[row - 1][len] == false)
		{
			path.push_back(word[path.size()]);
			flags[row - 1][len] = true;
			DFS(board, res, path, word, flags, row - 1, len);
			path.pop_back();
			flags[row - 1][len] = false;
			if (res)
			{
				return;
			}
		}
	}
	//down
	if (row >=0 && row + 1 < board.size())
	{
		if (word[path.size()] == board[row + 1][len] && flags[row + 1][len] == false)
		{
			path.push_back(word[path.size()]);
			flags[row + 1][len] = true;
			DFS(board, res, path, word, flags, row + 1, len);
			path.pop_back();
			flags[row + 1][len] = false;
			if (res)
			{
				return;
			}
		}
	}
	
	//left
	if (len - 1 >= 0 && len < board[row].size())
	{
		if (!flags[row][len - 1] && word[path.size()] == board[row][len - 1])
		{
			path.push_back(word[path.size()]);
			flags[row][len - 1] = true;
			DFS(board, res, path, word, flags, row, len - 1);
			path.pop_back();
			flags[row][len - 1] = false;
			if (res)
			{
				return;
			}
		}
	}
	//right
	if (len >= 0 && len + 1 < board[row].size())
	{
		if (!flags[row][len + 1] && word[path.size()] == board[row][len + 1])
		{
			path.push_back(word[path.size()]);
			flags[row][len + 1] = true;
			DFS(board, res, path, word, flags, row, len + 1);
			path.pop_back();
			flags[row][len + 1] = false;
			if (res)
			{
				return;
			}
		}
	}

}

bool exist(vector<vector<char> > & board, string word)
{
	vector<vector<bool> > flags;
	vector<pair<int,int> > FirstOfWord;
	for (std::vector<std::vector<char> >::iterator itr= board.begin(); itr!= board.end(); ++itr)
	{
		vector<bool> tem(itr->size(), false);
		flags.push_back(tem);
		for (std::vector<char>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			if (*i == *(word.begin()))
			{
				FirstOfWord.push_back(make_pair(itr - board.begin(), i - (itr->begin())));
			}
		}
	}

	bool res = false;
	string path;
	for (std::vector<pair<int,int> >::iterator itr = FirstOfWord.begin(); itr != FirstOfWord.end(); ++itr)
	{
		path.clear();
		path.push_back(board[itr->first][itr->second]);
		flags[itr->first][itr->second] = true;
		DFS(board, res, path, word, flags, itr->first, itr->second);
		if (res)
		{
			return res;
		}
		flags[itr->first][itr->second] = false;
	}

	return res;

}

int main(int argc, char const *argv[])
{
	vector<vector<char> > board = {
		{'a'}
	};


	for (std::vector<std::vector<char> >::iterator itr = board.begin(); itr != board.end(); ++itr)
	{
		for (std::vector<char>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i;
		}
		cout<<endl;
	}
	string word = "a";
	cout<<endl<<word<<" is "<<(exist(board, word) ? "exist." : "not exist.")<<endl;
	return 0;
}