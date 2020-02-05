#include "HashTable.h"
#include <cmath>
#include <iostream>

inline size_t GetStartingSize() { return 3; }

HashTable::HashTable()
{
	_size = 0;
	_maxSize = static_cast<size_t>(GetGrowthFactor() * GetStartingSize());
	_lists = new List*[_maxSize];
	for (size_t i = 0; i < _maxSize; ++i)
	{
		_lists[i] = new List;
	}
}


HashTable::~HashTable()
{
	for (size_t i = 0; i < _maxSize; ++i)
	{
		delete _lists[i];
	}
	delete[] _lists;
	_lists = nullptr;
}


void HashTable::Resize()
{
	float tableFillFactor = static_cast<float>(_size) / 
		static_cast<float>(_maxSize);
	bool isRehashing = (tableFillFactor >= 1.33f);

	if (isRehashing)
	{
		size_t oldMaxSize = _maxSize;
		_maxSize = static_cast<size_t>(GetGrowthFactor() * _maxSize);
		List** newArray = new List*[_maxSize];
		for (size_t i = 0; i < _maxSize; ++i)
		{
			newArray[i] = new List;
		}
		Rehashing(newArray, oldMaxSize);

		for (size_t i = 0; i < oldMaxSize; ++i)
		{
			delete _lists[i];
		}
		delete[] _lists;
		_lists = newArray;
	}
}


void HashTable::Rehashing(List** newArray, size_t oldMaxSize)
{
	for (size_t i = 0; i < oldMaxSize; ++i)
	{
		Node<Pair>* current = _lists[i]->GetHead();
		while (current != nullptr)
		{
			Node<Pair>* addedNode = current;
			current = current->Next;
			newArray[Hash(addedNode->Data.Key)]->Add(addedNode);
		}
		_lists[i]->SetHeadNull();
	}
}


void HashTable::Add(const Pair& pair)
{
	List* list = _lists[Hash(pair.Key)];
	auto pairs = list->Find(pair.Key);
	if (!pairs.empty())
	{
		for (const auto* pairIterator : pairs)
		{
			if (pairIterator->Value == pair.Value)
			{
				throw std::exception("Такая пара уже имеется!");
			}
		}
	}
	++(_size);
	Resize();

	Node<Pair>* newNode = new Node<Pair>;
	newNode->Data = pair;
	return (_lists[Hash(pair.Key)])->Add(newNode);
}


void HashTable::Remove(const std::string& key)
{
	if ((_lists[Hash(key)]->GetHead()) == nullptr)
	{
		throw std::exception("Ключ не найден!");
	}
	size_t deletedElementCount = _lists[Hash(key)]->Remove(key);
	_size -= deletedElementCount;
}


std::vector<const Pair*> HashTable::Find(const std::string& key)
{
	return _lists[Hash(key)]->Find(key);
}


size_t HashTable::Hash(const std::string& key)
{
	size_t hash = 0;
	size_t somePrimeNum = (_maxSize - 1);
	size_t k = 0;
	
	for (const auto& symbol : key)
	{
		hash += symbol * static_cast<size_t>(pow(somePrimeNum, k));
		++k;
	}

	return hash % _maxSize;
}


void HashTable::Print()
{
	for (size_t i = 0; i < _maxSize; ++i)
	{
		std::cout << '\t';
		Node<Pair>* current = _lists[i]->GetHead();
		while (current != nullptr)
		{
			std::cout << current->Data.Key + ' ' +
				current->Data.Value + " -> ";
			current = current->Next;
		}
		std::cout << "NULL\n";
	}
}