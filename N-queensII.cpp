/*
author: jtr@BNU
date: 14.8.22
problem:
N-Queens II Total Accepted: 11524 Total Submissions: 34878 My Submissions
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

// private:

bool isAnti(vector<string> & path)
{
	if (path.size() < 2)
	{
		return false;
	}
	int lastQ = 0, len = path.size() - 1;
	while(lastQ <path[len].size() && path[path.size() - 1][lastQ] != 'Q') lastQ++;
	for (int i = 0; i < len ; ++i)
	{
		int cur = 0;
		while(cur < path[i].size() && path[i][cur] != 'Q') cur++;
		// cout<<"i, cur, last,lastQ : "<<i<<", "<< cur<< ", " << len <<","<<lastQ<<endl;
		if(abs(cur - lastQ)- abs(i - len) == 0 ) 
			return true;
	}
	return false;
}
void DFS(vector<vector<string> > &res, vector<string> & path, vector<int> & num, vector<string> &data)
{
	if (path.size() == num.size())
	{
		res.push_back(path);
		return;
	}
	for (std::vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
	{
		if (find(path.begin(), path.end(),data[*itr]) == path.end())
		{
			path.push_back(data[*itr]);
			if (!isAnti(path))
			{
				DFS(res, path, num, data);
			}
			path.pop_back();
		}
	}
}

vector<string> generateNQueensStart(int n)
{
	vector<string> res;
	for (int i = 0; i < n; ++i)
	{
		string tem(n,'.');
		tem[i] = 'Q';
		res.push_back(tem);
	}
	return res;
}
// public:
int totalNQueens(int n)
{
	std::vector<int> num(n,0);
	for (int i = 0; i < n; ++i)
	{
		num[i] = i;
	}
	vector<string> startN = generateNQueensStart(n);
	vector<vector<string> > res;
	vector<string> path;
	DFS(res, path, num, startN);

	return res.size();
}

int main(int argc, char const *argv[])
{
	int n = 5;
	cout<<n<<endl;
	cout<<endl<<"--------------------"<<endl;
	// std::vector<std::vector<string> > res = solveNQueens(n);
	cout<<totalNQueens(n)<<endl;
	// for (std::vector<std::vector<string> >::iterator itr = res.begin(); itr != res.end(); ++itr)
	// {
	// 	for (std::vector<string>::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
	// 	{
	// 		cout<<*i<<endl;
	// 	}
	// 	cout<<"---------------------"<<endl;
	// }
	return 0;
}