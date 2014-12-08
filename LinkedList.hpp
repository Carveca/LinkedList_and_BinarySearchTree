//LinkedList.hpp

#pragma once

template <class T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next = nullptr;
	};

	Node* m_head;
	Node* m_current;
	Node* m_temporary;

public:
	LinkedList()
	{
		m_head = nullptr;
		m_current = nullptr;
		m_temporary = nullptr;
	}

	~LinkedList()
	{
		if (m_head != nullptr)
		{
			m_current = m_head;

			while (m_current != nullptr)
			{
				m_temporary = m_current;
				m_current = m_current->next;
				
				delete m_temporary;
			}
		}

		m_head = nullptr;
		m_current = nullptr;
		m_temporary = nullptr;
	}

	void Push_Front(T add_data)
	{
		Node* n = new Node;
		n->next = m_head;
		n->data = add_data;
		m_head = n;
	}

	void Push_Back(T add_data)
	{
		Node* n = new Node;
		n->next = nullptr;
		n->data = add_data;

		if (m_head == nullptr)
		{
			m_head = n;
		}
		else
		{
			m_current = m_head;

			while (m_current->next != nullptr)
			{
				m_current = m_current->next;
			}

			m_current->next = n;
		}
	}

	void Pop_Front()
	{
		std::cout << std::endl;

		if (m_head == nullptr)
		{
			std::cout << "No nodes in list, cannot pop front" << std::endl;
		}
		else
		{
			m_temporary = m_head->next;

			delete m_head;
			m_head = m_temporary;
		}
	}

	void Pop_Back()
	{
		std::cout << std::endl; 

		if (m_head == nullptr)
		{
			std::cout << "No nodes in list, cannot pop back" << std::endl;
		}
		else
		{
			m_current = m_head;
			m_temporary = m_head;

			while (m_current->next != nullptr)
			{
				m_temporary = m_current;
				m_current = m_current->next;
			}

			if (m_current == m_head)
			{
				delete m_head;
				m_head = nullptr;
			}
			else
			{
				delete m_current;
				m_current = m_temporary;
				m_current->next = nullptr;
			}
		}
	}

	// Prints out all nodes
	void Print()
	{
		std::cout << std::endl;
		std::cout << "Print: ";

		if (m_head == nullptr)
		{
			std::cout << "No nodes in list, cannot print" << std::endl;
		}
		else
		{
			m_current = m_head;

			while (m_current != nullptr)
			{
				std::cout << m_current->data << " ";
				m_current = m_current->next;
			}
		}

		std::cout << std::endl;
	}

	// Erase the first node found with del_data
	void Erase(T del_data)
	{
		std::cout << std::endl;

		if (m_head == nullptr)
		{
			std::cout << "No nodes in list, cannot erase" << std::endl;
		}
		else
		{
			m_current = m_head;
			m_temporary = m_head;

			while (m_current != nullptr && m_current->data != del_data)
			{
				m_temporary = m_current;
				m_current = m_current->next;
			}

			if (m_current == nullptr)
			{
				std::cout << del_data << " was not found!" << std::endl;
			}
			else
			{
				if (m_current == m_head)
				{
					m_head = m_head->next;
					delete m_current;
				}
				else
				{
					Node* del_pointer = m_current;
					m_current = m_current->next;

					delete del_pointer;
					del_pointer = nullptr;

					m_temporary->next = m_current;
				}

				std::cout << del_data << " was deleted!" << std::endl;
			}
		}
	}


	// Boolean, true = at least one node has data
	bool Search(T data)
	{
		std::cout << std::endl;

		if (m_head == nullptr)
		{
			std::cout << "No nodes in list, cannot search" << std::endl;
		}
		else
		{
			m_current = m_head;

			while (m_current != nullptr)
			{
				if (m_current->data == data)
				{
					return true;
				}

				m_current = m_current->next;
			}
		}

		return false;
	}

	// Returns the number of nodes with data 
	unsigned int FindRange(T data)
	{
		std::cout << std::endl;

		if (m_head == nullptr)
		{
			std::cout << "No nodes in list, cannot find range" << std::endl;
			return 0;
		}
		else
		{
			unsigned int count = 0;
			m_current = m_head;

			while (m_current != nullptr)
			{
				if (m_current->data == data)
				{
					count++;
				}

				m_current = m_current->next;
			}

			return count;
		}		
	}

	// Returns the number of nodes in the list
	unsigned int Size()
	{
		if (m_head == nullptr)
		{
			return 0;
		}
		else
		{
			unsigned int count = 0;
			m_current = m_head;

			while (m_current != nullptr)
			{
				count++;

				m_current = m_current->next;
			}

			return count;
		}		
	}	
};