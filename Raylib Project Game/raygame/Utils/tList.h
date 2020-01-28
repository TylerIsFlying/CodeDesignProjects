#pragma once
#include <iostream>
#include <cassert>
template<typename type>
class tList
{
	struct Node
	{
		type data;                     // data for the element stored
		Node * next;                // pointer to node following this node
		Node * back; // pointer to the backwards node
	};

private:
	// Variables
	Node * head; // pointer to head of linked list
	Node * tail; // pointer to tail of the linked list
	void push_blank();  // pushes a node thats has more "blank details"
	void linkTail(); // just makes sure the tail has the correct back
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
		iterator& operator--();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator--(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)


	};

	// Variables
	iterator begin(); // returns a iterator that starts at the head
	iterator end(); // returns a iterator that ends at the tail
	const iterator begin()const; // returns a iterator that starts at the head
	const iterator end() const; // returns a iterator that ends at the tail
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
	void push_back(const type& val);   // adds element to back (i.e. before back)
	void pop_back();                // removes element from back
	int size(); // returns the size of the nodes

	void remove(const type& val);      // removes all elements equal to the given value
	//Operators
	tList& operator=(const tList &rhs);   // copy-assignment
	// Destructer and Constructer
	tList(const tList& other);            // copy-constructor
	tList();
	~tList();
};

template<typename type>
inline void tList<type>::push_blank()
{
	if (head == nullptr)
	{
		head = new Node;
		tail = head;
		head->back = nullptr;
		totalNodes++;
	}
	else
	{
		Node *tmp = new Node;
		tmp->next = nullptr;
		tmp->back = tail;
		tail->next = tmp;
		tail = tmp;
		totalNodes++;
	}
}

template<typename type>
inline void tList<type>::linkTail()
{
	Node *last = head;
	head->back = nullptr;
	Node* curr = head;
	for (size_t i = 0; i < totalNodes; ++i)
	{
		tail = curr;
		if (tail != head)
			tail->back = last;
		last = curr;
		if (curr->next != nullptr)
			curr = curr->next;
		else
			break;
	}
}

template<typename type>
typename inline tList<type>::iterator tList<type>::begin()
{
	return iterator(head);
}
template<typename type>
typename inline tList<type>::iterator tList<type>::end()
{
	return iterator(tail);
}
template<typename type>
typename inline const tList<type>::iterator tList<type>::begin() const
{
	return iterator(head);
}
template<typename type>
typename inline const tList<type>::iterator tList<type>::end() const
{
	return iterator(tail);
}
template<typename type>
inline void tList<type>::push_front(const type & val)
{
	if (head == nullptr)
	{
		head = new Node;
		head->data = val;
		tail = head;
		tail->back = nullptr;
		head->back = nullptr;
		head->next = nullptr;
		tail->next = nullptr;
		totalNodes++;
	}else
	{
		Node *tmp = new Node;
		tmp->data = val;
		tmp->next = head;
		if (tail == head)
		{
			tail->next = nullptr;
			tail->back = tmp;
		}
		head = tmp;
		totalNodes++;
	}
	linkTail();
}

template<typename type>
inline void tList<type>::pop_front()
{
	if(head != nullptr && totalNodes > 1)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
		if(head != nullptr)
			head->back = nullptr;
	}else
	{
		head = nullptr;
		tail = nullptr;
	}
	totalNodes--;
}

template<typename type>
inline bool tList<type>::empty() const
{
	if (totalNodes == 0)
		return true;
	else
		return false;
}

template<typename type>
inline void tList<type>::clear()
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
inline void tList<type>::resize(size_t newSize)
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
inline type & tList<type>::front()
{
	assert(head != nullptr);
	return head->data;
}

template<typename type>
inline const type & tList<type>::front() const
{
	assert(head != nullptr);
	return head->data;
}

template<typename type>
inline type & tList<type>::back()
{
	assert(head != nullptr);
	return tail->data;
}

template<typename type>
inline const type & tList<type>::back() const
{
	assert(head != nullptr);
	return tail->data;
}

template<typename type>
inline void tList<type>::push_back(const type & val)
{
	if (head == nullptr)
	{
		head = new Node;
		head->data = val;
		tail = head;
		tail->back = nullptr;
		head->back = nullptr;
		head->next = nullptr;
		tail->next = nullptr;
		totalNodes++;
	}
	else
	{
		Node *tmp = new Node;
		tmp->data = val;
		tmp->next = nullptr;
		tmp->back = tail;
		tail->next = tmp;
		tail = tmp;
		totalNodes++;
	}
	linkTail();
}

template<typename type>
inline void tList<type>::pop_back()
{
	if (head != nullptr && totalNodes > 1)
	{
		Node *tmp = tail->back;
		delete tail;
		tail = tmp;
		tail->next = nullptr;
		totalNodes--;
	}else
	{
		head = nullptr;
		tail = nullptr;
	}
}

template<typename type>
inline int tList<type>::size()
{
	return totalNodes;
}

template<typename type>
inline void tList<type>::remove(const type & val)
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
					if (tmp != nullptr)
						tmp->back = pastNode;
					currNode = tmp;
					if (pastNode->next == nullptr)
						tail = pastNode;
					totalNodes--;
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
inline tList<type> & tList<type>::operator=(const tList & rhs)
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
inline tList<type>::tList(const tList & other)
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
inline tList<type>::tList()
{
	head = nullptr;
	tail = nullptr;
	totalNodes = 0;
}

template<typename type>
inline tList<type>::~tList()
{
	delete head;
	delete tail;
}

template<typename type>
inline tList<type>::iterator::iterator()
{
	cur = nullptr;
}

template<typename type>
inline tList<type>::iterator::iterator(Node * startNode)
{
	cur = startNode;
}


template<typename type>
inline bool tList<type>::iterator::operator==(const iterator & rhs) const
{
	if (rhs.cur == cur)
		return true;
	else
		return false;
}

template<typename type>
inline bool tList<type>::iterator::operator!=(const iterator & rhs) const
{
	if (rhs.cur != cur)
		return true;
	else
		return false;
}

template<typename type>
inline type & tList<type>::iterator::operator*() const
{
	return cur->data;
}

template<typename type>
typename tList<type>::iterator & tList<type>::iterator::operator++()
{
	if (cur != nullptr)
		cur = cur->next;

	return *this;
}

template<typename type>
typename inline tList<type>::iterator tList<type>::iterator::operator++(int)
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

template<typename type>
typename inline tList<type>::iterator & tList<type>::iterator::operator--()
{
	if (cur != nullptr)
		cur = cur->back;

	return *this;
}

template<typename type>
typename inline tList<type>::iterator tList<type>::iterator::operator--(int)
{
	iterator t;
	if (cur != nullptr)
	{
		Node * tmp = cur;
		cur = cur->back;
		t.cur = tmp;
	}
	return t;
}

