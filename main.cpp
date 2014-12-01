//main.cpp

#include "vld.h"

#include "LinkedList.hpp"
#include "BinarySearchTree.hpp"

int main(int argc, char* argv[])
{
	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };

	BinarySearchTree<int>* myTree = new BinarySearchTree<int>;

	myTree->Traversal_In_Order();

	for (unsigned int i = 0; i < 16; i++)
	{
		myTree->Insert(TreeKeys[i]);
	}

	myTree->Erase(50);

	myTree->Traversal_In_Order();

	myTree->Traversal_Pre_Order();

	myTree->Traversal_Post_Order();

	delete myTree;
	myTree = nullptr;

	LinkedList<int> list;

	for (unsigned int u = 0; u < 16; u++)
	{
		list.Push_Back(TreeKeys[u]);
	}

	list.Push_Front(200);

	list.Erase(50);

	list.Print();

	std::cout << std::endl << "Size: " << list.Size() << std::endl;

	std::cin.get();
	return 0;
}

