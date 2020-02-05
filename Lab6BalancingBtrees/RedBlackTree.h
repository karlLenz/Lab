#pragma once
#include "RedBlackTreeNode.h"
#include <algorithm>
#include <string>

template <class T>
class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();
	void Add(T key) { AddRecursive(_root, key); }
	void Remove(T key) { RemoveRecursive(_root, key); }
	const RbTreeNode<T>* Find(T key) { return FindRecursive(_root, key); }
	size_t GetHeight() { return GetHeightRecursive(_root); }
	void Print() { PrintRecursive(_root, "", false); }

private:
	void DestroyTree(RbTreeNode<T>*);
	void AddRecursive(RbTreeNode<T>*&, T);
	void Balance(RbTreeNode<T>*);
	bool IsLeftChild(RbTreeNode<T>*);
	void Recolor(RbTreeNode<T>*);
	void LeftRotate(RbTreeNode<T>*);
	void RightRotate(RbTreeNode<T>*);
	void SwapColor(RbTreeNode<T>*, RbTreeNode<T>*);
	RbTreeNode<T>* GetUncle(RbTreeNode<T>*);
	void RemoveRecursive(RbTreeNode<T>*&, T);
	void RemoveNill(RbTreeNode<T>*&);
	RbTreeNode<T>* GetBrother(RbTreeNode<T>*);
	RbTreeNode<T>** FindMinSuccessor(RbTreeNode<T>**);
	RbTreeNode<T>* FindRecursive(RbTreeNode<T>*, T);
	size_t GetHeightRecursive(RbTreeNode<T>*);
	void PrintRecursive(RbTreeNode<T>*, std::string, bool);

	RbTreeNode<T>* _root;
	RbTreeNode<T>* _nil;
};


template <class T>
RedBlackTree<T>::RedBlackTree()
{
	_nil = new RbTreeNode<T>{ nullptr, nullptr, nullptr, true };
	_root = _nil;
}


template <class T>
RedBlackTree<T>::~RedBlackTree()
{
	DestroyTree(_root);
	delete _nil;
}


template <class T>
inline void RedBlackTree<T>::DestroyTree(RbTreeNode<T>* current)
{
	if (current == _nil)
	{
		return;
	}

	DestroyTree(current->Left);
	DestroyTree(current->Right);
	delete current;
}


template <class T>
inline void RedBlackTree<T>::AddRecursive(RbTreeNode<T>*& current, T key)
{
	if (current == _nil)
	{
		current = new RbTreeNode<T>{ _nil, _nil, _nil, false, key };
		return;
	}

	if (key == current->Data)
	{
		return;
	}
	else if (key < current->Data)
	{
		AddRecursive(current->Left, key);
		current->Left->Parent = current;
		Balance(current->Left);
	}
	else
	{
		AddRecursive(current->Right, key);
		current->Right->Parent = current;
		Balance(current->Right);
	}
}


template <class T>
inline void RedBlackTree<T>::Balance(RbTreeNode<T>* node)
{
	if (node->Parent == _nil ||
		node->Parent->Parent == _nil)
	{
		_root->IsBlack = true;
		return;
	}

	if (!node->Parent->IsBlack && !node->IsBlack)
	{
		if (!GetUncle(node)->IsBlack)
		{
			return Recolor(node->Parent->Parent);
		}
		else if (IsLeftChild(node->Parent))
		{
			if (!IsLeftChild(node))
			{
				LeftRotate(node->Parent);
				return RightRotate(node->Parent);
			}
			RightRotate(node->Parent->Parent);
		}
		else
		{
			if (IsLeftChild(node))
			{
				RightRotate(node->Parent);
				return LeftRotate(node->Parent);
			}
			LeftRotate(node->Parent->Parent);
		}
		_root->IsBlack = true;
	}
}


template <class T>
inline bool RedBlackTree<T>::IsLeftChild(RbTreeNode<T>* node)
{
	return (node == node->Parent->Left);
}


template <class T>
inline void RedBlackTree<T>::Recolor(RbTreeNode<T>* grandParent)
{
	grandParent->IsBlack = false;
	grandParent->Left->IsBlack = grandParent->Right->IsBlack = true;
}


template <class T>
inline void RedBlackTree<T>::LeftRotate(RbTreeNode<T>* node)
{
	SwapColor(node, node->Right);
	RbTreeNode<T>* rightChild = node->Right;
	node->Right = rightChild->Left;
	rightChild->Left->Parent = node;
	rightChild->Left = node;
	if (node != _root)
	{
		(IsLeftChild(node)) ?
			node->Parent->Left = rightChild :
			node->Parent->Right = rightChild;
	}
	else
	{
		_root = rightChild;
	}
	rightChild->Parent = node->Parent;
	node->Parent = rightChild;
}


