//UnitTest.hpp

#pragma once

class UnitTest
{
public:
	UnitTest();
	~UnitTest();

	void Pause();
	void LinkedListCommands();
	void BinarySearchTreeCommands();

	void RunTest_LinkedList_Int();
	void RunTest_LinkedList_Float();

	void RunTest_BinarySearchTree_Int();
	void RunTest_BinarySearchTree_Float();
};