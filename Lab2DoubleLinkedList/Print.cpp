#include "Print.h"
#include <iostream>

void PrintList(const List* list)
{
	Node *current = list->Head;
	while (current != nullptr)
	{
		std::cout << ' ' << current->Data;
		current = current->Next;
	}
}


void PrintMenu()
{
	std::cout << "\n\t0 ���������� �������� � ������.\n" <<
		"\t1 �������� �������� �� ������.\n" <<
		"\t2 ������� �������� � ������ ������.\n" <<
		"\t3 ������� �������� � ����� ������.\n" <<
		"\t4 ������� ����� ������������� ��������.\n" <<
		"\t5 ������� ����� ������������ ���������.\n" <<
		"\t6 ���������� ������.\n" <<
		"\t7 ������� ����� �������� � ������.\n" <<
		"\t8 ����� �� ��������.\n";
}