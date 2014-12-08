//main.cpp

#include "vld.h"

#include <iostream>

#include "UnitTest.hpp"


int main(int argc, char* argv[])
{
	std::cout << std::endl;

	UnitTest tester;

	tester.RunTest_LinkedList_Int();
	tester.RunTest_LinkedList_Float();
	
	tester.RunTest_BinarySearchTree_Int();
	tester.RunTest_BinarySearchTree_Float();

	tester.QuitTesting();

	return 0;
}

