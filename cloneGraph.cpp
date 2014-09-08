/*
author: jtr@BNU
date: 14.9.8
problem:
Clone Graph Total Accepted: 16363 Total Submissions: 71848 My Submissions
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

#include "myIncs.h"	


struct UndirectedGraphNode {
	int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
{
	if(node == NULL) return NULL;
	if(node->neighbors.size() == 0) return new UndirectedGraphNode(node->label);
	UndirectedGraphNode * res = new UndirectedGraphNode(node->label);
	UndirectedGraphNode * cur, * resCur = res;
	queue<UndirectedGraphNode *> Q;
	map<UndirectedGraphNode *, UndirectedGraphNode *> M;
	map<UndirectedGraphNode *, bool> visited;
	M[node] = res;
	Q.push(node);
	do{
		cur = Q.front();
		Q.pop();
		resCur = M[cur];
		if(visited[cur])
			continue;
		else
			visited[cur] = true;
		cout<<"----"<<cur->label<<endl;
		for (std::vector<UndirectedGraphNode *>::iterator itr = cur->neighbors.begin(); itr != cur->neighbors.end(); ++itr)
		{
			Q.push(*itr);
			// cout<<(*itr)->label<<endl;
			if(!M[*itr])
				M[*itr] = new UndirectedGraphNode((*itr)->label);
			resCur->neighbors.push_back(M[*itr]);
		}
	}while(!Q.empty());
	return M[node];
}


int main(int argc, char const *argv[])
{
	UndirectedGraphNode * node = new UndirectedGraphNode(0);
	// UndirectedGraphNode * node1 = new UndirectedGraphNode(1);
	// UndirectedGraphNode * node2 = new UndirectedGraphNode(2);
	// // UndirectedGraphNode * node3 = new UndirectedGraphNode(3);
	// // UndirectedGraphNode * node4 = new UndirectedGraphNode(4);
	// // UndirectedGraphNode * node5 = new UndirectedGraphNode(5);
	// node->neighbors.push_back(node1);
	// node->neighbors.push_back(node2);
	// node1->neighbors.push_back(node);
	// node1->neighbors.push_back(node2);
	// node2->neighbors.push_back(node2);

	UndirectedGraphNode * res = cloneGraph(node);




	return 0;
}