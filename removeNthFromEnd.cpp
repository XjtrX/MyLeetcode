/*
author: jtr@BNU
date: 14.8.13
problem:
Remove Nth Node From End of List Total Accepted: 18018 Total Submissions: 60555
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

ListNode * removeNthFromEnd(ListNode * head, int n)
{
	ListNode * front, *last;
	front = head;
	last = head;
	int i = 0;
	while(last)
	{
		if (i<=n)
		{
			last = last->next;
			i++;
		}
		else
		{
			last = last->next;
			front = front->next;
		}
	}
	if (front == head && i == n)
	{
		ListNode * res = head->next;
		free(head);
		return res;
	}
	if (i<n+1)
	{
		return head;
	}
	last = front->next;
	front->next = last->next;
	free(last);
	return head;
}

void printList(ListNode * head)
{
	ListNode * cur = head;
	while(cur)
		if (cur->next != NULL)
		{
			cout<<cur->val<<"->";
			cur = cur->next;
		}
		else
		{
			cout<<cur->val<<endl;
			cur = cur->next;
		}
}

int main()
{
	ListNode * head = new ListNode(32);
	head->next = new ListNode(2);
	ListNode * cur = head-> next;
	cur->next = new ListNode(3);
	cur = cur->next;
	cur->next = new ListNode(213);
	cur = cur->next;
	cur->next = new ListNode(323);

	printList(head);

	printList(removeNthFromEnd(head,1));

	return 0;


}