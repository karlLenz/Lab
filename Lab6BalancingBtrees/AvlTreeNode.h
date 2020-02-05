#pragma once

template <typename T>
class AvlTreeNode
{
public:
	AvlTreeNode* Left;
	AvlTreeNode* Right;
	short Height;
	T Data;
};