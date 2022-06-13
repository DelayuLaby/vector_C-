#include "Line.h"


Line::Line(const std::string& str)
{
    auto pos = str.begin();
    for (auto i = str.begin(); i != str.end(); i++)
    {
        if ((int)(*i) == ';')
        {
            break;
        }
        item_number = item_number * 10 + (int)(*i) - 48;
        pos++;
    }
    pos++;
    for (auto i = pos; i != str.end(); i++)
    {
        if ((int)(*i) == ';')
        {
            break;
        }
        name.push_back(*i);
        pos++;
    }
    pos++;
    for (auto i = pos; i != str.end(); i++)
    {
        if ((int)(*i) == '\0')
        {
            break;
        }
        station_code = station_code * 10 + (int)(*i) - 48;
    }
}

Line::Line(int item_number, std::string name, int station_code) : item_number(item_number), name(name), station_code(station_code){ }

int Line::get_item_number() const { return item_number; }

std::string Line::get_name() const { return name; }

int Line::get_station_code() const { return station_code; }

void Line::print_LINE()
{
    std::cout << item_number << "; " << name << "; " << station_code << std::endl;
}