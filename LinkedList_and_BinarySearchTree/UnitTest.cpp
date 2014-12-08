//UnitTest.cpp

#include "UnitTest.hpp"

#include <string>

#include "BinarySearchTree.hpp"
#include "LinkedList.hpp"


UnitTest::UnitTest()
{}

UnitTest::~UnitTest()
{}


void UnitTest::Pause()
{
	std::cout << std::endl;

	std::cout << "Press Enter/Return to continue... ";
	std::cin.sync();
	std::cin.ignore();

	std::cout << std::endl;
}

void UnitTest::QuitTesting()
{
	std::cout << std::endl;

	std::cout << "Testing session finished, press Enter/Return to exit.";
	std::cin.sync();
	std::cin.ignore();

	std::cout << std::endl;
}


void UnitTest::LinkedListCommands()
{
	std::cout << std::endl;

	std::cout << "Please select an operation: " << std::endl;
	std::cout << std::endl;
	std::cout << "1 - push_front" << std::endl;
	std::cout << "2 - push_back" << std::endl;
	std::cout << "3 - pop_front" << std::endl;
	std::cout << "4 - pop_back" << std::endl;
	std::cout << "5 - search" << std::endl;
	std::cout << "6 - find_range" << std::endl;
	std::cout << "7 - erase" << std::endl;
	std::cout << "8 - print" << std::endl;
	std::cout << "9 - size" << std::endl;
	std::cout << std::endl;
	std::cout << "0 - quit testing" << std::endl;

	std::cout << std::endl;
}

void UnitTest::BinarySearchTreeCommands()
{
	std::cout << std::endl;

	std::cout << "Please select an operation: " << std::endl;
	std::cout << std::endl;
	std::cout << "1 - insert" << std::endl;
	std::cout << "2 - erase" << std::endl;
	std::cout << "3 - traversal_in_order (print)" << std::endl;
	std::cout << "4 - traversal_pre_order (print)" << std::endl;
	std::cout << "5 - traversal_post_order (print)" << std::endl;
	std::cout << "6 - search" << std::endl;
	std::cout << "7 - size" << std::endl;
	std::cout << std::endl;
	std::cout << "0 - quit testing" << std::endl;

	std::cout << std::endl;
}


void UnitTest::RunTest_LinkedList_Int()
{
	LinkedList<int> list;
	std::cout << "LinkedList<int> created!" << std::endl;

	bool running = true;
	char choice = ' ';
	int key = 0;

	while (running)
	{
		LinkedListCommands();
		std::cin >> choice;

		switch (choice)
		{
		case '1':
			std::cout << "push_front selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			list.Push_Front(key);
			break;
		case '2':
			std::cout << "push_back selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			list.Push_Back(key);
			break;
		case '3':
			std::cout << "pop_front selected" << std::endl;
			list.Pop_Front();
			break;
		case '4':
			std::cout << "pop_back selected" << std::endl;
			list.Pop_Back();
			break;
		case '5':
			std::cout << "search selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			list.Search(key);
			break;
		case '6':
			std::cout << "find range selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			std::cout << "Found: " << list.FindRange(key) << " nodes with the specified data" << std::endl;;
			break;
		case '7':
			std::cout << "erase selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			list.Erase(key);
			break;
		case '8':
			std::cout << "print selected" << std::endl;
			list.Print();
			break;
		case '9':
			std::cout << "size selected" << std::endl;
			std::cout << "List size: " << list.Size() << std::endl;
			break;
		case '0':
			running = false;
			std::cout << "Quitting test" << std::endl;
			break;
		default:
			std::cout << "Invalid input!" << std::endl;
			break;
		}
	}

	Pause();
}

