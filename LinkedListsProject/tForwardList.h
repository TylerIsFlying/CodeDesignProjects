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
	int totalNodes;
public:
	// Variables
	//Functions
	void push_front(const type& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	type& front();                     // returns the element at the head
	const type& front() const;         // returns the element at the head (const)
	type& back();                     // returns the element at the head
	const type& back() const;         // returns the element at the head (const)

	void remove(const type& val);      // removes all elements equal to the given value
	// Destructer and Constructer
	tForwardList();
	~tForwardList();
};

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
				std::cout << pastNode->data << std::endl;
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
inline tForwardList<type>::tForwardList()
{
	head = nullptr;
	tail = nullptr;
	totalNodes = 0;
}

template<typename type>
inline tForwardList<type>::~tForwardList()
{
}
