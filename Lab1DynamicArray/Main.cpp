#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	DynamicArray* array = CreateDynamicArray();

	while (true)
	{
		system("cls");
		cout << " ������ (" << array->Size << " ��������)\n";
		PrintArray(array);
		cout << '\n';
		PrintMenu();

		cout << "\n������� ����� �������: ";
		int commandNum = GetValue<int>(COMMAND_ZERO, COMMAND_SEVEN,
			IsRange);
		switch (commandNum)
		{
			case COMMAND_ZERO:
			{
				cout << "������� ������ ��������: ";
				DeleteElement(array, GetValue<size_t>(0, array->Size - 1,
					IsRange));
				break;
			}
			case COMMAND_FIRST:
			{
				cout << "������� �������� ��������: ";
				InsertElement(array, 0, GetValue<int>());
				break;
			}
			case COMMAND_SECOND:
			{
				cout << "������� �������� ��������: ";
				InsertElement(array, array->Size, GetValue<int>());
				break;
			}
			case COMMAND_THIRD:
			{
				cout << "������� ������ ��������: ";
				InsertElement(array,
					GetValue<size_t>(0, array->Size - 1, IsRange) + 1,
					GetValue<int>());
				break;
			}
			case COMMAND_FOURTH:
			{
				InsertionSort(array);
				break;
			}
			case COMMAND_FIFTH:
			{
				cout << "������� ������� ������: ";
				LinearSearch(array, GetValue<int>());
				cout << '\n';
				system("pause");
				break;
			}
			case COMMAND_SIX:
			{
				cout << "������� ������� ������: ";
				BinarySearch(array, GetValue<int>());
				cout << '\n';
				system("pause");
				break;
			}
			case COMMAND_SEVEN:
			{
				DeleteDynamicArray(array);
				return 0;
			}
		}
	}
}