/*
author: jtr@BNU
date: 14.9.3
problem:
Reverse Linked List II Total Accepted: 17165 Total Submissions: 66052 My Submissions
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include "myIncs.h"

ListNode * reverseBetween(ListNode * head, int m, int n)
{
	int curlen = 1;
	if(m == n) return head;
	ListNode * res = new ListNode(0);
	ListNode * tailRes = res;
	ListNode * cur = head;
	ListNode * tem, * pre = new ListNode(0);


	while(curlen < m && cur)
	{
		curlen++;
		pre->next = cur;
		cur = cur->next;
	}
	
	while(curlen <= n && cur)
	{
		if(curlen == m) tailRes = cur;
		curlen++;
		tem = cur;
		cur = cur->next;
		tem->next = res->next;
		res->next = tem;
	}
	tailRes->next = cur;
	if(pre->next)
	{
		pre->next->next = res->next;
		delete res;
		delete pre;
		return head;
	}

	delete pre;
	tem = res;
	res = res->next;
	delete tem;
	return res;
}

int main(int argc, char const *argv[])
{
	ListNode * head = makeAList("1->2->3->4->5->6->7->8->9");
	printList(head);
	int m = 3, n = 2;
	cout<<m<<","<<n<<endl;

	ListNode * res = reverseBetween(head,m,n);
	printList(res);
	delList(res);
	return 0;
}

