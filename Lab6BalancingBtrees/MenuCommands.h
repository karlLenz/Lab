#pragma once
#include <iostream>

enum class CommandMenu
{
	AVL_TREE,
	RED_BLACK_TREE,
	TESTING,
	EXIT
};


enum class Command
{
	ADD_RANDOM_VALUES,
	ADD_VALUE,
	REMOVE_VALUE,
	FIND_VALUE,
	EXIT
};


std::istream& operator>>(std::istream& inputStream, CommandMenu& value)
{
	int command;
	inputStream >> command;
	value = static_cast<CommandMenu>(command);

	return inputStream;
}


std::istream& operator>>(std::istream& inputStream, Command& value)
{
	int command;
	inputStream >> command;
	value = static_cast<Command>(command);

	return inputStream;
}