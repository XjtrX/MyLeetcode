#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "maxPathSum.h"
#include "twoSum.h"
#include "treeSumCloset.h"
using namespace std;


struct ListNode
{
	int value;
	ListNode * next;
};


int main()
{
	treeSumCloset::Solution test;
	test.test();
	std::cout<<"End"<<std::endl;
	return 0;
}
