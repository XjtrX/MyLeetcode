/*
author: jtr@BNU
date: 14.8.18
problem:
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
//the L list contarins same string
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// vector<int> findSubstring(string S, vector<string >  &L)
// {
// 	vector<int> res;
// 	res.clear();
// 	if (L.size() < 1)
// 	{
// 		return res;
// 	}
// 	int lens = S.size(), len = L[0].size(), lenl = L.size();
// 	if (lens < len * lenl)
// 	{
// 		return res;
// 	}
// 	std::unordered_map<string, int> mapstr;
// 	for (std::vector<string>::iterator itr = L.begin(); itr != L.end(); ++itr)
// 	{
// 		++mapstr[*itr];
// 	}
// 	int cur = 0;
// 	int mark = 1;
// 	std::unordered_map<string, int> maptem;
// 	int worlen = len*lenl;
// 	while(cur <= lens - worlen)
// 	{
// 		int tem = 0;
// 		maptem.clear();
// 		while(tem < lenl)
// 		{
// 			string stem = S.substr(cur + tem * len,len);
// 			if ( mapstr[stem] <= maptem[stem])
// 			{
// 				break;
// 			}
// 			++mapstr[stem];
// 			tem++;
// 			if (tem == lenl) res.push_back(cur);
// 		}
// 		cur++;
// 	}
// 	return res;
// }
//I dont know why the up method cannt run in the limit time
vector<int> findSubstring(string s, vector<string>& dict) {
	size_t wordLength = dict.front().length();
	size_t catLength = wordLength * dict.size();
	vector<int> result;
	if (s.length() < catLength) return result;
	unordered_map<string, int> wordCount;
	for (auto const& word : dict) ++wordCount[word];
	for (auto i = begin(s); i <= prev(end(s), catLength); ++i) {
		unordered_map<string, int> unused(wordCount);
		for (auto j = i; j != next(i, catLength); j += wordLength) {
			auto pos = unused.find(string(j, next(j, wordLength)));
			if (pos == unused.end() || pos->second == 0) break;
			if (--pos->second == 0) unused.erase(pos);
		}
		if (unused.size() == 0) result.push_back(distance(begin(s), i));
	}
	return result;
}

int main(int argc, char const *argv[])
{
	
	string s = "footnamefastfootnamefootboosfootname";
	vector <string> L = {"foot","name",};

	cout<< s << endl;
	for (std::vector<string>::iterator i = L.begin(); i != L.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;


	vector < int > res = findSubstring(s, L);

	for (std::vector<int>::iterator i = res.begin(); i != res.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;
	return 0;
}