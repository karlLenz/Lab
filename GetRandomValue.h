#pragma once
#include <random>

template <typename T>
inline std::enable_if_t<!std::is_floating_point<T>::value, T>
GetRandomValue(T min = T(), T max = INT8_MAX)
{
	std::random_device randomDevice;
	std::default_random_engine randomEngine(randomDevice());
	std::uniform_int_distribution<T> uniformDistribution(min, max);

	return uniformDistribution(randomEngine);
}


template <typename T>
inline std::enable_if_t<std::is_floating_point<T>::value, T>
GetRandomValue(T min = T(), T max = FLT_MAX)
{
	std::random_device randomDevice;
	std::default_random_engine randomEngine(randomDevice());
	std::uniform_real_distribution<T> uniformDistribution(min, max);

	return uniformDistribution(randomEngine);
}