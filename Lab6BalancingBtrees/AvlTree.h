#pragma once
#include "AvlTreeNode.h"
#include <string>

template <class T>
class AvlTree
{
public:
	AvlTree() : _root(nullptr) {}
	~AvlTree() { DestroyTree(_root); }
	void Add(T key) { AddRecursive(_root, key); }
	void Remove(T key) { RemoveRecursive(_root, key); }
	bool Find(T key) { return FindRecursive(_root, key); }
	size_t GetHeight() { return GetNodeHeight(_root); }
	void Print() { PrintRecursive(_root, "", false); }

private:
	void DestroyTree(AvlTreeNode<T>*);
	void AddRecursive(AvlTreeNode<T>*&, T);
	void Balance(AvlTreeNode<T>*&);
	short GetNodeHeight(AvlTreeNode<T>*);
	short GetBalanceFactor(AvlTreeNode<T>*);
	void FixHeight(AvlTreeNode<T>*);
	void LeftRotate(AvlTreeNode<T>*&);
	void RightRotate(AvlTreeNode<T>*&);
	void RemoveRecursive(AvlTreeNode<T>*&, T);
	AvlTreeNode<T>* GetSuccessor(AvlTreeNode<T>*);
	AvlTreeNode<T>* FindMinSuccessor(AvlTreeNode<T>*&);
	bool FindRecursive(AvlTreeNode<T>*, T);
	void PrintRecursive(AvlTreeNode<T>*, std::string, bool);

	AvlTreeNode<T>* _root;
};


template <class T>
inline void AvlTree<T>::DestroyTree(AvlTreeNode<T>* current)
{
	if (current == nullptr)
	{
		return;
	}

	DestroyTree(current->Left);
	DestroyTree(current->Right);
	delete current;
}


template <class T>
inline void AvlTree<T>::AddRecursive(AvlTreeNode<T>*& current, T key)
{
	if (current == nullptr)
	{
		current = new AvlTreeNode<T>{ nullptr, nullptr, 1, key };
		return;
	}

	if (key == current->Data)
	{
		return;
	}
	else if (key < current->Data)
	{
		AddRecursive(current->Left, key);
	}
	else
	{
		AddRecursive(current->Right, key);
	}
	Balance(current);
}


template <class T>
inline void AvlTree<T>::Balance(AvlTreeNode<T>*& node)
{
	FixHeight(node);
	if (GetBalanceFactor(node) == -2)
	{
		if (GetBalanceFactor(node->Left) > 0)
		{
			LeftRotate(node->Left);
		}
		RightRotate(node);
	}
	else if (GetBalanceFactor(node) == 2)
	{
		if (GetBalanceFactor(node->Right) < 0)
		{
			RightRotate(node->Right);
		}
		LeftRotate(node);
	}
}


template <class T>
inline short AvlTree<T>::GetNodeHeight(AvlTreeNode<T>* node)
{
	return (node == nullptr) ? 0 : node->Height;
}


template <class T>
inline short AvlTree<T>::GetBalanceFactor(AvlTreeNode<T>* node)
{
	return (GetNodeHeight(node->Right) -
		GetNodeHeight(node->Left));
}


template <class T>
inline void AvlTree<T>::FixHeight(AvlTreeNode<T>* node)
{
	short leftChildHeight = GetNodeHeight(node->Left);
	short rightChildHeight = GetNodeHeight(node->Right);

	node->Height = ((leftChildHeight > rightChildHeight) ?
		leftChildHeight :
		rightChildHeight) + 1;
}


template <class T>
inline void AvlTree<T>::LeftRotate(AvlTreeNode<T>*& node)
{
	AvlTreeNode<T>* rightChild = node->Right;
	node->Right = rightChild->Left;
	rightChild->Left = node;
	node = rightChild;
	FixHeight(node->Left);
	FixHeight(node);
}


template <class T>
inline void AvlTree<T>::RightRotate(AvlTreeNode<T>*& node)
{
	AvlTreeNode<T>* leftChild = node->Left;
	node->Left = leftChild->Right;
	leftChild->Right = node;
	node = leftChild;
	FixHeight(node->Right);
	FixHeight(node);
}


template <class T>
inline void AvlTree<T>::RemoveRecursive(AvlTreeNode<T>*& current, T key)
{
	if (current == nullptr)
	{
		return;
	}

	if (key == current->Data)
	{
		AvlTreeNode<T>* newSuccessor = GetSuccessor(current);
		delete current;
		current = newSuccessor;
		return;
	}
	else if (key < current->Data)
	{
		RemoveRecursive(current->Left, key);
	}
	else
	{
		RemoveRecursive(current->Right, key);
	}
	Balance(current);
}


template <class T>
inline AvlTreeNode<T>* AvlTree<T>::GetSuccessor(AvlTreeNode<T>* current)
{
	AvlTreeNode<T>* newSuccessor = nullptr;
	if (current->Left != nullptr && current->Right != nullptr)
	{
		newSuccessor = FindMinSuccessor(current->Right);
		newSuccessor->Left = current->Left;
		newSuccessor->Right = current->Right;
	}
	else if (current->Left != nullptr)
	{
		newSuccessor = current->Left;
	}
	else if (current->Right != nullptr)
	{
		newSuccessor = current->Right;
	}

	return newSuccessor;
}


template <class T>
inline AvlTreeNode<T>* AvlTree<T>::FindMinSuccessor(
	AvlTreeNode<T>*& current)
{
	if (current->Left == nullptr)
	{
		AvlTreeNode<T>* findedNode = current;
		current = current->Right;
		return findedNode;
	}
	AvlTreeNode<T>* temporary = FindMinSuccessor(current->Left);
	Balance(current);

	return temporary;
}


template <class T>
inline bool AvlTree<T>::FindRecursive(
	AvlTreeNode<T>* current, T key)
{
	if (current == nullptr)
	{
		return false;
	}

	if (key == current->Data)
	{
		return true;
	}
	else if (key < current->Data)
	{
		return FindRecursive(current->Left, key);
	}
	else
	{
		return FindRecursive(current->Right, key);
	}
}


template <class T>
inline void AvlTree<T>::PrintRecursive(AvlTreeNode<T>* current,
	std::string prefix, bool isRight)
{
	if (current != nullptr)
	{
		std::cout << prefix;
		std::cout << "|___";
		std::cout << '(' << GetBalanceFactor(current) << ") " <<
			current->Data << '\n';

		PrintRecursive(current->Right,
			prefix + (isRight ? "|\t" : " \t"), true);
		PrintRecursive(current->Left,
			prefix + (isRight ? "|\t" : " \t"), false);
	}
}