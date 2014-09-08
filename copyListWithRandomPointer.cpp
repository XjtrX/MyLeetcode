/*
author: jtr@BNU
date: 14.9.8
problem:
Copy List with Random Pointer Total Accepted: 18628 Total Submissions: 80234 My Submissions
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

#include "myIncs.h"


struct RandomListNode {
   int label;
   RandomListNode *next, *random;
   RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode * copyRandomList(RandomListNode * head)
{
	if(head == NULL) return NULL;
	RandomListNode * res = new RandomListNode(head->label);
	if(head->next == NULL && head->random == NULL) return res;

	RandomListNode * cur, *rescur;

	queue<RandomListNode *> Q;
	map<RandomListNode *, RandomListNode *> M;
	map<RandomListNode *, bool> visited;

	Q.push(head);
	M[head] = res;

	while(!Q.empty())
	{
		cur = Q.front();
		Q.pop();
		rescur = M[cur];
		if(!visited[cur])
		{
			visited[cur] = true;
			if(cur->next)
			{
				Q.push(cur->next);
				if(!M[cur->next])
					M[cur->next] = new RandomListNode(cur->next->label);
				rescur->next = M[cur->next];
			}
			if(cur->random)
			{
				Q.push(cur->random);
				if(!M[cur->random])
					M[cur->random] = new RandomListNode(cur->random->label);
				rescur->random = M[cur->random];
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	RandomListNode * head = new RandomListNode(1);
	head->next = new RandomListNode(2);
	head->next->next = new RandomListNode(4);
	head->random = head->next;
	head->next->next->random = new RandomListNode(5);


	RandomListNode * res = copyRandomList(head);

	return 0;
}