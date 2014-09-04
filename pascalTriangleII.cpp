/*
author: jtr@BNU
date: 14.9.4
problem:
Pascal's Triangle II Total Accepted: 16041 Total Submissions: 52661 My Submissions 


Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
 Return [1,3,3,1]. 

Note:
 Could you optimize your algorithm to use only O(k) extra space? 

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

vector<int> getRow(int rowIndex) 
{
	int n = rowIndex + 1;
	vector<int> res(n,0);
	if(n < 1) return res;
	res[0] = 1;
	int tem = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			int t = res[j];
			res[j] = res[j] + tem;
			tem = t;
		}
		res[i] = 1;
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
		// cout<<string(n-(itr - res.begin()),' ');
		for (std::vector<int>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i<<",";
		}
		cout<<endl;
	}


	cout<<"------------"<<endl;
	int rowIndex = 2;
	vector<int> ress = getRow(rowIndex);
	for (int i = 0; i < rowIndex + 1; ++i)
	{
		cout<<ress[i]<<",";
	}
	cout<<endl;
	return 0;
}