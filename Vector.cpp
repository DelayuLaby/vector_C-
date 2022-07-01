#include "Vector.h"

void Catalog::sort_by_category()
{
    bool (*funct)(const Line*, const Line*) = category_compare;
    std::sort(catalog_sorted_by_category.begin(), catalog_sorted_by_category.end(), funct);
}
void Catalog::sort_by_vendor_code()
{
    bool (*funct)(const Line*, const Line*) = vendor_code_compare;
    std::sort(catalog_sorted_by_vendor_code.begin(), catalog_sorted_by_vendor_code.end(), funct);
}
void Catalog::sort_by_name() 
{ 
    bool (*funct)(const Line*, const Line*) = name_compare;
    std::sort(catalog_sorted_by_name.begin(), catalog_sorted_by_name.end(), funct);
}
void Catalog::sort_by_price()
{
    bool (*funct)(const Line*, const Line*) = price_compare;
    std::sort(catalog_sorted_by_price.begin(), catalog_sorted_by_price.end(), funct);
}
void Catalog::sort_by_q_of_goods()
{
    bool (*funct)(const Line*, const Line*) = q_of_goods_compare;
    std::sort(catalog_sorted_by_q_of_goods.begin(), catalog_sorted_by_q_of_goods.end(), funct);
}


void Catalog::fill_catalogs_for_sort()
{
    size_t size = general_catalog.size();
    catalog_sorted_by_category.resize(size);
    catalog_sorted_by_vendor_code.resize(size);
    catalog_sorted_by_name.resize(size);
    catalog_sorted_by_price.resize(size);
    catalog_sorted_by_q_of_goods.resize(size);
    for (size_t i = 0; i < size; i++)
    {
        catalog_sorted_by_category.at(i) = &general_catalog.at(i);
        catalog_sorted_by_vendor_code.at(i) = &general_catalog.at(i);
        catalog_sorted_by_name.at(i) = &general_catalog.at(i);
        catalog_sorted_by_price.at(i) = &general_catalog.at(i);
        catalog_sorted_by_q_of_goods.at(i) = &general_catalog.at(i);
    }
    sort_by_category();
    sort_by_vendor_code();
    sort_by_name();
    sort_by_price();
    sort_by_q_of_goods();
}


Catalog::Catalog(const std::string& file_name)
{
    std::ifstream file_out;
    file_out.open(file_name);
    std::string line;
    if (file_out.is_open())
    {
        while (getline(file_out, line))
        {
            if (line.at(0) <= 58 && line.at(0) >= 47)
            {
                general_catalog.emplace_back(Line(line));
            }
            else
            {
                continue;
            }
        }
        file_out.close();
    }
    else
    {
        std::cout << "\nFailed to open file\n";
    }
    fill_catalogs_for_sort();
}


void Catalog::add_LINE(const Line& line)
{
    general_catalog.emplace_back(line);
}

void Catalog::delete_line(std::vector<Line>::iterator it_del)
{
    if (it_del >= general_catalog.begin() && it_del < general_catalog.end())
        general_catalog.erase(it_del);
    else
        std::cout << "Incorrect iterator\n";
}


std::vector<Line>::iterator Catalog::searcher(const std::string& string_to_search, char Choise)
{
    auto searche_number = 0;
    auto searche_price = 0.;
    auto count_operation = 0;
    std::chrono::steady_clock::time_point begin, end;
    auto searche_line_it = general_catalog.end() - 1;
    switch (Choise)
    {
    case '1':
        searche_number = std::stoi(string_to_search);
        begin = std::chrono::high_resolution_clock().now();
        for (auto i = general_catalog.begin(); i < general_catalog.end(); i++)
        {
            if ((*i).get_item_number() == searche_number)
            {
                end = std::chrono::high_resolution_clock().now();
                (*i).print_LINE();
                count_operation++;
                searche_line_it = i;
                break;
            }
        }
        if (count_operation == 0)
            (*searche_line_it).print_LINE();
        break;
    case '2':
        begin = std::chrono::high_resolution_clock().now();
        for (auto i = general_catalog.begin(); i < general_catalog.begin(); i++)
        {
            if ((*i).get_category().find(string_to_search) != std::string::npos)
            {
                end = std::chrono::high_resolution_clock().now();
                (*i).print_LINE();
                if (count_operation == 0)
                    searche_line_it = i;
                count_operation++;
            }
        }
        if (count_operation == 0)
            (*searche_line_it).print_LINE();
        break;
    case '3':
        searche_number = std::stoi(string_to_search);
        begin = std::chrono::high_resolution_clock().now();
        for (auto i = general_catalog.begin(); i < general_catalog.end(); i++)
        {
            if ((*i).get_vendor_code() == searche_number)
            {
                end = std::chrono::high_resolution_clock().now();
                (*i).print_LINE();
                if (count_operation == 0)
                    searche_line_it = i;
                count_operation++;
            }
        }
        if (count_operation == 0)
            (*searche_line_it).print_LINE();
        break;
    case '4':
        begin = std::chrono::high_resolution_clock().now();
        for (auto i = general_catalog.begin(); i < general_catalog.begin(); i++)
        {
            if ((*i).get_name().find(string_to_search) != std::string::npos)
            {
                end = std::chrono::high_resolution_clock().now();
                (*i).print_LINE();
                if (count_operation == 0)
                    searche_line_it = i;
                count_operation++;
            }
        }
        if(count_operation == 0)
            (*searche_line_it).print_LINE();
        break;
    case '5':
        searche_price = std::stof(string_to_search);
        begin = std::chrono::high_resolution_clock().now();
        for (auto i = general_catalog.begin(); i < general_catalog.end(); i++)
        {
            if ((*i).get_price() == searche_price)
            {
                end = std::chrono::high_resolution_clock().now();
                (*i).print_LINE();
                if (count_operation == 0)
                    searche_line_it = i;
                count_operation++;
            }
        }
        if (count_operation == 0)
            (*searche_line_it).print_LINE();
        break;
    case '6':
        searche_number = std::stoi(string_to_search);
        begin = std::chrono::high_resolution_clock().now();
        for (auto i = general_catalog.begin(); i < general_catalog.end(); i++)
        {
            if ((*i).get_quantity_of_goods() == searche_number)
            {
                end = std::chrono::high_resolution_clock().now();
                (*i).print_LINE();
                if (count_operation == 0)
                    searche_line_it = i;
                count_operation++;
            }
        }
        if (count_operation == 0)
            (*searche_line_it).print_LINE();
        break;
    default:
        std::cout << "What?\n";
    }
    std::chrono::duration<double> time_result = (end - begin) * 1000.;
    std::cout << "END. Search in catalog took " << time_result.count() << " ms" << std::endl << std::endl;
    return searche_line_it;
}

