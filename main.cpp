#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "maxPathSum.h"
#include "twoSum.h"
using namespace std;


struct ListNode
{
	int value;
	ListNode * next;
};


int main()
{
	twoSum::Solution test;
	test.test();
	std::cout<<"End"<<std::endl;
	return 0;
}
