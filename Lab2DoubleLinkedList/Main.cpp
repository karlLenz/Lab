#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	List* list = CreateList();

	while (true)
	{
		system("cls");
		cout << "���������� ��������� � ������: " << list->Size << '\n';
		PrintList(list);
		PrintMenu();

		size_t lastElementIndex = list->Size - 1;
		try
		{
			cout << "\n������� ����� �������: ";
			int commandNum = GetValue<int>(COMMAND_ZERO, COMMAND_EIGHTH,
				IsRange);
			switch (commandNum)
			{
				case COMMAND_ZERO:
				{
					std::cout << "������� ��������: ";
					AddNode(list, GetValue<int>());
					break; 
				}
				case COMMAND_FIRST:
				{
					std::cout << "������� ������ ��������: ";
					DeleteNode(list, GetValue<size_t>(0, list->Size - 1,
						IsRange));
					break;
				}
				case COMMAND_SECOND:
				{
					std::cout << "������� ��������: ";
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
					cout << "������� ������ ��������: ";
					InsertNode(list, GetValue<size_t>(0, lastElementIndex,
						IsRange) + 1, GetValue<int>());
					break;
				}
				case COMMAND_FIFTH:
				{
					IsEmpty(list);
					cout << "������� ������ ��������: ";
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
					cout << "������� �������� ������: ";
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