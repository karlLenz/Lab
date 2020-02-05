#include "List.h"

List::~List()
{
	Node<Pair>* current = _head;
	while (current != nullptr)
	{
		current = current->Next;
		delete _head;
		_head = current;
	}
}


void List::Add(Node<Pair>* node)
{
	node->Next = _head;
	_head = node;
}


size_t List::Remove(const std::string& key)
{
	Node<Pair>** current = &_head;
	size_t deletedElementCount = 0;
	while ((*current) != nullptr)
	{
		if (key == (*current)->Data.Key)
		{
			Node<Pair>* destroyedNode = (*current);
			(*current) = (*current)->Next;
			delete destroyedNode;
			++deletedElementCount;
		}
		else
		{
			current = &(*current)->Next;
		}
	}

	return deletedElementCount;
}


std::vector<const Pair*> List::Find(const std::string& key)
{
	std::vector<const Pair*> pairs;
	Node<Pair>* current = _head;
	while (current != nullptr)
	{
		if (key == current->Data.Key)
		{
			pairs.push_back(&(current->Data));
		}
		current = current->Next;
	}

	return pairs;
}