#include "Line.h"


std::vector<std::string> split(std::string string_for_split, std::string symbol)
{
    std::vector<std::string> temp;
    size_t next;
    auto i = 0;
    auto _first_it = string_for_split.begin();
    auto symbol_size = symbol.size();
    while ((next = string_for_split.find(symbol)) != std::string::npos)
    {
        temp.emplace_back(string_for_split.substr(0, next));
        string_for_split.erase(_first_it, _first_it + next + symbol_size);
        i++;
    }
    temp.emplace_back(string_for_split.substr(0, string_for_split.size()));
    string_for_split.clear();
    return temp;
}


Line::Line(const std::string& str)
{
    std::vector<std::string> split_strings = split(str, ";");
    item_number = std::stoi(split_strings[0]);
    category = split_strings[1];
    subcategory2 = split_strings[2];
    subcategory3 = split_strings[3];
    vendor_code = std::stoi(split_strings[4]);
    name = split_strings[5];
    price = std::stof(split_strings[6]);
    quantity_of_goods = std::stoi(split_strings[7]);
}

Line::Line(int item_number, std::string category, std::string subcategory2, 
    std::string subcategory3, int vendor_code, std::string name, double price, int q_of_gs) 
    : item_number(item_number), category(category), subcategory2(subcategory2), subcategory3(subcategory3), vendor_code(vendor_code), name(name), price(price), quantity_of_goods(q_of_gs){ }

int Line::get_item_number() const { return item_number; }
std::string Line::get_category() const { return category; }
std::string Line::get_subcategory2() const { return subcategory2; }
std::string Line::get_subcategory3() const { return subcategory3; }
int Line::get_vendor_code() const { return vendor_code; }
std::string Line::get_name() const { return name; }
double Line::get_price() const { return price; }
int Line::get_quantity_of_goods() const { return quantity_of_goods; }

void Line::print_LINE()
{
    std::cout << item_number << "; " << category << "; " << subcategory2 << "; " << subcategory3 << "; " 
        << vendor_code << "; " << name << "; " << price << "$; " << quantity_of_goods << std::endl;
}