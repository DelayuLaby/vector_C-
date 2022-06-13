#include "Cache.h"

void Cache::cache_sort_by_item_number()
{
    bool (*funct)(const Line*, const Line*) = item_number_compare;
    std::sort(cache_sorted_by_item_number.begin(), cache_sorted_by_item_number.begin() + size, funct);
}

void Cache::cache_sort_by_name()
{
    bool (*funct)(const Line*, const Line*) = item_number_compare;
    std::sort(cache_sorted_by_name.begin(), cache_sorted_by_name.begin() + size, funct);
}

void Cache::cache_sort_by_station_code()
{
    bool (*funct)(const Line*, const Line*) = item_number_compare;
    std::sort(cache_sorted_by_station_code.begin(), cache_sorted_by_station_code.begin() + size, funct);
}


Cache::Cache() : count(0), size(0)
{ }


void Cache::to_cache(Line* ptr)
{
    if (size < 99)
        size++;
	if (count < 99) 
	{
		cache_sorted_by_item_number.at(count) = ptr;
		cache_sorted_by_name.at(count) = ptr;
		cache_sorted_by_station_code.at(count) = ptr;
		count++;
	}
	else
	{
		cache_sorted_by_item_number.at(count) = ptr;
		cache_sorted_by_name.at(count) = ptr;
		cache_sorted_by_station_code.at(count) = ptr;
		count = 0;
	}
    if (size > 1)
    {
        cache_sort_by_item_number();
        cache_sort_by_name();
        cache_sort_by_station_code();
    }
}


Line* Cache::search_in_cache(const std::string& string_to_search, char Choise)
{
    std::vector<Line*>::iterator search_line_it;
    int searche_number = 0;
    int i = 0;
    if (Choise != '2')
        searche_number = std::stoi(string_to_search);
    std::chrono::steady_clock::time_point begin, end;
    Line a(searche_number, string_to_search, searche_number);
    bool (*funct)(const Line*, const Line*);
    if (size == 1)
    {
        switch (Choise)
        {
        case '1':
            begin = std::chrono::high_resolution_clock().now();
            if (a.get_item_number() == (*(*cache_sorted_by_item_number.begin())).get_item_number())
                search_line_it = cache_sorted_by_item_number.begin();
            end = std::chrono::high_resolution_clock().now();
            break;
        case '2':
            begin = std::chrono::high_resolution_clock().now();
            if (a.get_name() == (*(*cache_sorted_by_name.begin())).get_name())
                search_line_it = cache_sorted_by_name.begin();
            end = std::chrono::high_resolution_clock().now();
            break;
        case '3':
            begin = std::chrono::high_resolution_clock().now();
            if (a.get_station_code() == (*(*cache_sorted_by_station_code.begin())).get_station_code())
                search_line_it = cache_sorted_by_station_code.begin();
            end = std::chrono::high_resolution_clock().now();
            break;
        case 'q':
            break;
        default:
            std::cout << "What in cache?\n";
        }
        std::chrono::duration<double> result = (end - begin) * 1000.;
        std::cout << "END. Search in cache took " << result.count() << " ms" << std::endl << std::endl;
        return *search_line_it;
    }
    else if (size > 1) 
    {
        switch (Choise)
        {
        case '1':
            funct = item_number_compare;
            begin = std::chrono::high_resolution_clock().now();
            search_line_it = lower_bound(cache_sorted_by_item_number.begin(), cache_sorted_by_item_number.end(), a, funct);
            end = std::chrono::high_resolution_clock().now();
            //(*(*search_line_it)).print_LINE();
            break;
        case '2':
            funct = name_compare;
            begin = std::chrono::high_resolution_clock().now();
            search_line_it = lower_bound(cache_sorted_by_name.begin(), cache_sorted_by_name.end(), a, funct);
            end = std::chrono::high_resolution_clock().now();
            //do
            //{
            //    (*(*(search_line_it + i))).print_LINE();     // (*(*(First + i))) получение указателя по итератору и последующее его разыменовывание 
            //    i++;
            //} while (!(*(*(search_line_it + i))).get_name().find(string_to_search));
            break;
        case '3':
            funct = station_code_compare;
            begin = std::chrono::high_resolution_clock().now();
            search_line_it = lower_bound(cache_sorted_by_station_code.begin(), cache_sorted_by_station_code.end(), a, funct);
            end = std::chrono::high_resolution_clock().now();
            //(*(*search_line_it)).print_LINE();
            break;
        case 'q':
            break;
        default:
            std::cout << "What in cache?\n";
        }
        std::chrono::duration<double> result = (end - begin) * 1000.;
        std::cout << "END. Search in cache took " << result.count() << " ms" << std::endl << std::endl;
        return *search_line_it;
    }
    else
    {
        std::cout << "Cache is empty " << std::endl << std::endl;
        return nullptr;
    }
}
