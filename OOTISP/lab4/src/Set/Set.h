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
	Set();
	~Set();
	void insert(T element);
	void erase(T element);
	int size();
	void display();
	bool operator > (T data);
};

template<class T>
Set<T>::Set()
{
	tree = new Tree<T>();
	length = 0;
}

template<class T>
bool Set<T>::operator > (T data)
{
	return tree->inTree(data);
}

template<class T>
Set<T>::Set(std::initializer_list<T> elements)
{
	tree = new Tree<T>();
	length = 0;
	for (auto element : elements)
	{
		insertIfDoesNotExist(element);
	}
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
void Set<T>::display()
{
	tree->inorder();
}

template<class T>
Set<T>::~Set()
{
	delete tree;
}


