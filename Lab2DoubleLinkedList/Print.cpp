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
	std::cout << "\n\t0 Добавление элемента в список.\n" <<
		"\t1 Удаление элемента из списка.\n" <<
		"\t2 Вставка элемента в начало списка.\n" <<
		"\t3 Вставка элемента в конец списка.\n" <<
		"\t4 Вставка после определенного элемента.\n" <<
		"\t5 Вставка перед определенным элементом.\n" <<
		"\t6 Сортировка списка.\n" <<
		"\t7 Линеный поиск элемента в списке.\n" <<
		"\t8 Выход из программ.\n";
}