#include "Check.h"
#include <exception>


void IsEmpty(const List* list)
{
	if (list == nullptr || list->Head == nullptr)
	{
		throw std::exception("������ ����!");
	}
}


void IsSorted(const List* list)
{
	if (list->Size < 2)
	{
		throw std::exception("������ ������������!");
	}
	else if (list->IsSorted)
	{
		throw std::exception("������ ������������!");
	}
}