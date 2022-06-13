#include "Vector.h"

void Catalog::sort_by_item_number() 
{ 
    bool (*funct)(const Line*, const Line*) = item_number_compare;
    std::sort(catalog_sorted_by_item_number.begin(), catalog_sorted_by_item_number.end(), funct);
}
void Catalog::sort_by_name() 
{ 
    bool (*funct)(const Line*, const Line*) = name_compare;
    std::sort(catalog_sorted_by_name.begin(), catalog_sorted_by_name.end(), funct);
}
void Catalog::sort_by_station_code() 
{ 
    bool (*funct)(const Line*, const Line*) = station_code_compare;
    std::sort(catalog_sorted_by_station_code.begin(), catalog_sorted_by_station_code.end(), funct);
}


void Catalog::fill_catalogs_for_sort()
{
    size_t size = general_catalog.size();
    catalog_sorted_by_item_number.resize(size);
    catalog_sorted_by_name.resize(size);
    catalog_sorted_by_station_code.resize(size);
    for (size_t i = 0; i < size; i++)
    {
        catalog_sorted_by_item_number.at(i) = &general_catalog.at(i);
        catalog_sorted_by_name.at(i) = &general_catalog.at(i);
        catalog_sorted_by_station_code.at(i) = &general_catalog.at(i);
    }
    sort_by_item_number();
    sort_by_name();
    sort_by_station_code();
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
    //search_in_cache(string_to_search, Choise);
    auto searche_number = 0;
    std::chrono::steady_clock::time_point begin, end;
    std::vector<Line>::iterator searche_line_it = general_catalog.end();
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
                /*to_cache(&(*i));*/
                (*i).print_LINE();
                searche_line_it = i;
                break;
            }
        }
        break;
    case '2':
        begin = std::chrono::high_resolution_clock().now();
        for (auto i = general_catalog.begin(); i < general_catalog.end(); i++)
        {
            if ((*i).get_name().find(string_to_search) != std::string::npos)
            {
                end = std::chrono::high_resolution_clock().now();
                /*to_cache(&(*i));*/
                (*i).print_LINE();
                searche_line_it = i;
            }
        }
        break;
    case '3':
        searche_number = std::stoi(string_to_search);
        begin = std::chrono::high_resolution_clock().now();
        for (auto i = general_catalog.begin(); i < general_catalog.end(); i++)
        {
            if ((*i).get_station_code() == searche_number)
            {
                end = std::chrono::high_resolution_clock().now();
                /*to_cache(&(*i));*/
                (*i).print_LINE();
                searche_line_it = i;
                break;
            }
        }
        break;
    default:
        std::cout << "What?\n";
    }
    std::chrono::duration<double> result = (end - begin) * 1000.;
    std::cout << "END. Search in catalog took " << result.count() << " ms" << std::endl << std::endl;
    return searche_line_it;
}

Line* Catalog::bin_searcher(const std::string& string_to_search, char Choise)
{
    /*Line* line_from_cache = search_in_cache(string_to_search, Choise);*/
    /*bool empty = false;
    if (line_from_cache == nullptr)
        empty = true;*/
    int searche_number = 0;
    int i = 0;
    if(Choise != '2')
        searche_number = std::stoi(string_to_search);
    std::chrono::steady_clock::time_point begin, end;
    std::vector<Line*>::iterator searche_line_it;
    Line a(searche_number, string_to_search, searche_number);
    bool (*funct)(const Line*, const Line*);
    switch (Choise)
    {
    case '1':
        /*if (empty == false && (*(line_from_cache)).get_item_number() == searche_number)
            (*line_from_cache).print_LINE();
        else
        {*/
            funct = item_number_compare;
            begin = std::chrono::high_resolution_clock().now();
            searche_line_it = lower_bound(catalog_sorted_by_item_number.begin(), catalog_sorted_by_item_number.end(), a, funct);
            end = std::chrono::high_resolution_clock().now();
            /*to_cache(*searche_line_it);*/
            (*(*searche_line_it)).print_LINE();
        //}
        break;
    case '2':
        //if (empty == false && (*(line_from_cache)).get_name() == string_to_search)
        //{
        //    (*line_from_cache).print_LINE();
        //    do
        //    {
        //        (*(line_from_cache + i)).print_LINE();     // (*(*(First + i))) получение указателя по итератору и последующее его разыменовывание 
        //        i++;
        //    } while (!(*(line_from_cache + i)).get_name().find(string_to_search));
        //}
        //else
        //{
            funct = name_compare;
            begin = std::chrono::high_resolution_clock().now();
            searche_line_it = lower_bound(catalog_sorted_by_name.begin(), catalog_sorted_by_name.end(), a, funct);
            end = std::chrono::high_resolution_clock().now();
            /*to_cache(*searche_line_it);*/
            do
            {
                (*(*(searche_line_it + i))).print_LINE();     // (*(*(First + i))) получение указателя по итератору и последующее его разыменовывание 
                i++;
            } while (!(*(*(searche_line_it + i))).get_name().find(string_to_search));
        //}
        break;
    case '3':
        /*if (empty == false && (*(line_from_cache)).get_station_code() == searche_number)
            (*line_from_cache).print_LINE();
        else
        {*/
            funct = station_code_compare;
            begin = std::chrono::high_resolution_clock().now();
            searche_line_it = lower_bound(catalog_sorted_by_station_code.begin(), catalog_sorted_by_station_code.end(), a, funct);
            end = std::chrono::high_resolution_clock().now();
            //to_cache(*searche_line_it);
            (*(*searche_line_it)).print_LINE();
        //}
        break;
    case 'q':
        break;
    default:
        std::cout << "What?\n";
    }
    std::chrono::duration<double> result = (end - begin) * 1000.;
    std::cout << "END. Binary search in catalog took " << result.count() << " ms" << std::endl << std::endl;
    return *searche_line_it;
}


void Catalog::print_Vec()
{
    std::cout << "--------------------------------Vector start--------------------------------" << std::endl;
    for (auto i = general_catalog.begin(); i != general_catalog.end(); i++)
    {
        (*i).print_LINE();
    }
    std::cout << "--------------------------------Vector ended--------------------------------" << std::endl;
}



