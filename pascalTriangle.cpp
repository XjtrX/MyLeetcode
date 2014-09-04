/*
author: jtr@BNU
date: 14.9.4
problem:
Pascal's Triangle Total Accepted: 18059 Total Submissions: 56989 My Submissions 



Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
 Return 
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

#include "myIncs.h"

vector<vector<int> > generate(int numRows) 
{
	vector<vector<int> > res;
	if(numRows < 1) return res;
	res.push_back(vector<int>(1,1));
	for (int i = 1; i < numRows; ++i)
	{
		vector<int> tem;
		int len = res[i - 1].size();
		tem.push_back(1);
		for(int j = 0; j < len - 1; ++j)
			tem.push_back(res[i - 1][j] + res[i - 1][j + 1]);
		tem.push_back(1);
		res.push_back(tem);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 10;
	cout<<n<<endl<<endl;

	vector<vector<int> > res = generate(n);
	for (std::vector<std::vector<int> >::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		cout<<string(n-(itr - res.begin()),' ');
		for (std::vector<int>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i<<",";
		}
		cout<<endl;
	}
	return 0;
}