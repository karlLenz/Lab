#pragma once
#include <iostream>

enum class CommandMenu
{
	HASH_TABLE,
	DICTIONARY,
	EXIT
};


enum class Command
{
	ADD_PAIR,
	REMOVE_PAIR,
	FIND_PAIRS,
	ADD_RANDOM_PAIRS,
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