/*
author: jtr@BNU
date: 14.9.4
problem:
Triangle Total Accepted: 17062 Total Submissions: 63731 My Submissions 



Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]



The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 

Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

*/

 #include "myIncs.h"

 int minimumTotal(vector<vector<int> > &triangle)
 {
 	int res = 0x7fffffff;
 	int len = triangle.size();
 	vector<int> path(len + 1, 0);
 	if (triangle.size() == 0) return 0;
 	if (triangle.size() == 1) return triangle[0][0];
 	path[0] = triangle[0][0];
 	int tem = path[0];
 	for (int i = 1; i < len; ++i)
 	{
 		tem = path[0];
 		path[0] += triangle[i][0];
 		if(i == len - 1 && res > path[0]) res = path[0];
 		int j = 1;
 		for(; j < i ; ++j)
 		{
 			int t = path[j];
 			path[j] = (tem + triangle[i][j] > path[j] + triangle[i][j]) ? path[j] + triangle[i][j] : tem + triangle[i][j];
 			tem = t;
 			if(i == len - 1 && res > path[j]) res = path[j];
 		}
 		path[j] = tem + triangle[i][j];
 		if(i == len - 1 && res > path[j]) res = path[j];
 	}
	return res;

 }
 int main(int argc, char const *argv[])
 {
 	vector<vector<int> > triangle = {
 		{2,},
 		{3,4},
 		{6,5,7},
 		{4,1,8,3}
 	};
 	for (std::vector<vector<int> >::iterator itr = triangle.begin(); itr != triangle.end(); ++itr)
 	{
 		for (std::vector<int>::iterator i = itr->begin(); i != itr->end(); ++i)
 		{
 			cout<<*i<<", ";
 		}
 		cout<<endl;
 	}
 	cout<<"--------"<<endl;

 	cout<<endl<<minimumTotal(triangle)<<endl;
 	return 0;
 }