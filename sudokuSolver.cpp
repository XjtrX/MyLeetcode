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

 ///time limite................................
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

void solveSudoku(vector<vector<char> >  & board)
{
	int lens = board.begin()->size();
	int rows = board.size();
	set<char> allchar = {'1','2','3','4','5','6','7','8','9'};
	if (lens != 9 || rows != 9) return;
	vector<set<char> > rset(9);//rows
	vector<set<char> > lset(9);//cols
	vector<set<char> > bset(9);//blocks
	int ndot = 0;
	set<pair<int, int> > setdot;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < lens; ++j)
		{
			char c = board[i][j];
			if (c != '.')
			{
				rset[i].insert(c);
				lset[j].insert(c);
				int tem = (i/3) * 3 + j/3;
				bset[tem].insert(c);
			}
			else
			{
				ndot++;
				setdot.insert(make_pair(i,j));
			}
		}
	}
	// map<pair<int,int>, set<char> > whi;
	// for (std::set<pair<int, int>>::iterator i = setdot.begin(); i != setdot.end(); ++i )
	// {
	// 	set<char> tem;
	// 	set<char> tem2;
	// 	int row = i->first;
	// 	int col = i->second;
	// 	int blo = (row/3) *3 + col/3;
	// 	set_union(rset[row].begin(), rset[row].end(), lset[col].begin(), lset[col].end(), inserter(tem, tem.begin()));
	// 	set_union(bset[blo].begin(), bset[blo].end(), tem.begin(), tem.end(), inserter(tem2, tem2.begin()));
	// 	whi[*i] = tem2;
	// }
	// cout<<whi.size()<<endl;

	while(setdot.size() > 0)
	{

		cout<<setdot.size()<<endl;
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



		for (std::set<pair<int, int>>::iterator i = setdot.begin(); i != setdot.end(); ++i )
		{
			set<char> tem;
			set<char> tem2;
			int row = i->first;
			int col = i->second;
			int blo = (row/3) *3 + col/3;
			set_union(rset[row].begin(), rset[row].end(), lset[col].begin(), lset[col].end(), inserter(tem, tem.begin()));
			set_union(bset[blo].begin(), bset[blo].end(), tem.begin(), tem.end(), inserter(tem2, tem2.begin()));
			if (tem2.size() == 8)
			{
				set<char> t;
				// set_difference(allchar.begin(), allchar.end(), whi[*i].begin(),whi[*i].end(),inserter(t, t.begin()));
				set_difference(allchar.begin(), allchar.end(), tem2.begin(),tem2.end(),inserter(t, t.begin()));
				if (t.size() == 1)
				{
					char cc = *(t.begin());
					board[row][col] = cc;
					rset[row].insert(cc);
					lset[col].insert(cc);
					bset[blo].insert(cc);
					// for (int k= 0; k< 9; ++k)
					// {
					// 	whi[make_pair(k,col)].insert(cc);
					// 	whi[make_pair(row, k)].insert(cc);
					// }
					setdot.erase(i);
					break;
				}
			}
		}
	}

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
