#ifndef __LINKEDLIST__
#define __LINKEDLIST__
#include <iostream>
using namespace std;

template <class T>
class Node{
public:
	T data;
	Node *link;
	Node(T element)
	{
		data = element;
		link = NULL;
    }
};

template <class T>
class LinkedList
{
protected:
	Node<T> *first;
	int current_size;

public:
	LinkedList()
	{
		first = 0;
		current_size = 0;
	};
	int GetSize() { return current_size; };
	void Insert(T element);
	virtual bool Delete(T &element);
	void Print();
};

template <typename T>
void LinkedList<T>::Insert(T element)
{
	Node<T> *newnode = new Node<T>(element);
	newnode->link = first;
	first = newnode;
	current_size++;
}

template <typename T>
bool LinkedList<T>::Delete(T &element)
{
	if (first == 0)
		return false;
	
	Node<T> *current = first;
	Node<T> *previous = NULL;
	
	while (1)
	{
		if (current->link == 0) // find end node
		{
			if(previous) previous->link = current->link;
			else first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	
	element = current->data;
	delete current;

	current_size--;
	
	return true;
}

template <typename T>
void LinkedList<T>::Print()
{
	if (current_size == 0) {
		cout<<"비어있습니다"<<endl;

		return;
	}

	Node<T> *current = first;
	int i = 0;
	for ( i = 0; i < current_size - 1; i++) {
		cout<<"["<<i+1<<"|"<<current->data<<"]->";
		current = current->link;
	}
	cout<<"["<<i+1<<"|"<<current->data<<"]"<<endl;
}

#endif
