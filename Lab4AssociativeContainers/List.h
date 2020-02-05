#pragma once
#include "../Lab3ASD/StructNode.h"
#include "StructPair.h"
#include <vector>

class List
{
public:
	~List();
	void Add(Node<Pair>*);
	size_t Remove(const std::string&);
	std::vector<const Pair*> Find(const std::string&);

	Node<Pair>* GetHead() { return _head; }
	void SetHeadNull() { _head = nullptr; }

private:
	Node<Pair>* _head;
};