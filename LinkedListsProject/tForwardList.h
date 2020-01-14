#pragma once
#include <iostream>
#include <cassert>
template<typename type>
class tForwardList
{
	struct Node
	{
		type data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

private:
	// Variables
	Node * head; // pointer to head of linked list
	Node * tail; // pointer to tail of the linked list
	void push_blank();  // pushes a node thats has more "blank details"
	int totalNodes;
public:
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();                                 // initializes an empty iterator pointing to null
		iterator(Node * startNode);                 // initializes an iterator pointing to the given node

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		type& operator*() const;                       // returns a reference to the element pointed to by the current node

		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)

	};

	// Variables
	iterator begin();
	iterator end();
	//Functions
	void push_front(const type& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front
	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements. New elements are default-initialized
	type& front();                     // returns the element at the head
	const type& front() const;         // returns the element at the head (const)
	type& back();                     // returns the element at the head
	const type& back() const;         // returns the element at the head (const)

	void remove(const type& val);      // removes all elements equal to the given value
	//Operators
	tForwardList& operator=(const tForwardList &rhs);   // copy-assignment
	// Destructer and Constructer
	tForwardList(const tForwardList& other);            // copy-constructor
	tForwardList();
	~tForwardList();
};

template<typename type>
inline void tForwardList<type>::push_blank()
{
	if (head == nullptr)
	{
		head = new Node;
		tail = head;
		totalNodes++;
	}
	else
	{
		Node *tmp = new Node;
		tmp->next = nullptr;
		tail->next = tmp;
		tail = tmp;
		totalNodes++;
	}
}

template<typename type>
typename inline tForwardList<type>::iterator tForwardList<type>::begin()
{
	return iterator(head);
}
template<typename type>
typename inline tForwardList<type>::iterator tForwardList<type>::end()
{
	return iterator(nullptr);
}
template<typename type>
inline void tForwardList<type>::push_front(const type & val)
{
	if (head == nullptr)
	{
		head = new Node;
		head->data = val;
		tail = head;
		totalNodes++;
	}else
	{
		Node *tmp = new Node;
		tmp->data = val;
		tmp->next = nullptr;
		tail->next = tmp;
		tail = tmp;
		totalNodes++;
	}

}

template<typename type>
inline void tForwardList<type>::pop_front()
{
	if(head != nullptr)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
		totalNodes--;
	}
}

template<typename type>
inline bool tForwardList<type>::empty() const
{
	if (totalNodes == 0)
		return true;
	else
		return false;
}

template<typename type>
inline void tForwardList<type>::clear()
{
	if(totalNodes > 0)
	{
		int currentCount = totalNodes;
		Node *currNode = head;
		for (size_t i = 0; i < currentCount; ++i)
		{
			if (currNode != nullptr)
			{
				Node * tmp = currNode;
				currNode = currNode->next;
				//std::cout << "Nodes Deleted: " << tmp->data << std::endl;
				delete tmp;
				totalNodes--;
			}
		}
		head = nullptr;
		tail = nullptr;
	}
}

template<typename type>
inline void tForwardList<type>::resize(size_t newSize)
{
	Node * currNode = head;
	int currTotal = totalNodes;
	int size = newSize;
	Node * past = nullptr;
	//std::cout << currTotal - 1 << std::endl;
	if(size < currTotal)
	{
		for (size_t i = 0; i < currTotal; ++i)
		{
			if(currNode != nullptr)
			{
				Node * tmp = currNode->next;
				if(i > newSize-1)
				{
					delete currNode;
					currNode = nullptr;
					past->next = nullptr;
					totalNodes--;
				}
				if(currNode != nullptr)
					past = currNode;
				currNode = tmp;
			}
		}
		tail = past;
	}else
	{
		Node * currNode = head;
		for (size_t i = 0; i < newSize; ++i)
		{
			if(i >= currTotal)
			{
				push_blank();
				totalNodes++;
			}
			if (currNode->next != nullptr)
				currNode = currNode->next;
			tail = currNode;
		}
	}
}

