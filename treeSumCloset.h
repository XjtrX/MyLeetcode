#ifndef TREESUMCLOSET_H
#define TREESUMCLOSET_H

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <algorithm>

namespace treeSumCloset{
	using namespace std;
	/*
	Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
	 Return the sum of the three integers. You may assume that each input would have exactly one solution.
	
	For example, given array S = {-1 2 1 -4}, and target = 1.

    	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
	*/
	class Solution {
	public:
   		int threeSumClosest(vector<int> &num, int target) {
        			if(num.size()<3) return 0;
        			if(num.size() == 3) return(num[0] + num[1] + num[2]);
        			
        			sort(num.begin(), num.end());

        			int sumtem = 0;
        			int mind = 0x7FFFFFFF;
        			for (int i = 0; i < num.size() - 2; ++i)
        			{
        				int left = i + 1;
        				int right = num.size() - 1;
        				while(left < right)
        				{
        					int sum = num[i] + num[left] + num[right];
        					int dis = abs(sum - target);
        					if (mind > dis)
        					{
        						sumtem = sum;
        						mind = dis;
        						if(dis == 0) return target;
        					}
        					if (sum > target) right--;
        					else left++;
        				}
        			}
        			return sumtem;
    		}
    		void test(){
    			std::vector<int > v ;
    			v.push_back(120);v.push_back(40);v.push_back(10);v.push_back(140);v.push_back(-110);v.push_back(123);v.push_back(-10);
    			v.push_back(-5);v.push_back(-3);v.push_back(-1);v.push_back(120);v.push_back(111);v.push_back(12);v.push_back(1);

    			int target = 100;
    			for (std::vector<int >::iterator i = v.begin(); i != v.end(); ++i)
    			{
    				cout<<*i<<", ";
    			}
    			cout<<endl;
    			cout<<"The target is "<<target <<endl;
    			cout<< threeSumClosest(v, target)<<endl;
    		}
	};
}
#endif