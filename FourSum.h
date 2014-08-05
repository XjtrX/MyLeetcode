
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
                return res;
            }
            sort(num.begin(), num.end());

            map<int, vector<pair<int,int> >  >  lastTwo;
            int count = num.size();

            bool flag = false;
            for (int i = 0; i < count - 1; ++i)
            {
            	for (int j = 0; j < count - 2; ++j)
            	{
            		lastTwo[num[i] + num[j]].push_back(pair<int,int>(i, j));
            		if (num[j] == num[j+1]) 
            		{
            		while(num[j] == num[j+1]) ++j;
            		--j;
            		}

            	}
            	if (num[i] == num[i+1])
            	{
            		while(num[i] == num[i + 1] ) ++i;
            		--i;
            	}
            }
            
            for (int i = 0; i < count ; ++i)
            {
            	for (int j = i + 1; j < count ; ++j)
            	{
            		int sum = num[i] + num[j];
            		int rest = target - sum;
            		if(lastTwo.find(rest) == lastTwo.end()) continue;
            		vector<pair<int,int> > & tem = lastTwo[rest];
            		for (int k = 0; k < tem.size() ; ++k )
            		{
            			if (i <= tem[k].second) continue;
            			res.push_back({num[tem[k].first],num[tem[k].second], num[i], num[j]});
            		}

            		if (num[j] == num[j+1]) 
            		{
            		while(num[j] == num[j+1]) ++j;
            		--j;
            		}
            	}
            	if (num[i] == num[i+1])
            	{
            		while(num[i] == num[i + 1] && i < j) ++i;
            		--i;
            	}
            }
           // sort(res.begin(), res.end());
            //res.erase(unique(res.begin(),res.end(), res.end()));
            return res;
        }

        //------------------
        void test(){
            vector<int> test = {1,3,6,7,1,2,33,68,32,12,9,0,0,4,2,-2,-6,-23};
            int n = 20;
            while(n--) test.push_back(rand()%50);
            n = 20;
            while(n--) test.push_back(0 - rand()%50);
            for (int i = 0; i < test.size(); ++i)
            {
            	cout<<test[i]<<", ";
            }
            cout<<endl;
            int target = 34;
            cout<<target<<endl<<"-----"<<endl;
            
            vector<vector<int> > res = fourSum(test, target);
            for (vector<vector<int> >::iterator  i = res.begin(); i !=  res.end(); ++i)
            {
                for(vector<int>::iterator j = i->begin(); j != i->end(); ++j)
                	cout<<*j<<",";
                cout<<endl;
            }
        }
    };
}

#endif
