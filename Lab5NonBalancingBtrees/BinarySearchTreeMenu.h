#pragma once
#include "Treap.h"
#include <iostream>
#include "MenuCommands.h"
#include "../GetRandomValue.h"
#include "../Lab1DynamicArray/GetValue.h"
using namespace std;

void PrintBinarySearchTreeTextMenu();

template <typename T>
void PrintBinarySearchTreeMenu()
{
	BinaryTree<T> tree;

	while (true)
	{
		system("cls");
		tree.Print();
		PrintBinarySearchTreeTextMenu();

		cout << "\n������� �������: ";
		BstCommand command = GetValue(BstCommand::ADD_VALUE,
			BstCommand::EXIT, IsRange);

		try
		{
			switch (command)
			{
				case BstCommand::ADD_VALUE:
				{
					cout << "������� ����: ";
					tree.Add(GetValue<T>());
					break;
				}
				case BstCommand::ADD_RANDOM_VALUES:
				{
					cout << "������� ���������� ���������: ";
					size_t count = GetValue<size_t>();
					for (size_t i = 0; i < count; ++i)
					{
						tree.Add(GetRandomValue<T>());
					}
					break;
				}
				case BstCommand::REMOVE_VALUE:
				{
					cout << "������� ����: ";
					tree.Remove(GetValue<T>());
					break;
				}
				case BstCommand::FIND_VALUE:
				{
					cout << "������� ����: ";
					const BstNode<T>* result = tree.Find(GetValue<T>());
					if (result == nullptr)
					{
						 std::exception("���� �� ������!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::FIND_MIN:
				{
					cout << "������� ����: ";
					const BstNode<T>* result = tree.FindMin();
					if (result == nullptr)
					{
						std::exception("����������� ���� �� ������!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::FIND_MAX:
				{
					cout << "������� ����: ";
					const BstNode<T>* result = tree.FindMax();
					if (result == nullptr)
					{
						std::exception("������������ ���� �� ������!");
					}
					cout << result->Data << '\n';
					system("pause");
					break;
				}
				case BstCommand::EXIT:
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


void PrintBinarySearchTreeTextMenu()
{
	cout << "\n\n\t 0 �������� ����.\n" <<
		"\t 1 �������� n ��������� ������.\n" <<
		"\t 2 ������� ����.\n" <<
		"\t 3 ����� �� �����.\n" <<
		"\t 4 ����� ������������ �����.\n" <<
		"\t 5 ����� ������������ �����.\n" <<
		"\t 6 ����� � ������� ����.\n";
}