template <class T>
inline void RedBlackTree<T>::RightRotate(RbTreeNode<T>* node)
{
	SwapColor(node, node->Left);
	RbTreeNode<T>* leftChild = node->Left;
	node->Left = leftChild->Right;
	leftChild->Right->Parent = node;
	leftChild->Right = node;
	if (node != _root)
	{
		(IsLeftChild(node)) ?
			node->Parent->Left = leftChild :
			node->Parent->Right = leftChild;
	}
	else
	{
		_root = leftChild;
	}
	leftChild->Parent = node->Parent;
	node->Parent = leftChild;
}


template <class T>
inline void RedBlackTree<T>::SwapColor(RbTreeNode<T>* node1,
	RbTreeNode<T>* node2)
{
	bool color = node1->IsBlack;
	node1->IsBlack = node2->IsBlack;
	node2->IsBlack = color;
}


template <class T>
inline RbTreeNode<T>* RedBlackTree<T>::GetUncle(RbTreeNode<T>* node)
{
	return (node->Parent == node->Parent->Parent->Left) ?
		node->Parent->Parent->Right :
		node->Parent->Parent->Left;
}


template <class T>
inline void RedBlackTree<T>::RemoveRecursive(RbTreeNode<T>*& current, T key)
{
	if (current == _nil)
	{
		return;
	}

	if (key == current->Data)
	{
		RbTreeNode<T>* newSuccessor;
		if (current->Left != _nil && current->Right != _nil)
		{
			RbTreeNode<T>** successor = FindMinSuccessor(&(current->Right));
			current->Data = (*successor)->Data;
			return RemoveRecursive((*successor), (*successor)->Data);
		}
		else if (current->Left != _nil)
		{
			newSuccessor = current->Left;
		}
		else if (current->Right != _nil)
		{
			newSuccessor = current->Right;
		}
		else
		{
			if (current->IsBlack && current != _root)
			{
				return RemoveNill(current);
			}
			delete current;
			current = _nil;
			return;
		}
		newSuccessor->IsBlack = true;
		newSuccessor->Parent = current->Parent;
		delete current;
		current = newSuccessor;
	}
	else if (key < current->Data)
	{
		RemoveRecursive(current->Left, key);
	}
	else
	{
		RemoveRecursive(current->Right, key);
	}
}


template <class T>
inline RbTreeNode<T>** RedBlackTree<T>::FindMinSuccessor(RbTreeNode<T>** node)
{
	RbTreeNode<T>** current = node;
	while ((*current)->Left != _nil)
	{
		current = &((*current)->Left);
	}

	return current;
}


template <class T>
inline void RedBlackTree<T>::RemoveNill(RbTreeNode<T>*& node)
{
	RbTreeNode<T>* brother = GetBrother(node);
	delete node;
	node = _nil;
	if (!brother->IsBlack)
	{
		RbTreeNode<T>* brotherParent = brother->Parent;
		if (IsLeftChild(brother))
		{
			brother = brother->Right;
			RightRotate(brotherParent);
		}
		else
		{
			brother = brother->Left;
			LeftRotate(brotherParent);
		}
	}
	if (brother->Left->IsBlack && brother->Right->IsBlack)
	{
		brother->IsBlack = false;
		brother->Parent->IsBlack = true;
		return;
	}
	if (brother->Right->IsBlack && !brother->Left->IsBlack)
	{
		RightRotate(brother);
		brother = brother->Parent;
	}
	if (!brother->Right->IsBlack)
	{
		brother->Right->IsBlack = true;
		if (IsLeftChild(brother))
		{
			LeftRotate(brother);
			return RightRotate(brother->Parent->Parent);
		}
		LeftRotate(brother->Parent);
	}
}


template <class T>
inline RbTreeNode<T>* RedBlackTree<T>::GetBrother(RbTreeNode<T>* node)
{
	return (node == node->Parent->Left) ?
		node->Parent->Right :
		node->Parent->Left;
}


template <class T>
inline RbTreeNode<T>* RedBlackTree<T>::FindRecursive(RbTreeNode<T>* current,
	T key)
{
	if (current == nullptr)
	{
		return nullptr;
	}

	if (key == current->Data)
	{
		return current;
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
inline size_t RedBlackTree<T>::GetHeightRecursive(RbTreeNode<T>* current)
{
	if (current == _nil)
	{
		return 0;
	}

	return std::max(GetHeightRecursive(current->Left),
		GetHeightRecursive(current->Right)) + 1;
}


template <class T>
void RedBlackTree<T>::PrintRecursive(RbTreeNode<T>* current,
	std::string prefix, bool isRight)
{
	if (current != _nil)
	{
		std::cout << prefix;
		std::cout << "|___";
		std::cout << (current->IsBlack ? "Черный " : "Красный ")
			<< current->Data << '\n';

		PrintRecursive(current->Right,
			prefix + (isRight ? "|\t" : " \t"), true);
		PrintRecursive(current->Left,
			prefix + (isRight ? "|\t" : " \t"), false);
	}
}