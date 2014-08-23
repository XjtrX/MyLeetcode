/*
author: jtr@BNU
date: 14.8.23
problem:
Rotate List Total Accepted: 14490 Total Submissions: 65981 My Submissions
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode * rotateRight(ListNode *head, int k)
{
	int len = 0;
	ListNode * tem = head;
	ListNode * tail = head;
	while(tem){
		if (tem->next == NULL)
		{
			tail = tem;
		}
		tem= tem->next; 
		len++;
	}
	if (len == 0) return head;
	k = k%len;
	if (k == 0) return head;
	ListNode * res = new ListNode(0);
	ListNode * fast = head, * slow = head;
	ListNode * cur = res;
	while(slow){
		if(k != -1)
		{
			slow = slow->next;
			k--;
		}
		else
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	slow = head;
	cur = fast;
	fast = fast->next;
	cur->next = NULL;
	cur = res;
	while(slow)
	{
		cur->next = fast;//the result's new node
		cur = cur->next;//move the tail of the result, but next is not null
		tail->next = slow;//put the node at the tail
		slow = slow->next;//next current node
		tail = tail->next;//
		tail->next = NULL;//
		fast = cur->next;//
		cur->next = NULL;
	}
	cur->next = fast;
	return res->next;
}

int main(int argc, char const *argv[])
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	ListNode * cur = head;
	while(cur)
	{
		if (cur->next)
		{
			cout<<cur->val<<"->";
		}
		else
			cout<<cur->val;
		cur = cur->next;
	}
	cout<<endl;
	int n = 3;
	cout<<n<<endl;

	ListNode * res = rotateRight(head,n);
	cur = res;
	while(cur)
	{
		if (cur->next)
		{
			cout<<cur->val<<"->";
		}
		else
			cout<<cur->val;
		cur = cur->next;
	}
	cout<<endl;
	return 0;
}