#pragma once
#include "List.h"
#include "Check.h"
#include "Print.h"

#include <iostream>
#include <exception>
#include "../Lab1DynamicArray/GetValue.h"
using namespace std;

enum Commands
{
	COMMAND_ZERO,
	COMMAND_FIRST,
	COMMAND_SECOND,
	COMMAND_THIRD,
	COMMAND_FOURTH,
	COMMAND_FIFTH,
	COMMAND_SIXTH,
	COMMAND_SEVENTH,
	COMMAND_EIGHTH
};


std::istream& operator>>(std::istream& inputStream, Commands& value)
{
	int Command;
	inputStream >> Command;
	value = static_cast<Commands>(Command);

	return inputStream;
}