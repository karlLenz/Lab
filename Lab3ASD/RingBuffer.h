#pragma once
#include "StructNode.h"
#include <exception>

template <class T>
class RingBuffer
{
public:
	RingBuffer(size_t);
	~RingBuffer();
	void Enqueue(T);
	T Dequeue();
	void Print();

	bool IsEmpty() { return _size == 0; }

private:
	Node<T>* _head;
	Node<T>* _tail;
	size_t _size;
	size_t _maxSize;

	Node<T>* _outputBegin;
};


template <class T>
RingBuffer<T>::RingBuffer(size_t maxSize)
{
	if (maxSize > 0)
	{
		_size = 0;
		_maxSize = maxSize;
		_tail = _head = new Node<T>;
		_head->Next = _tail->Next = _head;

		for (size_t i = 0; i < _maxSize - 1; ++i)
		{
			Node<T>* newNode = new Node<T>;
			_tail->Next = newNode;
			_tail = newNode;
			_tail->Next = _head;
		}
		_outputBegin = _head;
	}
	else
	{
		throw std::exception("Минимальный размер буфера 1!");
	}
}


template <class T>
RingBuffer<T>::~RingBuffer()
{
	Node<T>* current = _head;
	while (current != _tail)
	{
		current = current->Next;
		delete _head;
		_head = current;
	}
	delete _tail;
}


template <class T>
void RingBuffer<T>::Enqueue(T data)
{
	_tail = _tail->Next;
	_tail->Data = data;
	if (_size >= _maxSize)
	{
		_head = _head->Next;
		_size = _maxSize - _size / _maxSize;
	}
	++(_size);
}


template <class T>
T RingBuffer<T>::Dequeue()
{
	if (IsEmpty())
	{
		throw std::exception("Буфер пуст!");
	}

	if (_size > _maxSize)
	{
		_size = _maxSize - (_size / _maxSize);
	}
	T value = _head->Data;
	_head = _head->Next;
	--(_size);

	return value;
}


template <class T>
void RingBuffer<T>::Print()
{
	std::cout << "Количество элементов: " << _size <<
		"(" << _maxSize << ")\n\n";

	Node<T>* current = _head;
	for (size_t i = 0; i < _size; ++i)
	{
		std::cout << ' ' << current->Data;
		current = current->Next;
	}
}