#include "class_LINE.h"


LINE::LINE(const std::string& str)
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

LINE::LINE(int item_number, std::string name, int station_code) : item_number(item_number), name(name), station_code(station_code){ }

int LINE::get_item_number() const { return this->item_number; }

std::string LINE::get_name() const { return this->name; }

int LINE::get_station_code() const { return this->station_code; }

void LINE::print_LINE()
{
    std::cout << this->item_number << "; " << this->name << "; " << station_code << std::endl;
}