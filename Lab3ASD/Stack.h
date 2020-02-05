#pragma once
#include "StructNode.h"
#include <exception>

template <class T>
class Stack
{
public:
	Stack() :
		_top(nullptr)
	{
	}

	void Push(T);
	T Pop();
	void Print();
	
	bool IsEmpty() { return (_top == nullptr); }

private:
	Node<T>* _top;
};


template <class T>
void Stack<T>::Push(T data)
{
	Node<T>* newNode = new Node<T>{ _top, data };
	_top = newNode;
}


template <class T>
T Stack<T>::Pop()
{
	if (IsEmpty())
	{
		throw std::exception("Стек пуст!");
	}

	T value = _top->Data;
	Node<T>* deletedNode = _top;
	_top = _top->Next;
	delete deletedNode;

	return value;
}


template <class T>
void Stack<T>::Print()
{
	Node<T>* current = _top;
	while (current != nullptr)
	{
		std::cout << '\t' << current->Data << '\n';
		current = current->Next;
	}
}