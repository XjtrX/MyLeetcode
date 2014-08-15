/*
autor: jtr@BNU
date: 14.8.15
problem:
Merge k Sorted Lists Total Accepted: 15581 Total Submissions: 71454 My Submissions
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x): val(x),next(NULL){}
};

ListNode * merge2Lists(ListNode * p, ListNode * q)
{
	ListNode * res = new ListNode(0x80000000);
	if (p == NULL || q == NULL)
	{
		return (p != NULL) ? p : q;
	}
	ListNode * pcur = p, * qcur = q;
	ListNode * rcur = res;
	do{
		if (pcur->val > qcur->val)
		{
			rcur->next = qcur;
			rcur = rcur->next;
			qcur = qcur->next;
			rcur->next = NULL;
		}
		else {
			rcur->next = pcur;
			rcur = rcur->next;
			pcur = pcur->next;
			rcur->next = NULL;
		}
	}while(pcur && qcur);
	if (pcur)
	{
		rcur->next = pcur;
	}
	else
		rcur->next = qcur;

	return res->next;
}

ListNode * mergeKLists(vector<ListNode *> & lists)
{
	ListNode * res = NULL;
	for (int i = 0; i < lists.size(); ++i)
	{
		res = merge2Lists(res, lists[i]);
	}
	return res;
}


int main()
{
	vector<ListNode *> lists;
	ListNode * list1 = new ListNode(12);
	list1->next = new ListNode(14);
	list1->next->next = new ListNode(17);
	list1->next->next->next = new ListNode(32);
	list1->next->next->next->next = new ListNode(44);
	lists.push_back(list1);

	ListNode * list2 = new ListNode(4);
	list2->next = new ListNode(23);
	list2->next->next = new ListNode(32);
	list2->next->next->next = new ListNode(44);
	list2->next->next->next->next = new ListNode(56);
	lists.push_back(list2);

	ListNode * list3 = new ListNode(1);
	list3->next = new ListNode(32);
	list3->next->next = new ListNode(44);
	list3->next->next->next = new ListNode(61);
	list3->next->next->next->next = new ListNode(88);
	lists.push_back(list3);

	ListNode * list4 = new ListNode(2);
	list4->next = new ListNode(12);
	list4->next->next = new ListNode(23);
	list4->next->next->next = new ListNode(32);
	list4->next->next->next->next = new ListNode(334);
	lists.push_back(list4);

	for (std::vector<ListNode *>::iterator i = lists.begin(); i != lists.end(); ++i)
	{
		ListNode * cur = *i;
		while(cur)
		{
			cout<<cur->val<<" -> ";
			cur = cur->next;
		}
		cout<<endl;
	}

	cout<<"-----"<<endl;

	ListNode * res = mergeKLists(lists);

	while(res)
	{
		cout << res->val <<" -> ";
		ListNode * tem = res;

		res = res ->next;
		delete tem;
	}
	cout<<endl;
	return 0;
}