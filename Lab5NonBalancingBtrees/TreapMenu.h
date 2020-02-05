#pragma once
#include "Treap.h"
#include "MenuCommands.h"
#include "../Lab1DynamicArray/GetValue.h"
#include "../GetRandomValue.h"
#include "TreapTesting.h"
using namespace std;


void PrintTreapTextMenu();

template <typename T>
void PrintTreapMenu()
{
	Treap<T> treap;

	while (true)
	{
		std::system("cls");
		treap.Print();
		PrintTreapTextMenu();

		cout << "\nВведите команду: ";
		TreapCommand command = GetValue(TreapCommand::ADD_RANDOM_VALUES,
			TreapCommand::EXIT,
			IsRange);

		try
		{
			switch (command)
			{
				case TreapCommand::ADD_RANDOM_VALUES:
				{
					cout << "Введите количество элементов: ";
					size_t count = GetValue<size_t>();
					for (size_t i = 0; i < count; ++i)
					{
						treap.AddNonOptimized(GetRandomValue<T>());
					}
					break;
				}
				case TreapCommand::ADD_VALUE_NONOPTIMIZED:
				{
					cout << "Введите ключ: ";
					T key = GetValue<T>();
					treap.AddNonOptimized(key);
					break;
				}
				case TreapCommand::ADD_VALUE_OPTIMIZED:
				{
					cout << "Введите ключ: ";
					T key = GetValue<T>();
					treap.AddOptimized(key);
					break;
				}
				case TreapCommand::REMOVE_VALUE_NONOPTIMIZED:
				{
					cout << "Введите ключ: ";
					T key = GetValue<T>();
					treap.RemoveNonOptimized(key);
					break;
				}
				case TreapCommand::REMOVE_VALUE_OPTIMIZED:
				{
					cout << "Введите ключ: ";
					T key = GetValue<T>();
					treap.RemoveOptimized(key);
					break;
				}
				case TreapCommand::FIND_VALUE:
				{
					cout << "Введите ключ: ";
					cout << "\nРезультат: " << (treap.Find(GetValue<T>())) ?
						"ключ найден!" :
						"ключ не найден!";
					system("pause");
					break;
				}
				case TreapCommand::TESTING:
				{
					cout << "Количество элементов: ";
					Testing(GetValue<size_t>());
					system("pause");
					break;
				}
				case TreapCommand::EXIT:
				{
					return;
				}
			}
		}
		catch (const bad_alloc&)
		{
			cerr << "Ошибка выделения памяти!\n";
			system("pause");
		}
		catch (const exception& exception)
		{
			cerr << exception.what() << '\n';
			system("pause");
		}
	}
}


void PrintTreapTextMenu()
{
	cout << "\n\n\t 0 Добавить n рандомных ключей.\n" <<
		"\t 1 Добавить ключ(не оптимизированный).\n" <<
		"\t 2 Добавить ключ(оптимизированный).\n" <<
		"\t 3 Удалить ключ(не оптимизированный).\n" <<
		"\t 4 Удалить ключ(оптимизированный).\n" <<
		"\t 5 Поиск по ключу.\n" <<
		"\t 6 Тестировавние вставки и удаления.\n" <<
		"\t 7 Выход в главное меню.\n";
}