#pragma once

struct DynamicArray
{
	int *Array;
	size_t Size;
	size_t MaxSize;
	bool IsSorted;
};

DynamicArray* CreateDynamicArray();
void AddElement(DynamicArray*);
void ResizeArray(DynamicArray*);
void InsertElement(DynamicArray*, size_t, int);
void DeleteElement(DynamicArray*, size_t);
void LinearSearch(const DynamicArray*, int);
void InsertionSort(DynamicArray*);
void BinarySearch(const DynamicArray*, int);
void DeleteDynamicArray(const DynamicArray*);

void FillArray(DynamicArray*);
void PrintArray(const DynamicArray*);
void CopyArray(const DynamicArray*, int*);
void PrintMenu();