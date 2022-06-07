#pragma once
#include <vector>
#include <chrono>
#include <algorithm> 
#include "class_LINE.h"

class Vec
{
public:
    std::vector<LINE> vec;
    Vec() = default;

    void add_LINE(const LINE&);
    void delete_line(std::vector<LINE>::iterator);

    void sort_by_item_number(int);
    void sort_by_name(int);
    void sort_by_station_code(int);

    std::vector<LINE>::iterator searcher(const std::string&);

    void print_Vec();
};