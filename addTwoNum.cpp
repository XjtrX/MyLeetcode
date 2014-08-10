/*
author: jtr@BNU
date: 14.8.10
problem:
Add Two Numbers Total Accepted: 19160 Total Submissions: 83529 My Submissions
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>


using namespace std;



 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode * res;
	bool up = false;
	if (l1 == NULL || l2 == NULL)
	{
		return NULL;
	}

	up = ( (l1->val + l2->val) >= 10);
	res = new ListNode((l1->val + l2->val)%10);
	ListNode * cur = res;
	ListNode * cur1, * cur2;
	cur1 = l1->next; cur2 = l2->next;
	int tem = 0;
	while(cur1 != NULL && cur2 != NULL){
		tem = cur1->val + cur2->val ;
		tem = (up? tem+1 : tem);
		up = (tem >= 10);
		cur->next = new ListNode(tem%10);

		cur = cur->next;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	while(cur1)
	{
		tem = (up? cur1->val + 1 : cur1->val);
		up = (tem >= 10);
		cur->next = new ListNode(tem%10);

		cur1 = cur1->next;
		cur = cur->next;
	}
	while(cur2)
	{
		tem = (up? cur2->val + 1 : cur2->val);
		up = (tem >= 10);
		cur->next = new ListNode(tem%10);

		cur2 = cur2->next;
		cur = cur->next;
	}
	if (up)
	{
		cur->next = new ListNode(1);
	}
	return res;
}

void printList(ListNode * head)
{
	ListNode * cur = head;
	while(cur)
	{
		cout<<cur->val<<", ";
		cur = cur->next;
	}
	cout<<endl;
}

int main()
{
	ListNode * l1 = new ListNode(7);
	l1->next = new ListNode(4);
	//l1->next->next = new ListNode(5);

	ListNode * l2 = new ListNode(2);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(3);

	cout<<"l1: ";
	printList(l1);
	cout<<"l2: ";
	printList(l2);

	ListNode * res = addTwoNumbers(l1,l2);
	cout<<"result: ";
	printList(res);
	return 0;
}