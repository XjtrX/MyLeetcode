/*
author: jtr@BNU
date: 14.8.22
problem:
Insert Interval Total Accepted: 13363 Total Submissions: 65151 My Submissions
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s, int e):start(s), end(e){}
};

bool comp(Interval a, Interval b){return (a.start < b.start);}
struct mycomp
{
	bool operator()(Interval a, Interval b){return(a.start < b.start);}
}myobj;

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval> res;
	if (intervals.size()<1)
	{
		res.push_back(newInterval);
		return res;
	}
	sort(intervals.begin(), intervals.end(), myobj);
	bool flag = false;
	for (std::vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); ++itr)
	{
		if (!flag && itr->end >= newInterval.start)
		{
			flag = true;
			Interval tem = *itr;
			if (tem.start > newInterval.end)
			{
				res.push_back(newInterval);
				res.push_back(tem);
				continue;
			}
			if (tem.start > newInterval.start)
			{
				tem.start = newInterval.start;
			}
			if (newInterval.end >= tem.end)
			{
				
				tem.end = newInterval.end;
				while(itr != intervals.end() && tem.end >= itr->start)
				{
					if (tem.end < itr->end)
					{
						tem.end = itr->end;
					}
					++itr;
				}
				res.push_back(tem);
				--itr;
			}
			else
				res.push_back(tem);
		}
		else
			res.push_back(*itr);
	}
	if (!flag)
	{
		res.push_back(newInterval);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<Interval> intervals = {
		
		Interval(1,5),Interval(6,11),Interval(31,45)
	};

	for (std::vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); ++itr)
	{
		cout<<"("<<itr->start<<","<<itr->end<<"),";
	}
	cout<<endl;
	Interval newInterval(0,0);
	std::vector<Interval> res = insert(intervals,newInterval);
	for (std::vector<Interval>::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		cout<<"("<<itr->start<<","<<itr->end<<"),";
	}
	cout<<endl;
	return 0;
}