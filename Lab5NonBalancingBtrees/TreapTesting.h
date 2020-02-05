#pragma once
#include "Treap.h"
#include "../Timer.h"


template <typename U>
void Test(Treap<U> &treap, void (Treap<U>::*TestingFunction)(U),
	size_t elementCount)
{
	Timer time;
	for (size_t i = 0; i < elementCount; ++i)
	{
		(treap.*TestingFunction)(static_cast<short>(i));
	}
}


void Testing(size_t elementCount)
{
	Treap<short> treap;
	std::cout << "Время неоптимизированной вставки: ";
	Test(treap, &Treap<short>::AddNonOptimized, elementCount);
	std::cout << " (высота дерева = " << treap.GetHeight() << ")\n";

	std::cout << "\nВремя неоптимизированного удаления добавленных элементов: ";
	Test(treap, &Treap<short>::RemoveNonOptimized, elementCount);

	std::cout << "Время оптимизированной вставки: ";
	Test(treap, &Treap<short>::AddOptimized, elementCount);
	std::cout << " (высота дерева = " << treap.GetHeight() << ")\n";

	std::cout << "\nВремя оптимизированного удаления добавленных элементов: ";
	Test(treap, &Treap<short>::RemoveOptimized, elementCount);
}