//BinarySearchTree.hpp

#pragma once

#include <iostream>
#include <string>

template <class T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;

		Node* left_child = nullptr;
		Node* right_child = nullptr;
	};

	Node* m_root;
	Node* m_current;
	Node* m_temporary;

	unsigned long int size;

public:
	BinarySearchTree()
	{
		m_root = nullptr;
		m_current = nullptr;
		m_temporary = nullptr;

		size = 0;
	}

	~BinarySearchTree()
	{
		RemoveSubTree(m_root); //<-- traversal post order

		m_root = nullptr;
		m_current = nullptr;
		m_temporary = nullptr;

		size = 0;
	}

	void Insert(T add_data)
	{
		Node* n = new Node;
		n->data = add_data;

		if (m_root == nullptr)
		{
			m_root = n;
			std::cout << "Data inserted";
			size++;
		}
		else
		{
			if (n->data == m_root->data)
			{
				std::cout << "Data already present, aborting insert";
			}
			else if (n->data < m_root->data)
			{
				Left(n);
			}
			else
			{
				Right(n);
			}
		}

		std::cout << "( " << add_data << " )" << std::endl;
	}

	void Erase(T del_data)
	{
		RemoveNode(del_data, m_root);
	}

	// Prints all nodes in tree (In Order Traversal)
	void Traversal_In_Order()
	{
		std::cout << std::endl;
		std::cout << "In order: ";

		if (m_root == nullptr)
		{
			std::cout << "The tree is empty" << std::endl;
		}
		else
		{
			PrintInOrder(m_root);
		}
		
		std::cout << std::endl << std::endl;;
	}

	// Prints all nodes in tree (Pre Order Traversal)
	void Traversal_Pre_Order()
	{
		std::cout << std::endl;
		std::cout << "Pre order: ";

		if (m_root == nullptr)
		{
			std::cout << "The tree is empty" << std::endl;
		}
		else
		{
			PrintPreOrder(m_root);
		}
		
		std::cout << std::endl << std::endl;;
	}

	// Prints all nodes in tree (Post Order Traversal)
	void Traversal_Post_Order()
	{	
		std::cout << std::endl;
		std::cout << "Post order: ";

		if (m_root == nullptr)
		{
			std::cout << "The tree is empty" << std::endl;
		}
		else
		{
			PrintPostOrder(m_root);
		}
	
		std::cout << std::endl << std::endl;;
	}

	void Search(T find_data)
	{
		m_current = m_root;
		m_temporary = m_root;

		bool searching = true;

		while (searching)
		{
			if (m_current == nullptr)
			{
				std::cout << "No nodes with " << find_data << " aborting..." << std::endl;
				searching = false;
			}
			else if (m_current->data == find_data)
			{
				std::cout << find_data << " was found!" << std::endl;
				searching = false;
			}
			else if (find_data < m_current->data)
			{
				m_temporary = m_current;
				m_current = m_current->left_child;
			}
			else
			{
				m_temporary = m_current;
				m_current = m_current->right_child;
			}
		}

		std::cout << std::endl;
	}

	void PrintSize()
	{
		std::cout << "Size: " << Size() << std::endl << std::endl;
	}

	unsigned long int Size()
	{
		return size;
	}


