/*
author: jtr@BNu
date: 14.8.22
peoblem:
Pow(x, n) Total Accepted: 19844 Total Submissions: 76616 My Submissions
Implement pow(x, n).
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <limits>
#include <cmath>

using namespace std;

double mypow(double x, int n)
{
	double res = 1.0;
	if (n == 0) return 1;
	if (n >= 0 && x > -1e-23 &&  x < 1e-23) return 0;
	if (n < 0 && x > -1e-23 &&  x < 1e-23) return std::numeric_limits<double>::max();
	double maxd =  numeric_limits<double>::max(), mind = numeric_limits<double>::min();


	bool negn = true; //n is + or -
	if (n < 0)
	{
		negn = false;
		n = -n;
	}

	bool sign = true;
	if (x < 0.0)
	{
		sign = n%	2?false:true;
		x = -x;
	}
	if (abs(x - 1) < 1e-23)
	{
		return sign?x:-x;
	}

	while(n--)
	{	
		if (x>1 && res > maxd/x)
		{
			if (!negn)
			{
				return 0;
			}
			else
				return sign?maxd:-maxd;
		}
		if (x<1 && res < mind/x)
		{
			if (!negn)
			{
				return sign?maxd:-maxd;
			}
			else
				return 0;
		}
		res = res * x;
	}

	if (!negn)
	{
		res = 1.0/res;
	}
	return sign?res:-res;
}

int main(int argc, char const *argv[])
{
	double x = -4.51232;
	int n = 6;
	cout<<endl<<"("<<x<<")^("<<n<<") = "<<mypow(x,n)<<" =? "<<pow(x,n)<<endl<<endl;
	return 0;
}