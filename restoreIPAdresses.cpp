/*
author: jtr@BNU
date: 14.9.3
problem:
Restore IP Addresses Total Accepted: 13444 Total Submissions: 65715 My Submissions
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
// #include <cstring>
#include "myIncs.h"

vector<string> restoreGerneralIp(string s, int dot)
{
	vector<string> res;
	if (s == "") return res;
	if (dot == 0 && (s.size() > 3 || atoi(s.c_str()) > 255 ||(s[0] == '0' && s.size() > 1)))
	{
		return res;
	}
	if (dot == 0 && s.size() < 4 && atoi(s.c_str())<256)
	{
		res.push_back(s);
		return res;
	}

	string s1 = s.substr(0,1);
	if (atoi(s1.c_str())< 256)
	{
		vector<string> tem = restoreGerneralIp(s.substr(1),dot - 1);
		for (std::vector<string>::iterator i = tem.begin(); i != tem.end(); ++i)
		{
			string stem = s1;
			stem.append("." + (*i));
			res.push_back(stem);
		}
	}
	s1 = s.substr(0,2);
	if (atoi(s1.c_str()) > 9 && atoi(s1.c_str())< 256)
	{
		vector<string> tem = restoreGerneralIp(s.substr(2),dot - 1);
		for (std::vector<string>::iterator i = tem.begin(); i != tem.end(); ++i)
		{
			string stem = s1;
			stem.append("." + (*i));
			res.push_back(stem);
		}
	}
	s1 = s.substr(0,3);

	if (atoi(s1.c_str())< 256 && atoi(s1.c_str()) >= 100)
	{
		vector<string> tem = restoreGerneralIp(s.substr(3),dot - 1);
		for (std::vector<string>::iterator i = tem.begin(); i != tem.end(); ++i)
		{
			string stem = s1;
			stem.append("." + (*i));
			res.push_back(stem);
		}
	}
	return res;

}

vector<string> restoreIpAddresses(string s)
{
	vector<string> res;
	if (s == "") return res;
	int len = s.size();
	if(len < 4) return res;

	return restoreGerneralIp(s, 3);
}

int main(int argc, char const *argv[])
{

	string s = "010010";
	cout<<s<<endl;
	vector<string> res = restoreIpAddresses(s);

	for (std::vector<string>::iterator i = res.begin(); i != res.end(); ++i)
	{
		cout<<*i<<endl;
	}
	return 0;
}