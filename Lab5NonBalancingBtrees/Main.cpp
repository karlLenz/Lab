#include "Main.h"

int main()
{
	srand(static_cast<size_t>(time(0)));
	setlocale(LC_ALL, "ru");
	using KeyType = int;

	while (true)
	{
		system("cls");
		PrintTextMainMenu();

		cout << "\n¬ведите команду: ";
		CommandMenu command = GetValue(CommandMenu::BINARY_SEARCH_TREE,
			CommandMenu::EXIT, IsRange);

		switch (command)
		{
			case CommandMenu::BINARY_SEARCH_TREE:
			{
				PrintBinarySearchTreeMenu<KeyType>();
				break;
			}
			case CommandMenu::TREAP:
			{
				PrintTreapMenu<KeyType>();
				break;
			}
			case CommandMenu::EXIT:
			{
				return 0;
			}
		}
	}
}