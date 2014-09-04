/*
author: jtr@BNU
date: 14.9.4
problem:
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

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
		while(cur < len && prices[cur - 1] <= prices[cur])
		{
			cur++;
		}
		res += prices[cur - 1] - prices[prelow];
		prelow = cur;
		cur++;
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