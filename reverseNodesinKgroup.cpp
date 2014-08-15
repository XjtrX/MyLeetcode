/*
author: jtr@BNU
date: 14.8.15
problem:
Reverse Nodes in k-Group Total Accepted: 12420 Total Submissions: 49984
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x): val(x), next(NULL){}
};

ListNode * reverseKGroup(ListNode * head, int k)
{
	ListNode * res = new ListNode(0);
	if (k<2 || head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode * tem = new ListNode(0);
	ListNode *cur = head;
	int wi = k;
	ListNode * rcur = res;
	while(cur)
	{

		ListNode * tt = cur;
		wi = k;
		while(tt && wi) {
			tt = tt->next;
			wi--;
		}
		if (wi)
		{
			tem->next = NULL;
			rcur->next = cur;
			delete tem;
			return res->next;
		}
		else
		{
			wi = k;
			tem->next = NULL;
			ListNode * te = cur;
			while(wi--)
			{
				tt = cur->next;
				cur->next = tem->next;
				tem->next = cur;
				cur = tt;
			}
			rcur->next = tem->next;
			rcur = te;
		}
	}
	rcur = res;
	res = res->next;
	delete rcur;
	return res;
}

int main(int argc, char const *argv[])
{
	ListNode * head = new ListNode(10);
	head->next = new ListNode(5);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(432);
	head->next->next->next->next = new ListNode(322);
	int k = 7;
	cout<<k<<endl;
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

	ListNode * res = reverseKGroup(head, k);

	cur = res;
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

	return 0;
}