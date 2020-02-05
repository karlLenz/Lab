#pragma once
#include <chrono>
#include <iostream>

class Timer
{
public:
	using clock = std::chrono::high_resolution_clock;
	Timer() : _start(clock::now()) {}

	~Timer()
	{
		_finish = clock::now();
		duration = (_finish - _start);
		std::cout << std::fixed << "duration = " << duration.count() <<
			" sec";
	}

private:
	clock::time_point _start;
	clock::time_point _finish;
	std::chrono::duration<long double> duration;
};