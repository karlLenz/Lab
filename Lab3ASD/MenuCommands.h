#pragma once
#include <iostream>

enum class Command
{
	STACK,
	DOUBLE_STACK_QUEUE,
	RING_BUFFER,
	EXIT
};


enum class CommandAsd
{
	INPUT,
	OUTPUT,
	EXIT
};


std::istream& operator>>(std::istream& inputStream, Command& value)
{
	int command;
	inputStream >> command;
	value = static_cast<Command>(command);

	return inputStream;
}


std::istream& operator>>(std::istream& inputStream, CommandAsd& value)
{
	int command;
	inputStream >> command;
	value = static_cast<CommandAsd>(command);

	return inputStream;
}