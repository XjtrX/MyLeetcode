/*
author: jtr@BNU
date: 14.8.24
problem:
Merge Two Sorted Lists Total Accepted: 21972 Total Submissions: 66093 My Submissions
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x):val(x), next(NULL){}
};

ListNode * mergeTwoLists(ListNode *l1, ListNode * l2)
{
	ListNode * res = new ListNode(0);
	ListNode * cur = res;

	ListNode * cur1 = l1, *cur2 = l2;
	while(cur1 && cur2)
	{
		if (cur1->val > cur2->val)
		{
			cur->next = cur2;
			cur2 = cur2->next;
			cur = cur->next;
			cur->next = NULL;
		}
		else
		{
			cur->next = cur1;
			cur1 = cur1->next;
			cur = cur->next;
			cur->next = NULL;
		}
	}
	if (cur1)
	{
		cur->next = cur1;
	}
	if (cur2)
	{
		cur->next = cur2;
	}
	cur = res->next;
	delete res;
	return cur;
}

int main(int argc, char const *argv[])
{
	ListNode * l1 = new ListNode(1);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(6);

	ListNode * l2 = new ListNode(3);
	l2->next = new ListNode(5);
	l2->next->next = new ListNode(6);
	l2->next->next->next = new ListNode(8);

	ListNode * cur = l1;
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
	cur = l2;
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

	cur = mergeTwoLists(l1, l2);
	while(cur)
	{
		if (cur->next)
		{
			cout<<cur->val<<"->";
		}
		else
			cout<<cur->val<<endl;
		ListNode * tem = cur;
		cur = cur->next;
		delete tem;
	}
	return 0;
}