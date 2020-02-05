#pragma once
#include "AvlTree.h"
#include "RedBlackTree.h"

#include <iostream>
#include "../Timer.h"


template <typename T, typename DATA_TYPE>
void TestFunction(T& tree, void (T::*TestingFunction)(DATA_TYPE),
	size_t size)
{
	Timer duration;
	for (size_t i = 0; i < size; ++i)
	{
		(tree.*TestingFunction)(i);
	}
}

void Testing(size_t elementCount)
{
	AvlTree<short> avlTree;
	RedBlackTree<short> rbTree;
	using Avl = AvlTree<short>;
	using Rbt = RedBlackTree<short>;

	std::cout << "\n����� �������  � AvlTree: ";
	TestFunction(avlTree, &Avl::Add, elementCount);
	std::cout << "\n����� �������� ���������� ��������� �� AvlTree: ";
	TestFunction(avlTree, &Avl::Remove, elementCount);
	std::cout << '\n';

	std::cout << "\n����� �������  � RedBlackTree: ";
	TestFunction(rbTree, &Rbt::Add, elementCount);
	std::cout << "\n����� ��������  ����������� ��������� �� RedBlackTree: ";
	TestFunction(rbTree, &Rbt::Remove, elementCount);
}