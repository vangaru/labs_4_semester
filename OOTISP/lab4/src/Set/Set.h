#pragma once

#include "Tree.h"
#include <initializer_list>

template <class T>
class Set
{
private:
	Tree<T>* tree;
	int length;
	void insertIfDoesNotExist(T data);
	void eraseIfExists(T data);

public:
	Set(std::initializer_list<T> elements);
	Set(const Set<T>& other);
	Set();
	~Set();
	void insert(T element);
	void erase(T element);
	void clear();
	int size();
	bool operator > (T data);
	bool operator < (Set<T>& other);
	void operator = (std::initializer_list<T> elements);
	Set<T>& operator = (Set<T>& other);
	bool hasNext();
	T next();
	void toStart();
};

template<class T>
Set<T>::Set(const Set<T>& other)
{
	clear();
}

template<class T>
Set<T>::Set(std::initializer_list<T> elements)
{
	tree = new Tree<T>();
	length = 0;
	this->operator=(elements);
}

template<class T>
Set<T>::Set()
{
	tree = new Tree<T>();
	length = 0;
}

template<class T>
bool Set<T>::operator < (Set<T>& other)
{
	while (other.hasNext())
	{
		if (!(this->operator>(other.next())))
		{
			return false;
		}
	}
	other.toStart();
	return true;
}

template<class T>
bool Set<T>::operator > (T data)
{
	return tree->inTree(data);
}

template<class T>
void Set<T>::operator = (std::initializer_list<T> elements)
{
	for (auto element : elements)
	{
		insertIfDoesNotExist(element);
	}
}

template<class T>
typename Set<T>& Set<T>::operator = (Set<T>& other)
{
	if (this == &other)
	{
		return *this;
	}
	while (other.hasNext())
	{
		insert(other.next());
	}
	other.toStart();
	return *this;
}

template<class T>
void Set<T>::insert(T data)
{
	insertIfDoesNotExist(data);
}

template<class T>
void Set<T>::insertIfDoesNotExist(T data)
{
	if (!this->operator>(data))
	{
		tree->insert(data);
		length++;
	}
}

template<class T>
void Set<T>::clear()
{
	while (hasNext())
	{
		erase(next());
	}
	toStart();
	length = 0;
}

template<class T>
void Set<T>::erase(T data)
{
	eraseIfExists(data);
}

template<class T>
void Set<T>::eraseIfExists(T data)
{
	if (this->operator>(data))
	{
		tree->remove(data);
		length--;
	}
}

template<class T>
int Set<T>::size()
{
	return length;
}

template<class T>
bool Set<T>::hasNext()
{
	return tree->hasNext();
}

template<class T>
T Set<T>::next()
{
	return tree->next();
}

template<class T>
void Set<T>::toStart()
{
	tree->toStart();
}

template<class T>
Set<T>::~Set()
{
	delete tree;
}
