#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

/*
author: jtr@BNU
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

vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int> > res;
	res.clear();
	if (num.size() < 4)
	{
		return res;
	}
	sort(num.begin(), num.end());
	int count = num.size();
	multimap<int, pair<int, int> > sub;
	for (int i = 0; i < count - 1; ++i)
	{
		for (int j = i + 1; j < count ; ++j)
		{
			sub.insert(make_pair(num[i] + num[j], make_pair(i,j)) );
			if ( j+1<count -1 && num[j] == num[j+1])
			{
				while(num[j] == num[j+1] ) ++j;
				--j;
			}
		}
		//just save the first and last one same num
		if (i<count && num[i] == num[i+1])
		{
			while(num[i] == num[i+1]) ++i;
			--i;
		}
	}

	for(multimap<int, pair<int, int> >::iterator itr = sub.begin(); itr != sub.end(); ++itr)
	{
		int rest = target - itr->first;
		//cout<<itr->first<<endl;
		pair<multimap<int, pair<int, int> >::iterator, multimap<int, pair<int, int> >::iterator > range = sub.equal_range(rest);
		int prea ,preb, prec, pred;
		for (multimap<int, pair<int, int> >::iterator i = range.first; i != range.second; ++i)
		{

			int a = (itr->second).first;
			int b = (itr->second).second;
			int c = (i->second).first;
			int d = (i->second).second;
			//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			if (b< c)
			{
				res.push_back({num[a], num[b], num[c], num[d]});
			}

		}

	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

int main()
{
	vector<int > v = {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};//{-12,32,4,541,34,4,3,3,3,3,3,45,7,8,89,-123,-23,-43,-54,6,-6,-88,-86,3,423,5,2,324,2,42,4,32,4,3,2,432,4,3,-124,-65,-634,-76,-543,-4};
	for(auto  item = v.begin(); item != v.end() ; ++item)
		cout<<*item<<", ";
	cout<<endl;

	int target = 0;
	cout<<target<<endl;
	cout<<"-------------------------------------------"<<endl;
	std::vector<std::vector<int> > res = fourSum(v, target);

	for(auto ite = res.begin(); ite != res.end(); ++ite)
	{
		for(auto  tt = ite->begin(); tt != ite->end(); ++tt)
		{
			cout<<*tt<<", ";
		}
		cout<<endl;
	}
}