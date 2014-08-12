/*
author: jtr@BNU
date: 14.8.11
problem:
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you knyow that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
///All the negative cannt be palindromes........................
#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	if (x< 0)
	{
		return false;
	}
	int  tem = x;
	int y = 0;
	while(tem)
	{
		if (y>0x7fffffff/10 || (y == 0x7fffffff && tem%10 > 0x7fffffff%10))
		{
			cout<<y<<" , "<<tem<<"  H"<<endl;
			return false;
		}
		y = y*10 + tem%10;
		tem /=10;
	}
	if ( x == y)
	{
		return true;
	}
	return false;
}

int main()
{
	int x  = -2147447412;
	//cout<<int(0x80000000)<<endl;
	cout<<x<<" is "<< (isPalindrome(x)?"a palindrome number.":"not a palindrome number.")<<endl;
	return 0;
}