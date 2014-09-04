/*
author: jtr@BNU
date: 14.9.4
problem:
Best Time to Buy and Sell Stock Total Accepted: 22052 Total Submissions: 71056 My Submissions 

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

*/
#include "myIncs.h"

int maxProfit(vector<int> &prices) 
{
	int res = 0;
	if(prices.size() < 2) return 0;
	int len = prices.size();
	int cur = 1;
	int prelow = 0;
	while(cur < len)
	{
		while(cur< len && prices[cur - 1] > prices[cur]) 
		{
			prelow = cur;
			cur++;
		}
		while(cur < len && prices[prelow] <= prices[cur])
		{
			res = max(res, prices[cur] - prices[prelow]);
			cur++;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> prices = {6,1,3,2,4,7};

	for (std::vector<int>::iterator i = prices.begin(); i != prices.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;
	cout<<maxProfit(prices)<<endl;
	return 0;
}