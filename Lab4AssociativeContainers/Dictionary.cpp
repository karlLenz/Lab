#include "Dictionary.h"

void Dictionary::Add(const Pair& pair)
{
	auto findedPair = _table.Find(pair.Key);
	if (!findedPair.empty())
	{
		throw std::exception("Такой ключ в таблице уже существует!");
	}

	return _table.Add(pair);
}


std::vector<const Pair*> Dictionary::Find(const std::string& key)
{
	auto findedPair = _table.Find(key);
	if (findedPair.empty())
	{
		throw std::exception("Ключ не найден!");
	}

	return findedPair;
}