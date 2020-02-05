#pragma once
#include "Stack.h"
#include <exception>

template <class T>
class DoubleStackQueue
{
public:
	T Dequeue();
	void Print();
	
	void Enqueue(T data) { _in.Push(data); }
	bool IsEmpty() { return (_in.IsEmpty() && _out.IsEmpty()); }

private:
	Stack<T> _in;
	Stack<T> _out;
};


template <class T>
T DoubleStackQueue<T>::Dequeue()
{
	if (IsEmpty())
	{
		throw std::exception("Очередь пуста!");
	}

	if (_out.IsEmpty())
	{
		while (!(_in.IsEmpty()))
		{
			T value = _in.Pop();
			_out.Push(value);
		}
	}

	return _out.Pop();
}


template <class T>
void DoubleStackQueue<T>::Print()
{
	_in.Print();
	std::cout << '\n';
	_out.Print();
}