/*
author: jtr@BNU
date: 14.8.12
problem:
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
//this is a solve with force search. TLM!!!
int maxArea(vector<int> &height) {
	int area = 0;
	for(int i = 0; i<height.size() - 1; ++i)
	{
		for (int j = i + 1; j < height.size(); ++j )
		{
			int tem = 0;
			tem = (j - i) * min(height[i], height[j]);
			if (area < tem)
			{
				area = tem;
			}
		}
	}
	return area;
}
*/

int maxArea(vector<int> &height)
{
	int area = 0;
	int start = 0;
	int end = height.size() - 1;
	while(start<end)
	{
		area = max(area, min(height[start], height[end]) * (end - start));
		if (height[start] < height[end])
		{
			start++;
		}
		else
			end--;
	}
	return area;
}

int main()
{
	vector<int> h = {1,32,3,21,3,21,32,14,12,42,13,21,3,5,1,5,312,63,2,6,23,64};

	for (std::vector<int>::iterator i = h.begin(); i != h.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;

	cout<<maxArea(h)<<endl;
	return 0;
}