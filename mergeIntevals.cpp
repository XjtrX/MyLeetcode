/*
author: jtr@BNU
date: 14.8.22
problem:
Merge Intervals Total Accepted: 13832 Total Submissions: 66772 My Submissions
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
vector<Interval> merge(vector<Interval> & intervals)
{
	vector<Interval> res;
	if (intervals.size()<2)
	{
		return intervals;
	}
	sort(intervals.begin(), intervals.end(),myobj);
	bool first = true;
	Interval tem = Interval();
	for (std::vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); ++itr)
	{
		if (first)
		{
			tem.start = itr->start;
			tem.end = itr->end;
			first = false;
		}
		else
		{
			if (tem.end >= itr->start )
			{
				if (tem.end < itr->end)
					tem.end = itr->end;
			}
			else
			{
				res.push_back(tem);
				tem.start = itr->start;
				tem.end = itr->end;

			}
			if (itr+1 == intervals.end())
			{
				res.push_back(tem);
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<Interval> intervals = {
		Interval(1,4),
		Interval(1,4),
	};

	for (std::vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); ++itr)
	{
		cout<<"("<<itr->start<<","<<itr->end<<"),";
	}
	cout<<endl;

	sort(intervals.begin(), intervals.end(),comp);

	for (std::vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); ++itr)
	{
		cout<<"("<<itr->start<<","<<itr->end<<"),";
	}
	cout<<endl;
	

	std::vector<Interval> res = merge(intervals);
	for (std::vector<Interval>::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		cout<<"("<<itr->start<<","<<itr->end<<"),";
	}
	cout<<endl;
	return 0;
}