template<typename type>
inline type & tForwardList<type>::front()
{
	assert(head != nullptr);
	return head->data;
}

template<typename type>
inline const type & tForwardList<type>::front() const
{
	assert(head != nullptr);
	return head->data;
}

template<typename type>
inline type & tForwardList<type>::back()
{
	assert(head != nullptr);
	return tail->data;
}

template<typename type>
inline const type & tForwardList<type>::back() const
{
	assert(head != nullptr);
	return tail->data;
}

template<typename type>
inline void tForwardList<type>::remove(const type & val)
{
	if(head != nullptr)
	{
		Node *currNode = head;
		Node *pastNode = nullptr;
		int counter = totalNodes;
		for(size_t i = 0; i < counter; ++i)
		{
			if(currNode->data != val)
			{
				pastNode = currNode;
				//std::cout << pastNode->data << std::endl;
			}else
			{
				if(pastNode != nullptr)
				{
					Node *tmp = currNode->next;
					delete currNode;
					pastNode->next = tmp;
					currNode = tmp;
					if (pastNode->next == nullptr)
						tail = pastNode;
					continue;
				}else
				{
					currNode = currNode->next;
					pop_front();
					continue;
				}
				totalNodes--;
			}
			currNode = currNode->next;
		}
	}
}

template<typename type>
inline tForwardList<type> & tForwardList<type>::operator=(const tForwardList & rhs)
{
	clear();
	head = new Node;
	totalNodes = rhs.totalNodes;
	Node * currNode = head;
	Node * rhsNode = rhs.head;
	for (size_t i = 0; i < totalNodes; ++i)
	{
		if (currNode != nullptr)
		{
			*currNode = *rhsNode;
			tail = currNode;
			if (rhsNode->next != nullptr)
			{
				currNode->next = new Node;
				*currNode->next = *rhsNode->next;
			}
			currNode = currNode->next;
			rhsNode = rhsNode->next;
		}
	}
	return *this;
}

template<typename type>
inline tForwardList<type>::tForwardList(const tForwardList & other)
{
	head = new Node;
	totalNodes = other.totalNodes;
	Node * currNode = head;
	Node * rhsNode = other.head;
	for (size_t i = 0; i < totalNodes; ++i)
	{
		if (currNode != nullptr)
		{
			*currNode = *rhsNode;
			tail = currNode;
			if (rhsNode->next != nullptr)
			{
				currNode->next = new Node;
				*currNode->next = *rhsNode->next;
			}
			currNode = currNode->next;
			rhsNode = rhsNode->next;
		}
	}
}

template<typename type>
inline tForwardList<type>::tForwardList()
{
	head = nullptr;
	tail = nullptr;
	totalNodes = 0;
}

template<typename type>
inline tForwardList<type>::~tForwardList()
{
	assert(false && "TODO: tForwardList<T>::~tForwardList<T>()");
}

template<typename type>
inline tForwardList<type>::iterator::iterator()
{
	cur = nullptr;
}

template<typename type>
inline tForwardList<type>::iterator::iterator(Node * startNode)
{
	cur = startNode;
}

template<typename type>
inline bool tForwardList<type>::iterator::operator==(const iterator & rhs) const
{
	if (rhs.cur == cur)
		return true;
	else
		return false;
}

template<typename type>
inline bool tForwardList<type>::iterator::operator!=(const iterator & rhs) const
{
	if (rhs.cur != cur)
		return true;
	else
		return false;
}

template<typename type>
inline type & tForwardList<type>::iterator::operator*() const
{
	return cur->data;
}

template<typename type>
typename tForwardList<type>::iterator & tForwardList<type>::iterator::operator++()
{
	if (cur != nullptr)
		cur = cur->next;

	return *this;
}

template<typename type>
typename inline tForwardList<type>::iterator tForwardList<type>::iterator::operator++(int)
{
	iterator t;
	if (cur != nullptr)
	{
		Node * tmp = cur;
		cur = cur->next;
		t.cur = tmp;
	}
	return t;
}
