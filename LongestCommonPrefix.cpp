/*
author: jtr@BNU
date:14.8.13

problem:
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
	string res;
	if (strs.size() < 1)
	{
		return res;
	}
	res = strs[0];
	size_t pos = res.size();
	for (std::vector<string>::iterator i = strs.begin() + 1; i != strs.end(); ++i)
	{
		size_t tem = 0;
		while(tem < pos && tem < (*i).size() && (*i)[tem] == res[tem]) tem++;
		pos = (tem < pos) ? tem : pos; 
	}
	res = res.substr(0, pos);
	return res;
}

int main()
{
	vector<string> strs = {"abcdsdfsfdsafdafda",
						"abcdsdffffffff",
						"abcdssssssss",
						"abcdss"};
	for (std::vector<string>::iterator i = strs.begin(); i != strs.end(); ++i)
	{
		cout<<*i<<endl;
	}

	cout<<"-----"<<endl<<longestCommonPrefix(strs)<<endl;
	return 0;
}