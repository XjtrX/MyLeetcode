/*
author: jtr@BNU
date: 14.8.23
problem:
Permutation Sequence Total Accepted: 11616 Total Submissions: 52532 My Submissions
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


string getPermutation(int n, int k)
{
	string res = "";
	vector<int> P( n+1,1);
	for (int i = 1; i <= n; ++i)
	{
		P[i] = i * P[i-1];
	}
	vector<int> data(n);
	for (int i = 0; i < n; ++i)
	{
		data[i] = i + 1;
	}
	if (k > P[n] || k < 1) return res;
	int tem = 0;
	k--;
	while(tem < n)
	{
		res.push_back('0' + data[k/P[n - tem - 1]]);
		data.erase(find(data.begin(), data.end(), data[k/P[n - tem - 1]]));
		k = k%P[n - tem - 1];
		tem++;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 9;
	int k = 6;
	cout<<n<<", "<<k<<endl;

	cout<<getPermutation(n,k)<<endl;

	return 0;
}