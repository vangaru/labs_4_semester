#pragma once

#include <iostream>

template<class T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void push_front(T data);
	void insert(T data, int index);
	void clear();
	T pop_front();
	T pop_back();
	void removeAt(int index);
	int get_length();

	T& operator[](const int index);

private:
	template<class T>
	class Node 
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int length;
	Node<T>* head;
};

template<class T>
List<T>::List() 
{
	length = 0;
	head = nullptr;
}

template<class T>
List<T>::~List() 
{
	pop_front();
}

template<class T>
void List<T>::push_back(T data) 
{
	if(head == nullptr) 
	{
		head = new Node<T>(data);
	}
	else 
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	length++;
}

template<class T>
void List<T>::push_front(T data) 
{
	if(head == nullptr) 
	{
		head = new Node<T>(data);
	}
	else
	{
		this->head = new Node<T>(data, this->head);
	}

	length++;
}

template<class T>
void List<T>::insert(T data, int index) 
{
	if(index == 0) 
	{
		push_front(data);
	}
	else 
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		length++;
	}
}

template<class T>
T List<T>::pop_front() 
{
	T returnData = head->data;
	Node<T> *temp = head;
	head = head->pNext;
	
	delete temp;
	length--;
	
	return returnData;
}

template<class T>
T List<T>::pop_back()
{
	T returnData = this->operator[](length - 1);
	removeAt(length - 1);
	return returnData;
}

template<class T>
void List<T>::removeAt(int index) 
{
	if(index == 0) 
	{
		pop_front();
	}
	else 
	{
		Node<T>* previous = this->head;
		for(int i = 0; i < index - 1; i++) 
		{
			previous = previous->pNext;
		}
		Node<T>* nodeToDelete = previous->pNext;
		previous->pNext = nodeToDelete->pNext;

		delete nodeToDelete;
		length--;
	}
}

template<class T>
void List<T>::clear() 
{
	while(length > 0) 
	{
		pop_front();
	}
}
 
template<class T>
int List<T>::get_length() 
{
	return length;
}

template<class T>
T& List<T>::operator[](const int index) 
{
	Node<T>* current = this->head;
	int currentIndex = 0;
	while(current != nullptr) 
	{
		if(currentIndex == index) 
		{
			return current->data;
		}
		current = current->pNext;
		currentIndex++;
	}
}


 