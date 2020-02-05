#pragma once
#include <iostream>
#include <sstream>
#include <regex>


template <typename T>
std::enable_if_t<!std::is_floating_point<T>::value, void>
IsType(const std::string& integerNumber)
{
	std::regex lineFormat("[+-]?[0-9]+");
	if (!std::regex_match(integerNumber, lineFormat))
	{
		throw std::exception("¬водите целое число!\n->");
	}
}


template <typename T>
std::enable_if_t<std::is_floating_point<T>::value, void>
IsType(const std::string& floatPointNumber)
{
	std::regex lineFormat("[+-]?[0-9]+[.]+[0-9]+");
	if (!std::regex_match(floatPointNumber, lineFormat))
	{
		throw std::exception("¬водите дес€тичную дробь!\n->");
	}
}


template <typename T>
T ConvertToType(const std::string& line)
{
	std::istringstream inputStringStream(line);
	T value;
	inputStringStream >> value;

	if (inputStringStream.fail())
	{
		throw std::exception("—облюдайте диапазон!\n->");
	}

	return value;
}


template <typename T>
bool IsRange(T value, T min, T max)
{
	return (value >= min && value <= max);
}


template <typename T>
T GetValue(T min = 0, T max = 0, bool (*IsRange)(T, T, T) = nullptr)
{
	std::string line;
	while (true)
	{
		try
		{
			getline(std::cin, line);
			IsType<T>(line);
			T value = ConvertToType<T>(line);

			if (IsRange != nullptr &&
				!(IsRange(value, min, max)))
			{
				throw std::exception("—облюдайте диапазон!\n->");
			}

			return value;
		}
		catch (const std::exception& exception)
		{
			std::cerr << exception.what();
		}
	}
}


std::string GetValue(const std::regex& lineFormat =
	std::regex("[A-z]+"))
{
	std::string line;
	while (true)
	{
		try
		{
			getline(std::cin, line);
			if (line.empty() || !std::regex_match(line, lineFormat))
			{
				throw std::exception("¬водите строку!\n->");
			}

			return line;
		}
		catch (const std::exception& exception)
		{
			std::cerr << exception.what();
		}
	}
}