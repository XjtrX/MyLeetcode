
#ifndef FOURSUM_H
#define FOURSUM_H

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
   */
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
namespace FourSum{
    using namespace std;
    class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > res;
            res.clear();
            if (num.size() < 4)
            {
                r eturn res;
            }
            sort(num.begin(), num.end());

        }
        void test(){
            vector<int> test = {1,3,6,7,1,2,33,68,32,12,9,0,0,4,2,-2,-6,-23};
            int target = 16;
            vector<vector<int> > res = fourSum(test, target);
            for (vector<vector<int> >  i = res.begin(); i !=  res.end(); ++i)
            {
                /* code */
            }
        }
    };
}

#endif
