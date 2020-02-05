#pragma once
#include <iostream>

enum class CommandMenu
{
	BINARY_SEARCH_TREE,
	TREAP,
	EXIT
};


enum class BstCommand
{
	ADD_VALUE,
	ADD_RANDOM_VALUES,
	REMOVE_VALUE,
	FIND_VALUE,
	FIND_MIN,
	FIND_MAX,
	EXIT
};


enum class TreapCommand
{
	ADD_RANDOM_VALUES,
	ADD_VALUE_NONOPTIMIZED,
	ADD_VALUE_OPTIMIZED,
	REMOVE_VALUE_NONOPTIMIZED,
	REMOVE_VALUE_OPTIMIZED,
	FIND_VALUE,
	TESTING,
	EXIT
};


std::istream& operator>>(std::istream& inputStream, CommandMenu& value)
{
	int command;
	inputStream >> command;
	value = static_cast<CommandMenu>(command);

	return inputStream;
}


std::istream& operator>>(std::istream& inputStream, BstCommand& value)
{
	int command;
	inputStream >> command;
	value = static_cast<BstCommand>(command);

	return inputStream;
}


std::istream& operator>>(std::istream& inputStream, TreapCommand& value)
{
	int command;
	inputStream >> command;
	value = static_cast<TreapCommand>(command);

	return inputStream;
}