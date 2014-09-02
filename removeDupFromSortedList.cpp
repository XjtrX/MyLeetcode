/*
author: jtr@BNU
date: 14.9.2
problem:
Remove Duplicates from Sorted List Total Accepted: 24525 Total Submissions: 70029 My Submissions
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
	ListNode * res = new ListNode(-1);

	ListNode * cur = head;
	ListNode * resCur = res;
	ListNode * tem = head;
	int pre = head->val - 1;
	while(cur)
	{
		if (cur->val != pre)
		{
			resCur->next = cur;
			cur = cur->next;
			resCur = resCur->next;
			resCur->next = NULL;
			pre = resCur->val;
		}
		else
		{
			while(cur && cur->val == pre){
				tem = cur;
				cur = cur->next;
				delete tem;
			}
		}
	}

	tem = res;
	res = res->next;
	delete tem;
	return res;

}

int main(int argc, char const *argv[])
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next->next = new ListNode(3);

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


