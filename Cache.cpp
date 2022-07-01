#include "Cache.h"

std::unordered_multimap<Line*, int>::iterator Myfind(
    std::unordered_multimap<Line*, int>::iterator _first,
    std::unordered_multimap<Line*, int>::iterator _last,
    const Line& Val, 
    char Choise)
{
    switch (Choise)
    {
    case '1':
        for (; _first != _last; ++_first) {
            if ((*_first).first->get_item_number() == Val.get_item_number()) {
                return _first;
            }
        }
        return _last;
        break;
    case '4':
        for (; _first != _last; ++_first) {
            if ((*_first).first->get_name() == Val.get_name()) {
                return _first;
            }
        }
        return _last;
        break;
    case '3':
        for (; _first != _last; ++_first) {
            if ((*_first).first->get_vendor_code() == Val.get_vendor_code()) {
                return _first;
            }
        }
        return _last;
        break;
    case '2':
        for (; _first != _last; ++_first) {
            if ((*_first).first->get_category() == Val.get_category()) {
                return _first;
            }
        }
        return _last;
        break;
    case '5':
        for (; _first != _last; ++_first) {
            if ((*_first).first->get_price() == Val.get_price()) {
                return _first;
            }
        }
        return _last;
        break;
    default:
        return _last;
    }
}

Cache::Cache()
{ 
	cache.reserve(64);
    cache.max_load_factor(8);
}

void Cache::to_cache(Line* ptr)
{
    for (auto i = cache.begin(); i != cache.end(); i++)
    {
        if ((*i).second == count)
        {
            cache.erase(i);
            break;
        }
    }
	if (count < 99) 
	{
        cache.insert(std::make_pair(ptr, count));
		count++;
	}
	else 
	{
        cache.insert(std::make_pair(ptr, count));
		count = 0;
	}
}


Line* Cache::search_in_cache(const std::string& string_to_search, char Choise)      
{
    hit = false;
    std::unordered_multimap<Line*, int>::iterator search_line_it;
    auto searche_number = 0;
    auto searche_price = 0.;
    if (Choise != '2' && Choise != '4')
    {
        auto searche_number = std::stoi(string_to_search);
        auto searche_price = std::stof(string_to_search);
    }
    std::chrono::steady_clock::time_point begin, end;
    Line temp_line(searche_number, string_to_search, string_to_search, string_to_search, searche_number, string_to_search, searche_price, searche_number);
    begin = std::chrono::high_resolution_clock().now();
    search_line_it = Myfind(cache.begin(), cache.end(), temp_line, Choise);
    end = std::chrono::high_resolution_clock().now();
    if (search_line_it != cache.end())
        hit = true;
    std::chrono::duration<double> time_result = (end - begin) * 1000.;
    std::cout << "END. Search in cache took " << time_result.count() << " ms" << std::endl << std::endl;
    return (*search_line_it).first;
}
