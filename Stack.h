#ifndef __STACK__
#define __STACK__
#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T>
{
public:
	virtual bool Delete(T &element)
	{
		if (this->current_size == 0)
			return false;

		Node<T> *current = this->first;
		this->first = this->first->link;
		element = current->data;
		delete current;

		this->current_size--;

		return true;
	}
};

#endif
