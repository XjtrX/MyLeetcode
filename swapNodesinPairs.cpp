/*
autor: jtr@BNU
date: 14.8.15
problem:
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x): val(x),next(NULL){}
};


ListNode * swapPairs(ListNode * head)
{
	ListNode * res = new ListNode(0);
	if (head == NULL || head ->next == NULL)
	{
		return head;
	}
	ListNode *pre, *last;
	
	ListNode * cur = res; // the current of the result list
	pre = head->next;
	last = head;
	ListNode * rest = pre->next; //the rest of the unswap list

	do{
		cur->next = pre;
		rest = pre->next;
		cur = cur->next;
		cur->next = last;
		cur = cur->next;
		cur->next = NULL;

		last = rest;
		if (rest)
		{
			pre = rest->next;
		}
	}while(last && pre);
	cur->next = (last);
	return res->next;
}


int main()
{
	ListNode * head = new ListNode(10);
	head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(432);
	head->next->next->next->next = new ListNode(322);

	ListNode * cur = head;
	while(cur)
	{
		if (cur->next)
		{
			cout<<cur->val<<" -> ";
		}else
		{
			cout<<cur->val<<endl;
		}
		cur = cur->next;

	}

	ListNode * res = swapPairs(head);

	ListNode * cr = res;
	while(cr)
	{
		if (cr->next)
		{
			cout<<cr->val<<" -> ";
		}else
		{
			cout<<cr->val<<endl;
		}
		cr = cr->next;

	}

	return 0;
}