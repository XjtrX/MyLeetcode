/*
author: jtr@BNU
date: 14.8.25
problem:
Climbing Stairs Total Accepted: 21042 Total Submissions: 62215 My Submissions
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int climbStairs(int n)
{
	int res = 0;
	int first = 1, second = 2;
	for (int i = 0; i < n; ++i)
	{
		res = i>1 ? second + first : ((i == 1) ? second : first);
		first = i>1 ? second : first;
		second = i>1 ? res : second;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 4;
	cout<<n<<endl<<climbStairs(n)<<endl;
	return 0;
}