Line* Catalog::bin_searcher(const std::string& string_to_search, char Choise)
{
    int searche_number = 0;
    double searche_price = 0;
    int i = 0;
    if (Choise != '2' && Choise != '4')
    {
        searche_number = std::stoi(string_to_search);
        searche_price = std::stof(string_to_search);
    }
    std::chrono::steady_clock::time_point begin, end;
    std::vector<Line*>::iterator searche_line_it;
    std::vector<Line>::iterator searche_line_it_it_num;
    Line* result = nullptr;
    Line temp_line(searche_number, string_to_search, string_to_search, string_to_search, searche_number, string_to_search, searche_price, searche_number);
    switch (Choise)
    {
    case '1':
        begin = std::chrono::high_resolution_clock().now();
        searche_line_it_it_num = std::lower_bound(general_catalog.begin(), general_catalog.end() - 1, temp_line, &item_number_compare);
        end = std::chrono::high_resolution_clock().now();
        (*searche_line_it_it_num).print_LINE();
        result = &(*searche_line_it_it_num);
        break;
    case '2':
        begin = std::chrono::high_resolution_clock().now();
        searche_line_it = std::lower_bound(catalog_sorted_by_category.begin(), catalog_sorted_by_category.end() - 1, &temp_line, &category_compare);
        end = std::chrono::high_resolution_clock().now();
        do
        {
            (*(searche_line_it + i))->print_LINE();
            i++;
        } while (!(*(searche_line_it + i))->get_category().find(string_to_search));
        result = *searche_line_it;
        break;
    case '3':
        begin = std::chrono::high_resolution_clock().now();
        searche_line_it = std::lower_bound(catalog_sorted_by_vendor_code.begin(), catalog_sorted_by_vendor_code.end() - 1, &temp_line, &vendor_code_compare);
        end = std::chrono::high_resolution_clock().now();
        do
        {
            (*(searche_line_it + i))->print_LINE();
            i++;
        } while ((*(searche_line_it + i))->get_vendor_code() == searche_number);
        result = *searche_line_it;
        break;
    case '4':
        begin = std::chrono::high_resolution_clock().now();
        searche_line_it = std::lower_bound(catalog_sorted_by_name.begin(), catalog_sorted_by_name.end() - 1, &temp_line, &name_compare);
        end = std::chrono::high_resolution_clock().now();
        do
        {
            (*(searche_line_it + i))->print_LINE();     
            i++;
        } while (!(*(searche_line_it + i))->get_name().find(string_to_search));
        result = *searche_line_it;
        break;
    case '5':
        begin = std::chrono::high_resolution_clock().now();
        searche_line_it = std::lower_bound(catalog_sorted_by_price.begin(), catalog_sorted_by_price.end() - 1, &temp_line, &price_compare);
        end = std::chrono::high_resolution_clock().now();
        do
        {
            (*(searche_line_it + i))->print_LINE();
            i++;
        } while ((*(searche_line_it + i))->get_price() == searche_price);
        result = *searche_line_it;
        break;
    case '6':
        begin = std::chrono::high_resolution_clock().now();
        searche_line_it = std::lower_bound(catalog_sorted_by_q_of_goods.begin(), catalog_sorted_by_q_of_goods.end() - 1, &temp_line, &q_of_goods_compare);
        end = std::chrono::high_resolution_clock().now();
        do
        {
            (*(searche_line_it + i))->print_LINE();
            i++;
        } while ((*(searche_line_it + i))->get_quantity_of_goods() == searche_number);
        result = *searche_line_it;
        break;
    case 'q':
        break;
    default:
        std::cout << "What?\n";
    }
        std::chrono::duration<double> time_result = (end - begin) * 1000.;
        std::cout << "END. Binary search in catalog took " << time_result.count() << " ms" << std::endl << std::endl;
        return result;
    }


    void Catalog::print_catalog()
    {
        std::cout << "--------------------------------Vector start--------------------------------" << std::endl;
        for (auto i = general_catalog.begin(); i != general_catalog.end(); i++)
        {
            (*i).print_LINE();
        }
        std::cout << "--------------------------------Vector ended--------------------------------" << std::endl;
    }
