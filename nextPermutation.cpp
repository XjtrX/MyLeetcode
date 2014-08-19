/*
author: jtr@BNU
date: 14.8.19
problem:
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> & num)
{
	if (num.size()< 2)
	{
		return;
	}
	int len = num.size();
	int pre = num[len - 1];
	for (int i = len - 1; i > 0; --i)
	{
		if (pre > num[i - 1])
		{
			sort(num.begin() + i, num.end());
			int k = i;
			while(k < len)
			{
				if (num[k] > num[i - 1])
				{
					pre = num[i - 1];
					num[i - 1] = num[k];
					num[k]  = pre;
					return;
				}
				k++;
			}
		}
		pre = num[i - 1];
	}
	sort(num.begin(), num.end());
}

int main(int argc, char const *argv[])
{
	vector<int> num = {1,2,3};

	for (std::vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
	{
		cout<<*itr<<", ";
	}
	cout<<endl;

	nextPermutation(num);
	for (std::vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
	{
		cout<<*itr<<", ";
	}
	cout<<endl;
	return 0;
}