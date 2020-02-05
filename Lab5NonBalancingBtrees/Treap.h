#pragma once
#include "TreapNode.h"
#include <algorithm>

template <class T>
class Treap
{
public:
	~Treap();
	void AddNonOptimized(T);
	void AddOptimized(T key) { AddRecursive(key, GetPriority(), _root); }
	void RemoveNonOptimized(T);
	void RemoveOptimized(T key) { RemoveRecursive(key, _root); }
	bool Find(T key) { return FindRecursive(key, _root); }
	size_t GetHeight() { return GetHeightRecursive(_root); }
	void Print() { PrintRecursive(_root, "", false); }

private:
	void DestroyTreap(TreapNode<T>*);
	void Split(T, TreapNode<T>*, TreapNode<T>*&, TreapNode<T>*&);
	TreapNode<T>* Merge(TreapNode<T>*, TreapNode<T>*);
	void AddRecursive(T, T, TreapNode<T>*&);
	void RemoveRecursive(T, TreapNode<T>*&);
	bool FindRecursive(T, TreapNode<T>*);
	size_t GetHeightRecursive(TreapNode<T>*);
	void PrintRecursive(TreapNode<T>*, std::string, bool);

	T GetPriority() { return rand(); }

	TreapNode<T>* _root;
};


template <class T>
Treap<T>::~Treap()
{
	DestroyTreap(_root);
	_root = nullptr;
}


template <class T>
inline void Treap<T>::DestroyTreap(TreapNode<T>* current)
{
	if (current == nullptr)
	{
		return;
	}

	DestroyTreap(current->Left);
	DestroyTreap(current->Right);
	delete current;
}


template <class T>
inline void Treap<T>::Split(T key, TreapNode<T>* current,
	TreapNode<T>*& left, TreapNode<T>*& right)
{
	if (current == nullptr)
	{
		left = right = nullptr;
		return;
	}

	if (key < current->Key)
	{
		Split(key, current->Left, left, current->Left);
		right = current;
	}
	else
	{
		Split(key, current->Right, current->Right, right);
		left = current;
	}
}


template <class T>
inline TreapNode<T>* Treap<T>::Merge(TreapNode<T>* left,
	TreapNode<T>* right)
{
	if (left == nullptr)
	{
		return right;
	}
	if (right == nullptr)
	{
		return left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}


template <class T>
inline void Treap<T>::AddNonOptimized(T key)
{
	TreapNode<T>* left;
	TreapNode<T>* right;
	Split(key, _root, left, right);
	TreapNode<T>* newTree = new TreapNode<T>{ nullptr, nullptr, key,
		GetPriority() };
	_root = Merge(Merge(left, newTree), right);
}


template <class T>
inline void Treap<T>::AddRecursive(T key, T priority,
	TreapNode<T>*& current)
{
	if (current == nullptr)
	{
		current = new TreapNode<T>{ nullptr, nullptr, key, GetPriority() };
		return;
	}
	
	if (priority >= current->Priority)
	{
		TreapNode<T>* left;
		TreapNode<T>* right;
		Split(key, current, left, right);
		TreapNode<T>* newTree = new TreapNode<T>{ left, right,
			key, priority };
		current = newTree;
	}
	else if (key < current->Key)
	{
		AddRecursive(key, priority, current->Left);
	}
	else
	{
		AddRecursive(key, priority, current->Right);
	}
}


template <class T>
inline void Treap<T>::RemoveNonOptimized(T key)
{
	TreapNode<T>* left;
	TreapNode<T>* right;
	Split(key, _root, left, right);
	TreapNode<T>* destroyedTree;
	Split(key - 1, left, left, destroyedTree);

	if (destroyedTree == nullptr)
	{
		return;
	}
	DestroyTreap(destroyedTree);
	_root = Merge(left, right);
}


template <class T>
inline void Treap<T>::RemoveRecursive(T key, TreapNode<T>*& current)
{
	if (current == nullptr)
	{
		return;
	}
	
	if (key == current->Key)
	{
		TreapNode<T>* destroyedNode = current;
		current = Merge(current->Left, current->Right);
		delete destroyedNode;
	}
	else if (key < current->Key)
	{
		RemoveRecursive(key, current->Left);
	}
	else
	{
		RemoveRecursive(key, current->Right);
	}
}


template <class T>
inline bool Treap<T>::FindRecursive(T key, TreapNode<T>* current)
{
	if (current == nullptr)
	{
		return false;
	}

	if (key == current->Key)
	{
		return true;
	}
	else if (key < current->Key)
	{
		return FindRecursive(key, current->Left);
	}
	else
	{
		return FindRecursive(key, current->Right);
	}
}


template <class T>
inline size_t Treap<T>::GetHeightRecursive(TreapNode<T>* current)
{
	if (current == nullptr)
	{
		return 0;
	}

	return std::max(GetHeightRecursive(current->Left),
		GetHeightRecursive(current->Right)) + 1;
}


template <class T>
inline void Treap<T>::PrintRecursive(TreapNode<T>* current,
	std::string prefix, bool isLeft)
{
	if (current != nullptr)
	{
		std::cout << prefix;
		std::cout << "|_______";
		std::cout << current->Key << "; " << current->Priority << "\n|";

		PrintRecursive(current->Right,
			prefix + (isLeft ? "|\t    " : "\t    "), true);
		PrintRecursive(current->Left,
			prefix + (isLeft ? "|\t    " : "\t    "), false);
	}
}