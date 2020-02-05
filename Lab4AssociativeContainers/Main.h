#pragma once
#include "Dictionary.h"

#include <ctime>
#include "MenuCommands.h"
#include "../Lab1DynamicArray/GetValue.h"
#include "../GetRandomValue.h"
using namespace std;

void PrintTextMenu();

template <typename T>
void AddRandomPairs(T&);

template <typename T>
void PrintMenu()
{
	T container;
	while (true)
	{
		system("cls");
		cout << "Количество пар (Размер табицы): " <<
			container.GetSize() << '(' << container.GetMaxSize() <<
			")\nКоэфициент заполнения: " <<
			static_cast<float>(container.GetSize()) /
			static_cast<float>(container.GetMaxSize()) << "\n\n";
		container.Print();
		PrintTextMenu();

		try
		{
			cout << "\nВведите номер команды: ";
			Command command = GetValue(Command::ADD_PAIR, Command::EXIT,
				IsRange);

			switch (command)
			{
				case Command::ADD_PAIR:
				{
					cout << "Введите значение: ";
					regex lineFormat("[A-z]+[ ][A-z]+");
					istringstream inputStream(GetValue(lineFormat));
					Pair pair;
					inputStream >> pair.Key >> pair.Value;
					container.Add(pair);
					break;
				}
				case Command::REMOVE_PAIR:
				{
					cout << "Введите ключ: ";
					container.Remove(GetValue());
					break;
				}
				case Command::FIND_PAIRS:
				{
					cout << "Введите ключ: ";
					auto pairs = container.Find(GetValue());
					for (const auto* pair : pairs)
					{
						cout << pair->Key + ' ' + pair->Value + ",\n";
					}
					system("pause");
					break;
				}
				case Command::ADD_RANDOM_PAIRS:
				{
					AddRandomPairs(container);
					break;
				}
				case Command::EXIT:
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


void PrintMainTextMenu()
{
	cout << "\n\t0 Хеш-таблица.\n" <<
		"\t1 Словарь.\n" <<
		"\t2 Выход из программы.\n";
}


void PrintTextMenu()
{
	cout << "\n\t0 Добавить пару.\n" <<
		"\t1 Удалить ключ.\n" <<
		"\t2 Поиск по ключю.\n" <<
		"\t3 Заполнить рандомными парами.\n" <<
		"\t4 Выход из программы.\n";
}


string GetRandomLine()
{
	string line;
	size_t length = 4 + GetRandomValue<size_t>() % 5;
	for (size_t i = 0; i < length; ++i)
	{
		char randomSymbol = 97 + GetRandomValue<short>() % 26;
		line += randomSymbol;
	}

	return line;
}


template <typename T>
void AddRandomPairs(T& container)
{
	size_t rehashingSize =
		static_cast<size_t>(1.5f * container.GetMaxSize());
	for (size_t i = 0; i < rehashingSize; ++i)
	{
		container.Add({ GetRandomLine(), GetRandomLine() });
	}
}