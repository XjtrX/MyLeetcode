#ifndef TWOSUM_H
#define TWOSUM_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <set>
//#include <algrothm>


namespace twoSum{
	using namespace std;
	/*
	author: jtr@BNU
site:https://oj.leetcode.com/problems/two-sum/
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
	*/

class Solution {

	public:
    		vector<int> twoSum(vector<int> &numbers, int target) {
    			std::map<int, size_t> pos;
    			std::vector<int> res;
    			res.clear();

    			if (numbers.size() < 2)
    			{
    				return res;
    			}

    			for (int i = 0; i < numbers.size();  ++i)
    			{
    				if (pos[target - numbers[i]] != 0)
    				{
    					res.push_back(pos[target - numbers[i]]);
    					res.push_back(i+1);
    					return res;
    				}
    				pos[numbers[i]] = i + 1;
    			}
    			return res;
    		}
    		void test()
    		{
    			vector<int > v ;
    			v.push_back(6);
    			v.push_back(7);
    			v.push_back(11);
    			v.push_back(5);
    			int target = 12;
    			std::vector<int > res;
    			res = twoSum(v, target);
    			for (int i = 0; i < res.size(); ++i)
    			{
    				cout<<res[i]<<", ";
    			}
    			cout<<endl;
    		}
    	};
}
#endif