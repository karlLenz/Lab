#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	List* list = CreateList();

	while (true)
	{
		system("cls");
		cout << "Количество элементов в списке: " << list->Size << '\n';
		PrintList(list);
		PrintMenu();

		size_t lastElementIndex = list->Size - 1;
		try
		{
			cout << "\nВведите номер команды: ";
			int commandNum = GetValue<int>(COMMAND_ZERO, COMMAND_EIGHTH,
				IsRange);
			switch (commandNum)
			{
				case COMMAND_ZERO:
				{
					std::cout << "Введите значение: ";
					AddNode(list, GetValue<int>());
					break; 
				}
				case COMMAND_FIRST:
				{
					std::cout << "Введите индекс элемента: ";
					DeleteNode(list, GetValue<size_t>(0, list->Size - 1,
						IsRange));
					break;
				}
				case COMMAND_SECOND:
				{
					std::cout << "Введите значение: ";
					InsertNode(list, 0, GetValue<int>());
					break;
				}
				case COMMAND_THIRD:
				{
					InsertNode(list, lastElementIndex, GetValue<int>());
					break;
				}
				case COMMAND_FOURTH:
				{
					IsEmpty(list);
					cout << "Введите индекс элемента: ";
					InsertNode(list, GetValue<size_t>(0, lastElementIndex,
						IsRange) + 1, GetValue<int>());
					break;
				}
				case COMMAND_FIFTH:
				{
					IsEmpty(list);
					cout << "Введите индекс элемента: ";
					InsertNode(list, GetValue<size_t>(0, lastElementIndex,
						IsRange), GetValue<int>());
					break;
				}
				case COMMAND_SIXTH:
				{
					BubbleSort(list);
					break;
				}
				case COMMAND_SEVENTH:
				{
					cout << "Введите значение поиска: ";
					LinearSearch(list, GetValue<int>());
					system("pause");
					break;
				}
				case COMMAND_EIGHTH:
				{
					DeleteList(list);
					return 0;
				}
			}
		}
		catch (const exception& exception)
		{
			cerr << exception.what() << '\n';
			system("pause");
		}
	}
}