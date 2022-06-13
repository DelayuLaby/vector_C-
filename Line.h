#pragma once
#include <iostream>
#include <string>

class Line
{
private:
    int item_number = 0;
    std::string name;
    int station_code = 0;
public:
    Line(const std::string& str);
    Line(int item_number, std::string name, int station_code);

    int get_item_number() const;
    std::string get_name() const;
    int get_station_code() const;

    void print_LINE();
};