#include "Main.h"

int main()
{
	setlocale(LC_ALL, "ru");

	while (true)
	{
		system("cls");
		PrintMainTextMenu();

		cout << "\n¬ведите номер команды: ";
		CommandMenu command = GetValue(CommandMenu::HASH_TABLE,
			CommandMenu::EXIT, IsRange);

		switch (command)
		{
			case CommandMenu::HASH_TABLE:
			{
				PrintMenu<HashTable>();
				break;
			}
			case CommandMenu::DICTIONARY:
			{
				PrintMenu<Dictionary>();
				break;
			}
			case CommandMenu::EXIT:
			{
				return 0;
			}
		}
	}
}