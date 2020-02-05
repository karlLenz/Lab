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
	std::cout << "����� ������������������ �������: ";
	TestAdding(treap, &Treap<short>::AddNonOptimized, elementCount);
	std::cout << " (������ ������ = " << treap.GetHeight() << ")\n";
	treap.~Treap();

	std::cout << "����� ���������������� �������: ";
	TestAdding(treap, &Treap<short>::AddOptimized, elementCount);
	std::cout << " (������ ������ = " << treap.GetHeight() << ")\n";

	std::cout << "\n����� ������������������� ��������: ";
	TestRemoving(treap, &Treap<short>::RemoveNonOptimized);

	std::cout << "\n����� ����������������� ��������: ";
	TestRemoving(treap, &Treap<short>::RemoveOptimized);
}