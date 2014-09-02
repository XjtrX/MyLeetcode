/*
author: jtr@BNU
date: 14.9.2
problem:
Remove Duplicates from Sorted List II Total Accepted: 17946 Total Submissions: 72083 My Submissions
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x):val(x), next(NULL){}
};

ListNode * deleteDuplicates(ListNode * head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode * res = new ListNode(head->val - 1);
	ListNode * cur = head;
	ListNode * pre = res;
	ListNode * resCur = res;
	ListNode * tem;
	bool flag = true;
	while(cur)
	{
		if (cur->val != pre->val)
		{
			if (!flag)
			{
				resCur->next = pre;
				resCur = resCur->next;
				resCur->next = NULL;
			}
			pre = cur;
			cur = cur->next;
			flag = false;
		}
		else if (cur->val == pre->val)
		{
			while(cur && cur->val == pre->val)
			{
				tem = cur;
				cur = cur->next;
				delete tem;
				flag = true;
			}
		}
	}
	if (!flag)
	{
		resCur->next = pre;
		resCur = resCur->next;
		resCur->next = NULL;
	}
	tem = res;
	res = res->next;
	return res;
}

int main(int argc, char const *argv[])
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);
	// head->next->next->next->next->next = new ListNode(3);
	// head->next->next->next->next->next->next = new ListNode(3);

	ListNode * cur = head;
	while(cur)
	{
		cout<<cur->val<<"->";
		cur = cur->next;
	}
	cout<<endl;

	cur = deleteDuplicates(head);

	while(cur)
	{
		ListNode * p = cur;
		cout<<cur->val<<"->";
		cur = cur->next;
		delete p;
	}
	cout<<endl;
	return 0;
}