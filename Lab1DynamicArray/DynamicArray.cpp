#include "DynamicArray.h"
#include <iostream>
using namespace std;

inline short GetStartinSize() { return 3; }
inline float GetGrowthFactor() { return 1.5; }

DynamicArray* CreateDynamicArray()
{
	DynamicArray* array = new DynamicArray;
	array->MaxSize = static_cast<size_t>(GetGrowthFactor() *
		GetStartinSize());
	array->Array = new int[array->MaxSize];

	array->Size = 0;
	array->IsSorted = false;
	return array;
}


void ResizeArray(DynamicArray* array)
{
	++array->Size;
	if (array->Size > array->MaxSize)
	{
		array->MaxSize = static_cast<size_t>(GetGrowthFactor() * array->Size);
		int *newArray = new int[array->MaxSize];
		CopyArray(array, newArray);

		delete[] array->Array;
		array->Array = newArray;
	}
}


void InsertElement(DynamicArray* array, size_t index, int data)
{
	ResizeArray(array);
	for (size_t i = array->Size - 1; i > index; --i)
	{
		array->Array[i] = array->Array[i - 1];
	}
	array->Array[index] = data;
	array->IsSorted = false;
}


void DeleteElement(DynamicArray* array, size_t index)
{
	if (array->Size > 0)
	{
		for (; index < array->Size; ++index)
		{
			array->Array[index] = array->Array[index + 1];
		}
		--array->Size;
	}
	else
	{
		cout << "Массив пуст."
			<< endl;
		system("pause");
	}
}


void LinearSearch(const DynamicArray* array, int value)
{
	for (size_t i = 0; i < array->Size; ++i)
	{
		if (value == array->Array[i])
		{
			cout << " array[" << i << "] = "
				<< array->Array[i] << ", ";
		}
	}
}


void InsertionSort(DynamicArray* array)
{
	if (!array->IsSorted)
	{
		int temp;
		for (size_t i = 1; i < array->Size; ++i)
		{
			for (size_t j = i; j > 0; --j)
			{
				if (array->Array[j] < array->Array[j - 1])
				{
					temp = array->Array[i];
					array->Array[i] = array->Array[j - 1];
					array->Array[j - 1] = temp;
				}
			}
		}
		array->IsSorted = true;
	}
	else
	{
		cout << "Массив отсортирован!" << endl;
		system("pause");
	}
}


void BinarySearch(const DynamicArray* array, int value)
{
	size_t left = 0;
	size_t right = array->Size - 1;
	size_t mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (array->Array[mid] == value)
		{
			cout << "array[" << mid << "] = "
				<< array->Array[mid] << ", ";
		}

		(value < array->Array[mid]) ?
			right = mid - 1 :
			left = mid + 1;
	}
}


void DeleteDynamicArray(const DynamicArray* array)
{
	if (array != nullptr && array->Array != nullptr)
	{
		delete[] array->Array;
		delete array;
	}
}


void PrintArray(const DynamicArray* array)
{
	for (size_t i = 0; i < array->Size; ++i)
	{
		cout << ' ' << array->Array[i];
	}
}


void CopyArray(const DynamicArray* array, int* copyArray)
{
	for (size_t i = 0; i < array->Size; ++i)
	{
		copyArray[i] = array->Array[i];
	}
}


void PrintMenu()
{
	cout << "\t0 Удаление элемента из массива.\n" <<
		"\t1 Вставка элемента в начало массива.\n" <<
		"\t2 Вставка элемента в конец массива.\n" <<
		"\t3 Вставка после определенного элемента.\n" <<
		"\t4 Сортировка массива.\n" <<
		"\t5 Линеный поиск элемента в массиве.\n" <<
		"\t6 Бинарный поиск элемента в массиве.\n" <<
		"\t7 Выход из программы." << endl;
}