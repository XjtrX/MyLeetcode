#ifndef MYINCS_H
#define MYINCS_H
/*
author: jtr@BNU
date: 14.9.3
descript:
define the normal struct and functions.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;


struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x):val(x), next(NULL){}
};

ListNode * makeAList(string s)
{
	ListNode * head = new ListNode(1);
	ListNode * cur = head;
	int tem;
	stringstream ss(s);
	char c;
	while(ss>>tem)
	{
		cur->next = new ListNode(tem);
		cur = cur->next;
		ss>>c;
		ss>>c;
	}

	cur = head;
	head = head->next;
	delete cur;
	return head;
}
void printList(ListNode * head)
{
	ListNode * cur = head;
	while(cur)
	{
		if (cur->next)
		{
			cout<<cur->val<<"->";
		}
		else
			cout<<cur->val<<endl;
		cur = cur->next;
	}
}

void delList(ListNode * head)
{
	ListNode * tem;
	while(head)
	{
		tem = head;
		head = head->next;
		delete tem;
	}
}
#endif