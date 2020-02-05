#pragma once
#include "AvlTree.h"
#include "RedBlackTree.h"

#include <iostream>
#include "../Lab1DynamicArray/GetValue.h"
#include "../GetRandomValue.h"
#include "MenuCommands.h"
using namespace std;
using DataType = int;

void PrintDataStructTextMenu();

template <typename T>
void PrintMenu(T& tree)
{
	while (true)
	{
		system("cls");
		cout << "������ ������: " << tree.GetHeight() << "\n\n";
		tree.Print();
		PrintDataStructTextMenu();
		cout << "\n������� ����� �������: ";
		Command command = GetValue(Command::ADD_RANDOM_VALUES,
			Command::EXIT, IsRange);

		switch (command)
		{
			case Command::ADD_RANDOM_VALUES:
			{
				cout << "������� ���������� ���������: ";
				size_t count = GetValue<size_t>();
				for (size_t i = 0; i < count; ++i)
				{
					tree.Add(GetRandomValue<DataType>());
				}
				break;
			}
			case Command::ADD_VALUE:
			{
				cout << "������� ����: ";
				DataType key = GetValue<DataType>();
				tree.Add(key);
				break;
			}
			case Command::REMOVE_VALUE:
			{
				cout << "������� ����: ";
				DataType key = GetValue<DataType>();
				tree.Remove(key);
				break;
			}
			case Command::FIND_VALUE:
			{
				cout << "������� ����: ";
				DataType key = GetValue<DataType>();
				bool isFinded = tree.Find(key);
				cout << ((isFinded) ?
					"\n���� ������!\n" :
					"\n���� �� ������!\n");
				system("pause");
				break;
			}
			case Command::EXIT:
			{
				return;
			}
		}
	}
}


void PrintMainTextMenu()
{
	cout << "\n\n\t 0 ���-������.\n" <<
		"\t 1 ������-������ ������.\n" <<
		"\t 2 ������������ ������� � �������� ��������.\n" <<
		"\t 3 ����� �� ���������.\n";
}


void PrintDataStructTextMenu()
{
	cout << "\n\n\t 0 �������� n ��������� ������.\n" <<
		"\t 1 �������� ����.\n" <<
		"\t 2 ������� ����.\n" <<
		"\t 3 ����� �� �����.\n" <<
		"\t 4 ����� � ������� ����.\n";
}