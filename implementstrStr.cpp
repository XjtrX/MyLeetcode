/*
author: jtr@BNU
date:14.8.18
problem:
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
//time limite
char * mystrStr(char * haystack, char * needle)
{
	if (strlen(haystack) < strlen(needle))
	{
		return NULL;
	}
	char * res = NULL;
	if (haystack == NULL || needle == NULL)
	{
		return haystack;
	}
	int len = strlen(needle);
	int  *mapk = new int[len];

/*
//time limite for the long string
	for (int i = 0; i < len; ++i)
	{
		mapk[i] = 0;
		for (int j = i ; j >= 0 ; --j)
		{
			//cout<<i<<", "<<j<<endl;
			int tem = 0;
			while(tem < j  && *(needle+tem) == *(needle + i + 1 - j + tem)) tem ++;
			if (tem == j)
			{
				mapk[i] = tem;
				break;
			}
		}
	}
*/
	res = haystack;

	while(strlen(res) >= len && *res != '\0')
	{
		int tem = 0;
		while(*(res+tem) != '\0' && *(needle+tem) != '\0' && (*(res+tem) == *(needle + tem))) tem++;
		if (*(needle + tem) == '\0')
		{
			delete [] mapk;
			return res;
		}
		if (tem == 0)
		{
			res++;
			continue;
		}
		//res  = (res + (tem - mapk[tem-1]));
		res++;
	}
	delete []mapk;
	return NULL;
}

int main(int argc, char const *argv[])
{
	char s1[] = "";

	char s2[] = "";

	//cout<<s1<<endl<<s2<<endl;

	cout<<strlen(s1)<<", "<<strlen(s2)<<endl;
	cout<<mystrStr(s1,s2)<<endl;
	return 0;
}