#pragma once

#include <stack>

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

	class TreeIterator
	{
	private:
		std::stack<T> nodes;
		void fillUpNodes(Node* node)
		{
			if (node == nullptr)
			{
				return;
			}
			fillUpNodes(node->right);
			nodes.push(node->data);
			fillUpNodes(node->left);
		}

	public:
		TreeIterator(Node* node)
		{
			fillUpNodes(node);
		}
		bool hasNext()
		{
			if (nodes.size() > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		T next()
		{
			T returnData = nodes.top();
			nodes.pop();
			return returnData;
		}
	};

	TreeIterator* treeIterator;

	Node* makeNodeEmpty(Node* node);
	Node* insert(T data, Node* node);
	Node* getNodeWithMinData(Node* node);
	Node* getNodeWithMaxData(Node* node);
	Node* remove(T data, Node* node);
	bool inTree(T data, Node* node);

public:
	Tree();
	~Tree();
	void insert(T data);
	void remove(T data);
	bool inTree(T data);
	bool hasNext();
	T next();
};

template<class T>
Tree<T>::Tree()
{
	root = nullptr;
	treeIterator = nullptr;
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
	treeIterator = new TreeIterator(root);
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
	treeIterator = new TreeIterator(root);
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
bool Tree<T>::hasNext()
{
	return treeIterator->hasNext();
}

template<class T>
T Tree<T>::next()
{
	return treeIterator->next();
}
