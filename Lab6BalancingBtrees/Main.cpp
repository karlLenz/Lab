#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		system("cls");
		PrintMainTextMenu();
		cout << "\n������� ����� �������: ";
		CommandMenu command = GetValue(CommandMenu::AVL_TREE,
			CommandMenu::EXIT, IsRange);

		switch (command)
		{
			case CommandMenu::AVL_TREE:
			{
				AvlTree<DataType> tree;
				PrintMenu(tree);
				break;
			}
			case CommandMenu::RED_BLACK_TREE:
			{
				RedBlackTree<DataType> tree;
				PrintMenu(tree);
				break;
			}
			case CommandMenu::TESTING:
			{
				cout << "������� ���������� ���������: ";
				Testing(GetValue<size_t>());
				break;
			}
			case CommandMenu::EXIT:
			{
				return 0;
			}
		}
	}
}