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

		cout << "\n������� �������: ";
		TreapCommand command = GetValue(TreapCommand::ADD_RANDOM_VALUES,
			TreapCommand::EXIT,
			IsRange);

		try
		{
			switch (command)
			{
				case TreapCommand::ADD_RANDOM_VALUES:
				{
					cout << "������� ���������� ���������: ";
					size_t count = GetValue<size_t>();
					for (size_t i = 0; i < count; ++i)
					{
						treap.AddNonOptimized(GetRandomValue<T>());
					}
					break;
				}
				case TreapCommand::ADD_VALUE_NONOPTIMIZED:
				{
					cout << "������� ����: ";
					T key = GetValue<T>();
					treap.AddNonOptimized(key);
					break;
				}
				case TreapCommand::ADD_VALUE_OPTIMIZED:
				{
					cout << "������� ����: ";
					T key = GetValue<T>();
					treap.AddOptimized(key);
					break;
				}
				case TreapCommand::REMOVE_VALUE_NONOPTIMIZED:
				{
					cout << "������� ����: ";
					T key = GetValue<T>();
					treap.RemoveNonOptimized(key);
					break;
				}
				case TreapCommand::REMOVE_VALUE_OPTIMIZED:
				{
					cout << "������� ����: ";
					T key = GetValue<T>();
					treap.RemoveOptimized(key);
					break;
				}
				case TreapCommand::FIND_VALUE:
				{
					cout << "������� ����: ";
					cout << "\n���������: " << (treap.Find(GetValue<T>())) ?
						"���� ������!" :
						"���� �� ������!";
					system("pause");
					break;
				}
				case TreapCommand::TESTING:
				{
					cout << "���������� ���������: ";
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
			cerr << "������ ��������� ������!\n";
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
	cout << "\n\n\t 0 �������� n ��������� ������.\n" <<
		"\t 1 �������� ����(�� ����������������).\n" <<
		"\t 2 �������� ����(����������������).\n" <<
		"\t 3 ������� ����(�� ����������������).\n" <<
		"\t 4 ������� ����(����������������).\n" <<
		"\t 5 ����� �� �����.\n" <<
		"\t 6 ������������� ������� � ��������.\n" <<
		"\t 7 ����� � ������� ����.\n";
}