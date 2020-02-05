#pragma once

template <typename T>
class RbTreeNode
{
public:
	RbTreeNode<T>* Left;
	RbTreeNode<T>* Right;
	RbTreeNode<T>* Parent;
	bool IsBlack;
	T Data;
};