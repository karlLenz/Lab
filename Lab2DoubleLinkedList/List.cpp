#include "List.h"

#include <iostream>
#include "Check.h"


List* CreateList()
{
	List* list = new List;
	list->Head = nullptr;
	list->Tail = nullptr;
	list->Size = 0;

	return list;
}


void AddNode(List* list, int data)
{
	Node* newNode = new Node;
	if (list->Size == 0)
	{
		list->Head = newNode;
		list->Head->Prev = nullptr;
		list->Tail = newNode;
	}
	else
	{
		newNode->Prev = list->Tail;
	}
	list->Tail->Next = newNode;
	list->Tail = newNode;
	list->Tail->Next = nullptr;
	list->Tail->Data = data;
	++list->Size;
	list->IsSorted = false;
}


void DeleteNode(List* list, size_t index)
{
	IsEmpty(list);
	Node* current = GetNode(list, index);

	if (list->Size > 1 && index == 0)
	{
		list->Head = current->Next;
		list->Head->Prev = nullptr;
	}
	else if (list->Size > 1 && index == list->Size - 1)
	{
		list->Tail = current->Prev;
		list->Tail->Next = nullptr;
	}
	else if (list->Size == 1)
	{
		list->Head = nullptr;
		list->Tail = nullptr;
	}
	else
	{
		current->Prev->Next = current->Next;
		current->Next->Prev = current->Prev;
	}

	delete current;
	--list->Size;
}


void InsertNode(List* list, size_t index, int data)
{
	IsEmpty(list);

	Node* newNode = new Node;
	if (index == 0)
	{
		newNode->Next = list->Head;
		newNode->Prev = nullptr;
		list->Head->Prev = newNode;
		list->Head = newNode;
	}
	else if (index == list->Size - 1)
	{
		list->Tail->Next = newNode;
		newNode->Next = nullptr;
		newNode->Prev = list->Tail;
		list->Tail = newNode;
	}
	else
	{
		Node* current = GetNode(list, index);
		current->Prev->Next = newNode;
		newNode->Next = current;
		newNode->Prev = current->Prev;
		current->Prev = newNode;
	}
	newNode->Data = data;
	++list->Size;
	list->IsSorted = false;
}


void BubbleSort(List* list)
{
	IsEmpty(list);
	IsSorted(list);
	for (size_t i = 0; i < list->Size; ++i)
	{
		Node* current = list->Head;
		while (current != nullptr && current->Next != nullptr)
		{
			if (current->Data > current->Next->Data)
			{
				SwapNode(list, current);
			}
			current = current->Next;
		}
	}
	list->IsSorted = true;
}


void LinearSearch(const List* list, int value)
{
	IsEmpty(list);
	Node* current = list->Head;
	for (size_t i = 0; current != nullptr; ++i)
	{
		if (current->Data == value)
		{
			std::cout << "List[" << i << "] = "
				<< current->Data << ", ";
		}
		current = current->Next;
	}
}


void DeleteList(const List* list)
{
	if (list != nullptr)
	{
		Node* current = list->Head;
		while (current != nullptr && current->Next != nullptr)
		{
			current = current->Next;
			delete current->Prev;
		}
		delete list->Tail;
		
		delete list;
		list = nullptr;
	}
}


inline Node* GetNode(const List* list, const size_t index)
{
	Node* current;
	const size_t mid = (list->Size - 1) / 2;
	if (index <= mid)
	{
		current = list->Head;
		for (size_t i = 0; i < index; ++i)
		{
			current = current->Next;
		}
	}
	else
	{
		current = list->Tail;
		for (size_t i = list->Size - 1; i > index; --i)
		{
			current = current->Prev;
		}
	}

	return current;
}


inline void SwapNode(List* list, Node* current)
{
	if (current == list->Head)
	{
		list->Head = current->Next;
		list->Head->Prev = nullptr;
	}
	else
	{
		current->Prev->Next = current->Next;
		current->Next->Prev = current->Prev;
	}
	Node* temp = current->Next->Next;
	current->Next->Next = current;
	current->Prev = current->Next;
	if (current->Next == list->Tail)
	{
		list->Tail = current;
		list->Tail->Next = nullptr;
	}
	else
	{
		current->Next = temp;
		temp->Prev = current;
	}
}