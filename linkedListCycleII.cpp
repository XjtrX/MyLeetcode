/*
author:jtr@BNU
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * }
 */
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode * front, * last;
        front = head;
        last = head;
        while(front != NULL && last != NULL)
        {
        	if (front->next != NULL)
        	{
        		front = front->next->next;
        	}
        	else
        		return NULL;
        	last = last->next;
        	if (last == front)
        	{
        		front =  head;
        		while(last != front){
        			front = front->next;
        			last = last->next;
        		}
        		return front;
        	}
        }
        return NULL;

    }
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode * cur =head;
	cur->next = new ListNode(2);
	cur = cur->next;
	cur->next = new ListNode(3);
	cur = cur->next;
	cur->next = new ListNode(4);
	cur = cur->next;
	cur->next = new ListNode(5);
	cur = cur->next;
	cur->next = new ListNode(6);
	cur = cur->next;
	cur->next = new ListNode(7);
	cur = cur->next;
	cur->next = head->next->next;
Solution test;

cout<<test.detectCycle(head)->val<<endl;

	return 0;
}