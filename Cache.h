#pragma once
#include <algorithm> 
#include <chrono>
#include "Support_function.h"

bool item_number_compare(const Line* a, const Line* b);
bool name_compare(const Line* a, const Line* b);
bool station_code_compare(const Line* a, const Line* b);

std::vector<Line*>::iterator lower_bound(std::vector<Line*>::iterator _FirstIt, std::vector<Line*>::iterator _SecondIt, const Line& val, bool (*comp)(const Line* a, const Line* b));


class Cache
{
private:
	std::vector<Line*> cache_sorted_by_item_number;
	std::vector<Line*> cache_sorted_by_name;
	std::vector<Line*> cache_sorted_by_station_code;
	int count;
	int size;

	void cache_sort_by_item_number();
	void cache_sort_by_name();
	void cache_sort_by_station_code();
public:
	Cache();

	void to_cache(Line* ptr);

	Line* search_in_cache(const std::string& string_to_search, char Choise);
};