private:
	void Left(Node* node)
	{
		if (m_root->left_child == nullptr)
		{
			m_root->left_child = node;
			std::cout << "Data inserted";
			size++;
		}
		else
		{
			Climb(node, m_root->left_child);
		}
	}
	void Right(Node* node)
	{
		if (m_root->right_child == nullptr)
		{
			m_root->right_child = node;
			std::cout << "Data inserted";
			size++;
		}
		else
		{
			Climb(node, m_root->right_child);
		}
	}
	void Climb(Node* add_node, Node* current)
	{
		m_current = current;
		bool climbing = true;

		while (climbing)
		{
			if (add_node->data == m_current->data)
			{
				std::cout << "Data already present, aborting insert";
				climbing = false;
			}
			else if (add_node->data < m_current->data)
			{
				if (m_current->left_child == nullptr)
				{
					m_current->left_child = add_node;
					size++;
					std::cout << "Data inserted";
					climbing = false;
				}
				else
				{
					m_current = m_current->left_child;
				}
			}
			else // if add_node-> data > m_current->data
			{
				if (m_current->right_child == nullptr)
				{
					m_current->right_child = add_node;
					size++;
					std::cout << "Data inserted";
					climbing = false;
				}
				else
				{
					m_current = m_current->right_child;
				}
			}
		}
	}

	void PrintInOrder(Node* pointer)
	{
		if (m_root != nullptr)
		{
			if (pointer->left_child != nullptr)
			{
				PrintInOrder(pointer->left_child);
			}

			std::cout << pointer->data << " ";

			if (pointer->right_child != nullptr)
			{
				PrintInOrder(pointer->right_child);
			}
		}
		else
		{
			std::cout << "The tree is empty";
		}
	}
	void PrintPreOrder(Node* pointer)
	{
		if (pointer == nullptr)
		{
			return;
		}

		std::cout << pointer->data << " ";

		PrintPreOrder(pointer->left_child);
		PrintPreOrder(pointer->right_child);
	}
	void PrintPostOrder(Node* pointer)
	{
		if (pointer == nullptr)
		{
			return;
		}

		PrintPostOrder(pointer->left_child);
		PrintPostOrder(pointer->right_child);

		std::cout << pointer->data << " ";
	}

	T FindSmallest(Node* pointer)
	{
		if (m_root == nullptr)
		{
			std::cout << "The tree is empty, cannot search for smallest value" << std::endl;
			return NULL;
		}
		else
		{
			if (pointer->left_child != nullptr)
			{
				return FindSmallest(pointer->left_child);
			}
			else
			{
				return pointer->data;
			}
		}
	}

	void RemoveNode(T del_data, Node* parent)
	{
		if (m_root != nullptr)
		{
			if (m_root->data == del_data)
			{
				RemoveRootMatch();
			}
			else
			{
				if (del_data < parent->data && parent->left_child != nullptr)
				{
					parent->left_child->data == del_data ?
						RemoveMatch(parent, parent->left_child, true) : RemoveNode(del_data, parent->left_child);
				}
				else if (del_data < parent->data && parent->right_child != nullptr)
				{
					parent->right_child->data == del_data ?
						RemoveMatch(parent, parent->right_child, false) : RemoveNode(del_data, parent->right_child);
				}
				else
				{
					std::cout << "The value (" << del_data << ") was not found" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "The tree is empty, aborting erase" << std::endl;
		}

		std::cout << std::endl;
	}
	void RemoveMatch(Node* parent, Node* match, bool left)
	{
		if (m_root != nullptr)
		{
			Node* del_pointer;
			T matchData = match->data;
			T smallestInRightSubTree;

			// Case 0 - 0 Children
			if (match->left_child == nullptr && match->right_child == nullptr)
			{
				del_pointer = match;

				left == true ?
					parent->left_child = nullptr : parent->right_child = nullptr;

				delete del_pointer;
				std::cout << "The node containing (" << matchData << ") was removed" << std::endl;
			}

			// Case 1 - 1 Child
			else if (match->left_child == nullptr && match->right_child != nullptr)
			{
				left == true ?
					parent->left_child = match->right_child : parent->right_child = match->right_child;

				match->right_child = nullptr;
				del_pointer = match;
				delete del_pointer;
				std::cout << "The node containing (" << matchData << ") was removed" << std::endl;
			}
			else if (match->left_child != nullptr && match->right_child == nullptr)
			{
				left == true ?
					parent->left_child = match->left_child : parent->right_child = match->left_child;

				match->left_child = nullptr;
				del_pointer = match;
				delete del_pointer;
				std::cout << "The node containing (" << matchData << ") was removed" << std::endl;
			}

			// Case 2 - 2 Children
			else
			{
				smallestInRightSubTree = FindSmallest(match->right_child);
				RemoveNode(smallestInRightSubTree, match);
				match->data = smallestInRightSubTree;
			}
		}
		else
		{
			std::cout << "The tree is empty, cannot remove match" << std::endl;
		}
	}
	void RemoveRootMatch()
	{
		if (m_root != nullptr)
		{
			Node* del_pointer = m_root;
			T rootData = m_root->data;
			T smallestInRightSubtree;

			// Case 0 - 0 children
			if (m_root->left_child == nullptr && m_root->right_child == nullptr)
			{
				m_root = nullptr;
				delete del_pointer;
			}
			
			// Case 1 - 1 child
			else if (m_root->left_child == nullptr && m_root->right_child != nullptr)
			{
				m_root = m_root->right_child;
				del_pointer->right_child = nullptr;
				delete del_pointer;
				std::cout << "The root, containing (" << rootData << ") was deleted. " << "New root contains (" << m_root->data << ")." << std::endl;
			}
			else if (m_root->left_child != nullptr && m_root->right_child == nullptr)
			{
				m_root = m_root->left_child;
				del_pointer->left_child = nullptr;
				delete del_pointer;
				std::cout << "The root, containing (" << rootData << ") was deleted. " << "New root contains (" << m_root->data << ")." << std::endl;
			}

			// Case 2 - 2 children
			else
			{
				smallestInRightSubtree = FindSmallest(m_root->right_child);
				RemoveNode(smallestInRightSubtree, m_root);
				m_root->data = smallestInRightSubtree;
				std::cout << "The root containing (" << rootData << ") was overwritten with (" << m_root->data << ")." << std::endl;
			}
		}
		else
		{
			std::cout << "Cannot remove root, the tree is empty!" << std::endl;
		}
	}

	void RemoveSubTree(Node* pointer)
	{
		if (pointer != nullptr)
		{
			if (pointer->left_child != nullptr)
			{
				RemoveSubTree(pointer->left_child);
			}
			if (pointer->right_child != nullptr)
			{
				RemoveSubTree(pointer->right_child);
			}

			std::cout << "Deleting the node containing (" << pointer->data << ")." << std::endl;

			delete pointer;
		}
	}
};



/*

	OLD CODE 1:

	void Traversal_In_Order()
	{
	if (m_root == nullptr)
	{
	std::cout << "No nodes in tree, traversal aborted" << std::endl;
	return;
	}

	std::cout << "Start - ";

	// Find first node
	if (m_root->left_child == nullptr)
	{
	std::cout << m_root->data;
	}
	else
	{
	m_current = m_root;
	m_temporary = m_root;

	while (m_current->left_child != nullptr)
	{
	m_temporary = m_current;
	m_current = m_current->left_child;
	}

	std::cout << m_current->data;
	}

	// Any more left nodes?
	if (m_temporary != m_root)
	{
	// Find all left nodes in order
	}

	// Any right nodes?
	if (m_root->right_child == nullptr)
	{
	if (m_root->left_child != nullptr)
	{
	std::cout << m_root->data;
	}
	}
	else
	{
	//find right nodes in order
	}

	std::cout << " - End" << std::endl;
	}
*/

/*
	OLD CODE 2:

	void Erase(T del_data)
	{
	std::string child = Search(del_data);
	// m_current now points to node containing del_data
	// m_temporary now points to node checked before m_current
	// child tells if m_current is Right or Left child of m_temporary

	if (m_current == m_root)
	{
	//how to handle deletion of root when subtrees are present?

	Node* tempLeft = m_root->left_child;
	Node* tempRight = m_root->right_child;

	delete m_root;
	m_root = nullptr;
	std::cout << "Erasing " << del_data << " ..." << std::endl;
	size--;

	return;
	}

	if (m_current != nullptr)
	{
	// No children
	if (m_current->left_child == nullptr && m_current->right_child == nullptr)
	{
	delete m_current;
	m_current = nullptr;
	std::cout << "Erasing " << del_data << " ..." << std::endl;
	size--;

	// reassign m_temporary's child pointer (create method called NewChild()?)
	if (child == "Left")
	{
	m_temporary->left_child = m_current;
	}
	else if (child == "Right")
	{
	m_temporary->right_child = m_current;
	}
	}
	// One child
	else if (m_current->left_child == nullptr || m_current->right_child == nullptr)
	{
	Node* child_Ptr;
	if (m_current->left_child == nullptr)
	child_Ptr = m_current->right_child;
	else
	child_Ptr = m_current->left_child;

	delete m_current;
	m_current = child_Ptr;
	std::cout << "Erasing " << del_data << " ..." << std::endl;
	size--;

	// reassign m_temporary's child pointer (create method called NewChild()?)
	if (child == "Left")
	{
	m_temporary->left_child = m_current;
	}
	else if (child == "Right")
	{
	m_temporary->right_child = m_current;
	}
	}
	// Two children
	else
	{
	Node* left = m_current->left_child;
	Node* right = m_current->right_child;

	delete m_current;
	m_current = left;
	std::cout << "Erasing " << del_data << " ..." << std::endl;
	size--;

	if (m_current->right_child == nullptr)
	{
	m_current->right_child = right;
	}
	else
	{
	Node* travel_right = m_current->right_child;

	while (travel_right->right_child != nullptr)
	{
	travel_right = travel_right->right_child;
	}

	travel_right->right_child = right;
	}

	// reassign m_temporary's child pointer (create method called NewChild()?)
	if (child == "Left")
	{
	m_temporary->left_child = m_current;
	}
	else if (child == "Right")
	{
	m_temporary->right_child = m_current;
	}
	}
	}

	std::cout << std::endl;
	}
*/

/*
	OLD CODE 3:

	std::string Search(T find_data)
	{
	m_current = m_root;
	m_temporary = m_root;
	std::string child = "";
	bool searching = true;

	while (searching)
	{
	if (m_current == nullptr)
	{
	std::cout << "No nodes with " << find_data << " aborting..." << std::endl;
	searching = false;
	}
	else if (m_current->data == find_data)
	{
	std::cout << find_data << " was found!" << std::endl;
	searching = false;
	}
	else if (find_data < m_current->data)
	{
	m_temporary = m_current;
	m_current = m_current->left_child;
	child = "Left";
	}
	else
	{
	m_temporary = m_current;
	m_current = m_current->right_child;
	child = "Right";
	}
	}

	std::cout << std::endl;
	return child;
	}
*/