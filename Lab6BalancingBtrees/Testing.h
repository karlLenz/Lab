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

	std::cout << "\nВремя вставки  в AvlTree: ";
	TestFunction(avlTree, &Avl::Add, elementCount);
	std::cout << "\nВремя удаления добавленых элементов из AvlTree: ";
	TestFunction(avlTree, &Avl::Remove, elementCount);
	std::cout << '\n';

	std::cout << "\nВремя вставки  в RedBlackTree: ";
	TestFunction(rbTree, &Rbt::Add, elementCount);
	std::cout << "\nВремя удаления  добавленных элементов из RedBlackTree: ";
	TestFunction(rbTree, &Rbt::Remove, elementCount);
}