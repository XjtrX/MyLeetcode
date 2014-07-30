#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "maxPathSum.h"

using namespace std;


struct ListNode
{
	int value;
	ListNode * next;
};


int main()
{
	maxPathSum::Solution test;
	test.test();
	std::cout<<"End"<<std::endl;
	return 0;
}
