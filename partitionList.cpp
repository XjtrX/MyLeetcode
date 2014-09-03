/*
author: jtr@BNU
date: 14.9.3
problem:
Partition List Total Accepted: 16334 Total Submissions: 60838 My Submissions
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/


#include "myIncs.h"


ListNode * partition(ListNode * head, int x)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode * list1 = new ListNode(0);
	ListNode * list2 = new ListNode(0);
	ListNode *cur = head, * cur1 = list1, *cur2 = list2;

	while(cur)
	{
		if (cur->val < x)
		{
			cur1->next = cur;
			cur = cur->next;
			cur1 = cur1->next;
			cur1->next = NULL;
		}
		else
		{
			cur2->next = cur;
			cur = cur->next;
			cur2 = cur2->next;
			cur2->next = NULL;
		}
	}
	cur1->next = list2->next;
	cur = list1->next;
	delete(list1);
	delete(list2);
	return cur;
}

int main(int argc, char const *argv[])
{
	ListNode * head = makeAList("1->12->11->2->3->3");

	printList(head);
	int x = 3;
	cout<<x<<endl;
	ListNode* res = partition(head, x);
	printList(res);

	delList(head);
	return 0;
}