void UnitTest::RunTest_LinkedList_Float()
{
	LinkedList<float> list;
	std::cout << "LinkedList<float> created!" << std::endl;

	bool running = true;
	char choice = ' ';
	float key = 0.0f;

	while (running)
	{
		LinkedListCommands();
		std::cin >> choice;

		switch (choice)
		{
		case '1':
			std::cout << "push_front selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			list.Push_Front(key);
			break;
		case '2':
			std::cout << "push_back selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			list.Push_Back(key);
			break;
		case '3':
			std::cout << "pop_front selected" << std::endl;
			list.Pop_Front();
			break;
		case '4':
			std::cout << "pop_back selected" << std::endl;
			list.Pop_Back();
			break;
		case '5':
			std::cout << "search selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			list.Search(key);
			break;
		case '6':
			std::cout << "find range selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			std::cout << "Found: " << list.FindRange(key) << " nodes with the specified data" << std::endl;;
			break;
		case '7':
			std::cout << "erase selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			list.Erase(key);
			break;
		case '8':
			std::cout << "print selected" << std::endl;
			list.Print();
			break;
		case '9':
			std::cout << "size selected" << std::endl;
			std::cout << "List size: " << list.Size() << std::endl;
			break;
		case '0':
			running = false;
			std::cout << "Quitting test" << std::endl;
			break;
		default:
			std::cout << "Invalid input!" << std::endl;
			break;
		}
	}

	Pause();
}

void UnitTest::RunTest_BinarySearchTree_Int()
{
	BinarySearchTree<int> tree;
	std::cout << "BinarySearchTree<int> created!" << std::endl;

	bool running = true;
	char choice = ' ';
	int key = 0;

	while (running)
	{
		BinarySearchTreeCommands();
		std::cin >> choice;

		switch (choice)
		{
		case '1': // insert
			std::cout << "insert selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			tree.Insert(key);
			break;
		case '2': // erase
			std::cout << "erase selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			tree.Erase(key);
			break;
		case '3': // traversal in order
			std::cout << "traversal_in_order (print) selected" << std::endl;
			tree.Traversal_In_Order();
			break;
		case '4': // traversal pre order
			std::cout << "traversal_pre_order (print) selected" << std::endl;
			tree.Traversal_Pre_Order();
			break;
		case '5': // traversal post order
			std::cout << "traversal_post_order (print) selected" << std::endl;
			tree.Traversal_Post_Order();
			break;
		case '6': // search 
			std::cout << "search selected, please enter value, finish with enter/return: ";
			std::cin >> key;
			tree.Search(key);
			break;
		case '7': // size
			std::cout << "size selected" << std::endl;
			tree.PrintSize();
			break;
		case '0':
			running = false;
			std::cout << "Quitting test" << std::endl;
			break;
		default:
			std::cout << "Invalid input!" << std::endl;
			break;
		}
	}

	Pause();
}

void UnitTest::RunTest_BinarySearchTree_Float()
{
	BinarySearchTree<float> tree;
	std::cout << "BinarySearchTree<float> created!" << std::endl;

	bool running = true;
	char choice = ' ';
	float key = 0.0f;

	while (running)
	{
		BinarySearchTreeCommands();
		std::cin >> choice;

		while (running)
		{
			BinarySearchTreeCommands();
			std::cin >> choice;

			switch (choice)
			{
			case '1': // insert
				std::cout << "insert selected, please enter value, finish with enter/return: ";
				std::cin >> key;
				tree.Insert(key);
				break;
			case '2': // erase
				std::cout << "erase selected, please enter value, finish with enter/return: ";
				std::cin >> key;
				tree.Erase(key);
				break;
			case '3': // traversal in order
				std::cout << "traversal_in_order (print) selected" << std::endl;
				tree.Traversal_In_Order();
				break;
			case '4': // traversal pre order
				std::cout << "traversal_pre_order (print) selected" << std::endl;
				tree.Traversal_Pre_Order();
				break;
			case '5': // traversal post order
				std::cout << "traversal_post_order (print) selected" << std::endl;
				tree.Traversal_Post_Order();
				break;
			case '6': // search 
				std::cout << "search selected, please enter value, finish with enter/return: ";
				std::cin >> key;
				tree.Search(key);
				break;
			case '7': // size
				std::cout << "size selected" << std::endl;
				tree.PrintSize();
				break;
			case '0':
				running = false;
				std::cout << "Quitting test" << std::endl;
				break;
			default:
				std::cout << "Invalid input!" << std::endl;
				break;
			}
		}
	}

	Pause();
}