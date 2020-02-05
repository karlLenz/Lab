#pragma once
#include "List.h"

class HashTable
{
public:
	HashTable();
	~HashTable();
	void Add(const Pair&);
	void Remove(const std::string&);
	std::vector<const Pair*> Find(const std::string&);
	void Print();

	size_t GetSize() { return _size; }
	size_t GetMaxSize() { return _maxSize; }

private:
	size_t Hash(const std::string&);
	void Resize();
	void Rehashing(List**, size_t);

	float GetGrowthFactor() { return 1.5; }
	size_t _size;
	size_t _maxSize;
	List** _lists;
};