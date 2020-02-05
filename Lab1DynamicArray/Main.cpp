#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	DynamicArray* array = CreateDynamicArray();

	while (true)
	{
		system("cls");
		cout << " Массив (" << array->Size << " элемента)\n";
		PrintArray(array);
		cout << '\n';
		PrintMenu();

		cout << "\nВведите номер команды: ";
		int commandNum = GetValue<int>(COMMAND_ZERO, COMMAND_SEVEN,
			IsRange);
		switch (commandNum)
		{
			case COMMAND_ZERO:
			{
				cout << "Введите индекс элемента: ";
				DeleteElement(array, GetValue<size_t>(0, array->Size - 1,
					IsRange));
				break;
			}
			case COMMAND_FIRST:
			{
				cout << "Введите значение элемента: ";
				InsertElement(array, 0, GetValue<int>());
				break;
			}
			case COMMAND_SECOND:
			{
				cout << "Введите значение элемента: ";
				InsertElement(array, array->Size, GetValue<int>());
				break;
			}
			case COMMAND_THIRD:
			{
				cout << "Введите индекс элемента: ";
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
				cout << "Введите элемент поиска: ";
				LinearSearch(array, GetValue<int>());
				cout << '\n';
				system("pause");
				break;
			}
			case COMMAND_SIX:
			{
				cout << "Введите элемент поиска: ";
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