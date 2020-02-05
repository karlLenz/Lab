#pragma once
#include "StructList.h"

List* CreateList();
void AddNode(List*, int);
void DeleteNode(List*, size_t);
void InsertNode(List*, size_t, int);
void BubbleSort(List*);
void LinearSearch(const List*, int);
void DeleteList(const List*);

inline Node* GetNode(const List*, size_t);
inline void SwapNode(List*, Node*);