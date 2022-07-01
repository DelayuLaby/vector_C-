#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

std::vector<std::string> split(std::string string_for_split, std::string symbol);

class Line
{
private:
    int item_number = 0;
    std::string category;
    std::string subcategory2;
    std::string subcategory3;
    int vendor_code = 0;
    std::string name;
    double price;
    int quantity_of_goods = 0;
public:
    Line(const std::string& str);
    Line(int item_number, std::string category, std::string subcategory2,
        std::string subcategory3, int vendor_code, std::string name, double price, int q_of_gs);

    int get_item_number() const;
    std::string get_category() const;
    std::string get_subcategory2() const;
    std::string get_subcategory3() const;
    int get_vendor_code() const;
    std::string get_name() const;
    double get_price() const;
    int get_quantity_of_goods() const;

    void print_LINE();
};