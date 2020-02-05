#pragma once
#include "Treap.h"
#include "../Timer.h"


template <typename U>
void TestAdding(Treap<U> &treap, void (Treap<U>::*AddFunction)(U),
	size_t elementCount)
{
	Timer time;
	for (size_t i = 0; i < elementCount; ++i)
	{
		(treap.*AddFunction)(static_cast<short>(i));
	}
}


template <typename U>
void TestRemoving(Treap<U> &treap, void (Treap<U>::*RemoveFunction)(U))
{
	short someKey = rand();
	treap.AddOptimized(someKey);
	Timer time;
	(treap.*RemoveFunction)(someKey);
}


void Testing(size_t elementCount)
{
	Treap<short> treap;
	std::cout << "Время неоптимизированной вставки: ";
	TestAdding(treap, &Treap<short>::AddNonOptimized, elementCount);
	std::cout << " (высота дерева = " << treap.GetHeight() << ")\n";
	treap.~Treap();

	std::cout << "Время оптимизированной вставки: ";
	TestAdding(treap, &Treap<short>::AddOptimized, elementCount);
	std::cout << " (высота дерева = " << treap.GetHeight() << ")\n";

	std::cout << "\nВремя неоптимизированного удаления: ";
	TestRemoving(treap, &Treap<short>::RemoveNonOptimized);

	std::cout << "\nВремя оптимизированного удаления: ";
	TestRemoving(treap, &Treap<short>::RemoveOptimized);
}