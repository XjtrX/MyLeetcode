/*
author: jtr@BNU
date: 14.9.1
problem:
https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
Largest Rectangle in Histogram Total Accepted: 14777 Total Submissions: 69918 My Submissions
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

// int largestRectangleArea(vector<int> & height)
// {
// 	if (height.size() < 1)
// 	{
// 		return 0;
// 	}
// 	if (height.size() == 1) return height[0];

// 	int res = height[0];
// 	int len = height.size();

// 	int lowest = height[0];
// 	int curLow = height[0];

// 	vector<int> uping;
// 	uping.push_back(height[0]);
// 	int upCur = 0;
// 	int curMax = height[0];

// 	bool upflag = true;
// 	for (int i = 1; i < len; ++i)
// 	{
// 		uping.push_back(height[i]);
// 		if (height[i] >= height[i - 1] )//uping
// 		{
// 			if(!upflag)
// 			{
// 				uping.clear();
// 				uping.push_back(height[i]);
// 				upCur = 0;
// 				curMax = height[i];
// 				upflag = true;
// 			}
// 			for (std::vector<int>::iterator itr = uping.begin() + upCur; itr != uping.end(); ++itr)
// 			{
// 				if ((*itr) * (uping.size() - (itr - uping.begin())) >= curMax)
// 				{
// 					curMax = (*itr) * (uping.size() - (itr - uping.begin()));
// 					upCur = itr - uping.begin();
// 				}
// 			}
// 			if (curMax > res)
// 			{
// 				res = curMax;
// 				// cout<<res<<", "<<upCur<<endl;
// 			}
// 			if (lowest * (i + 1) > res)
// 			{
// 				res = lowest * (i + 1);
// 			}
// 		}
// 		else
// 		{
// 			upflag = false;
// 			if (height[i] >= curLow)
// 			{
// 				for (std::vector<int>::iterator itr = uping.begin(); (*itr <= height[i]) && itr != uping.end(); ++itr)
// 				{
// 					if ((*itr) * height.size() > curMax)
// 					{
// 						curMax = (*itr) * height.size();
// 					}
// 				}
// 			}
// 			else if (height[i] < curLow && height[i] > lowest && height[i] * uping.size() > curMax)
// 			{
// 				curMax = height[i] * uping.size();
// 			}
// 			else if (height[i] <= lowest)
// 			{
// 				if (lowest * i > res)
// 				{
// 					res = lowest * i;
// 				}
// 				lowest = height[i];
// 				if (lowest * (i + 1) > res)
// 				{
// 					res = lowest * (i + 1);
// 				}
// 			}

// 		}
// 	}
// 	return res;
// }

int largestRectangleArea(vector<int> & height)
{
	int res = 0;
	stack<int> S;
	if (height.size() == 1)
	{
		return height[0];
	}
	height.push_back(0);
	for (std::vector<int>::iterator itr = height.begin(); itr != height.end(); ++itr)
	{
		if (S.empty() || *itr > height[S.top()])
		{
			S.push(itr - height.begin());
		}
		else
		{
			int tem = S.top();
			S.pop();
			int mm = height[tem] * (S.empty() ? (itr - height.begin()) : ((itr - height.begin()) - S.top() - 1));
			res = max(res, mm);
			--itr;
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{
	std::vector<int> height = {2,2,2,2,2,2,4};
		for (std::vector<int>::iterator itr = height.begin(); itr != height.end(); ++itr)
	{
		cout<<*itr<<", ";
	}
	cout<<endl;

	cout<<endl<<largestRectangleArea(height)<<endl;
	return 0;
}