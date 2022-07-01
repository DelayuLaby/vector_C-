#pragma once
#include <fstream>
#include "Cache.h"

class Catalog
{
private:
    std::vector<Line> general_catalog;
    std::vector<Line*> catalog_sorted_by_category;
    std::vector<Line*> catalog_sorted_by_vendor_code;
    std::vector<Line*> catalog_sorted_by_name;
    std::vector<Line*> catalog_sorted_by_price;
    std::vector<Line*> catalog_sorted_by_q_of_goods;

    void sort_by_category();
    void sort_by_vendor_code();
    void sort_by_name();
    void sort_by_price();
    void sort_by_q_of_goods();

    void fill_catalogs_for_sort();
public:
    Catalog(const std::string& file_name);

    void add_LINE(const Line& line);
    void delete_line(std::vector<Line>::iterator it_del);

    std::vector<Line>::iterator searcher(const std::string& string_to_search, char Choise);
    Line* bin_searcher(const std::string& string_to_search, char Choise);

    void print_catalog();
};