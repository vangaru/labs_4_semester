#pragma once

#include <iostream>

template<class T>
class Tree
{
private:

	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

	Node* root;

	Node* makeNodeEmpty(Node* node);
	Node* insert(T data, Node* node);
	Node* getNodeWithMinData(Node* node);
	Node* getNodeWithMaxData(Node* node);
	Node* remove(T data, Node* node);
	bool inTree(T data, Node* node);
	void inorder(Node* node);

public:
	Tree();
	~Tree();
	void insert(T data);
	void remove(T data);
	bool inTree(T data);
	void inorder();
};

template<class T>
Tree<T>::Tree()
{
	root = nullptr;
}

template<class T>
Tree<T>::~Tree()
{
	root = makeNodeEmpty(root);
}

template<class T>
typename Tree<T>::Node* Tree<T>::makeNodeEmpty(Tree<T>::Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else
	{
		makeNodeEmpty(node->left);
		makeNodeEmpty(node->right);
		delete node;
	}
	return nullptr;
}

template<class T>
void Tree<T>::insert(T data)
{
	root = insert(data, root);
}

template<class T>
typename Tree<T>::Node* Tree<T>::insert(T data, Tree<T>::Node* node)
{
	if (node == nullptr)
	{
		node = new Node;
		node->data = data;
		node->left = nullptr;
		node->right = nullptr;
	}
	else if (data < node->data)
	{
		node->left = insert(data, node->left);
	}
	else if (data > node->data)
	{
		node->right = insert(data, node->right);
	}
	return node;
}

template<class T>
void Tree<T>::remove(T data)
{
	root = remove(data, root);
}

template<class T>
typename Tree<T>::Node* Tree<T>::remove(T data, Tree<T>::Node* node)
{
	Node* temp;
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (data < node->data)
	{
		node->left = remove(data, node->left);
	}
	else if (data > node->data)
	{
		node->right = remove(data, node->right);
	}
	else if (node->left && node->right)
	{
		temp = getNodeWithMinData(node->right);
		node->data = temp->data;
		node->right = remove(node->data, node->right);
	}
	else
	{
		temp = node;
		if (node->left == nullptr)
		{
			node = node->right;
		}
		else if (node->right == nullptr)
		{
			node = node->left;
		}
		delete temp;
	}
	return node;
}

template<class T>
typename Tree<T>::Node* Tree<T>::getNodeWithMinData(Tree<T>::Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (node->left == nullptr)
	{
		return node;
	}
	else
	{
		return getNodeWithMinData(node->left);
	}
}

template<class T>
typename Tree<T>::Node* Tree<T>::getNodeWithMaxData(Tree<T>::Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else if (node->right == nullptr)
	{
		return node;
	}
	else
	{
		return getNodeWithMaxData(node->right);
	}
}

template<class T>
bool Tree<T>::inTree(T data)
{
	return inTree(data, root);
}

template<class T>
bool Tree<T>::inTree(T data, Tree<T>::Node* node)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (data < node->data)
	{
		return inTree(data, node->left);
	}
	else if (data > node->data)
	{
		return inTree(data, node->right);
	}
	else
	{
		return true;
	}
}

template<class T>
void Tree<T>::inorder()
{
	inorder(root);
}

template<class T>
void Tree<T>::inorder(Tree<T>::Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	inorder(node->left);
	std::cout << node->data << std::endl;
	inorder(node->right);
}

