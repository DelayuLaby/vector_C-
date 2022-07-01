#pragma once
#include <algorithm> 
#include <chrono>
#include <unordered_map>
#include "Support_function.h"

std::unordered_multimap<Line*, int>::iterator Myfind(
	std::unordered_multimap<Line*, int>::iterator _first,
	std::unordered_multimap<Line*, int>::iterator _last,
	const Line& Val,
	char Choise);

class Cache
{
private:
	std::unordered_multimap<Line*, int> cache;
	int count = 0;
public:
	bool hit = false;
	Cache();

	void to_cache(Line* ptr);

	Line* search_in_cache(const std::string& string_to_search, char Choise);
};