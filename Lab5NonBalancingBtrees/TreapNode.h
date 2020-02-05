#pragma once

template <typename T>
class TreapNode
{
public:
	TreapNode* Left;
	TreapNode* Right;
	T Key;
	T Priority;
};