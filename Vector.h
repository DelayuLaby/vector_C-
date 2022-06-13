#pragma once
#include <chrono>
#include <fstream>
#include "Cache.h"

class Catalog 
{
private:
    std::vector<Line> general_catalog;
    std::vector<Line*> catalog_sorted_by_item_number;
    std::vector<Line*> catalog_sorted_by_name;
    std::vector<Line*> catalog_sorted_by_station_code;

    void sort_by_item_number();
    void sort_by_name();
    void sort_by_station_code();

    void fill_catalogs_for_sort();
public:
    Catalog(const std::string& file_name);

    void add_LINE(const Line& line);
    void delete_line(std::vector<Line>::iterator it_del);

    std::vector<Line>::iterator searcher(const std::string& string_to_search, char Choise);
    Line* bin_searcher(const std::string& string_to_search, char Choise);

    void print_Vec();
};