#pragma once
#include <iostream>

class LINE
{
    int item_number = 0;
    std::string name;
    int station_code = 0;
public:
    LINE(const std::string&);
    LINE(int item_number, std::string name, int station_code);

    int get_item_number() const;

    std::string get_name() const;

    int get_station_code() const;

    void print_LINE();

};