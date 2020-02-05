#pragma once

struct Node
{
	Node* Next;
	Node* Prev;
	int Data;
};

struct List
{
	Node* Head;
	Node* Tail;
	size_t Size;
	bool IsSorted;
};