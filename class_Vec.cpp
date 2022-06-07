#include "class_Vec.h"

void Vec::add_LINE(const LINE& obj)
{
    vec.push_back(obj);
}

void Vec::delete_line(std::vector<LINE>::iterator it_del)
{
    if (it_del >= this->vec.begin() && it_del < this->vec.end())
        this->vec.erase(it_del);
    else
        std::cout << "Incorrect iterator\n";
}

//___________________________—ортировка элементов вектора по номеру___________________________//
void Vec::sort_by_item_number(int flg_sort)
{
    if (flg_sort == 1)
    {
        std::sort(this->vec.begin(), this->vec.end(), [](LINE& a, LINE& b) ->bool        //сортировка от большего к меньшему//
            { return (a.get_item_number() < b.get_item_number()); });
    }
    else if (flg_sort == 0)
    {
        std::sort(this->vec.begin(), this->vec.end(), [](LINE& a, LINE& b) ->bool        //сортировка от меньшего к большему//
            { return (a.get_item_number() > b.get_item_number()); });
    }
}


//___________________________—ортировка элементов вектора по имени___________________________//
void Vec::sort_by_name(int flg_sort)
{
    if (flg_sort == 1)
    {
        std::sort(this->vec.begin(), this->vec.end(), [](LINE& a, LINE& b) ->bool     //сортировка от большего к меньшему//
            { return (a.get_name() < b.get_name()); });
    }
    else if (flg_sort == 0)
    {
        std::sort(this->vec.begin(), this->vec.end(), [](LINE& a, LINE& b) ->bool        //сортировка от меньшего к большему//
            { return (a.get_name() > b.get_name()); });
    }
}


//___________________________—ортировка элементов вектора по коду станции___________________________//
void Vec::sort_by_station_code(int flg_sort)
{
    if (flg_sort == 1)
    {
        std::sort(this->vec.begin(), this->vec.end(), [](LINE& a, LINE& b) ->bool        //сортировка от большего к меньшему//
            { return (a.get_station_code() < b.get_station_code()); });
    }
    else if (flg_sort == 0)
    {
        std::sort(this->vec.begin(), this->vec.end(), [](LINE& a, LINE& b) ->bool        //сортировка от меньшего к большему//
            { return (a.get_station_code() > b.get_station_code()); });
    }
}




//___________________________ѕоиск элементов по одному из полей LINE___________________________//
std::vector<LINE>::iterator Vec::searcher(const std::string& string_to_search)
{
    char Choise;
    std::cout << "Do you want use binary searche?\n" << "\ty - yes / anuthing else - no\n\t";
    std::cin >> Choise;
    int temp = 0;
    auto begin = std::chrono::high_resolution_clock().now();
    std::vector<LINE>::iterator T;
    if (Choise == 'y')
    {
        std::cout << "Search by...\n" << "\t1 - Item Number\n" << "\t2 - Name\n" << "\t3 - Station code\n" << "Enter -q- to exit\n";
        std::cin >> Choise;
        begin = std::chrono::high_resolution_clock().now();
        switch (Choise)
        {
        case '1':
            for (auto i = string_to_search.begin(); i != string_to_search.end(); i++)
            {
                temp = temp * 10 + (int)(*i) - 48;        //ѕри поиске по числу преобразуем строку в число
            }
            sort_by_item_number(0);
            T = std::lower_bound(this->vec.begin(), this->vec.end(), LINE(temp, "", 0),
                [](LINE& a, LINE b) ->bool { return (a.get_item_number() > b.get_item_number()); });
            (*T).print_LINE();
            break;
        case '2':
            sort_by_name(0);
            T = std::lower_bound(this->vec.begin(), this->vec.end(), LINE(0, string_to_search, 0),
                [](LINE& a, LINE b) ->bool { return (a.get_name() > b.get_name()); });
            (*T).print_LINE();
            break;
            break;
        case '3':
            for (auto i = string_to_search.begin(); i != string_to_search.end(); i++)
            {
                temp = temp * 10 + (int)(*i) - 48;        //ѕри поиске по числу преобразуем строку в число
            }
            sort_by_station_code(0);
            T = std::lower_bound(this->vec.begin(), this->vec.end(), LINE(0, "", temp),
                [](LINE& a, LINE b) ->bool { return (a.get_station_code() > b.get_station_code()); });
            (*T).print_LINE();
            
            break;
        case 'q':
            break;
        default:
            std::cout << "What?\n";
        }
        auto end = std::chrono::high_resolution_clock().now();
        std::chrono::duration<double> result = end - begin;
        std::cout << "END. Search in Victor is " << result.count() << std::endl << std::endl;
        return this->vec.end();
    }
    else
    {
        std::cout << "Search by...\n" << "\t1 - Item Number\n" << "\t2 - Name\n" << "\t3 - Station code\n" << "Enter -q- to exit\n";
        std::cin >> Choise;
        begin = std::chrono::high_resolution_clock().now();
        switch (Choise)
        {
        case '1':
            for (auto i = string_to_search.begin(); i != string_to_search.end(); i++)
            {
                temp = temp * 10 + (int)(*i) - 48;        //ѕри поиске по числу преобразуем строку в число
            }

            for (auto i = this->vec.begin(); i < this->vec.end(); i++)
            {
                if ((*i).get_item_number() == temp)
                {
                    (*i).print_LINE();
                    break;
                }
            }
            break;
        case '2':
            for (auto i = this->vec.begin(); i < this->vec.end(); i++)
            {
                if ((*i).get_name().find(string_to_search) != std::string::npos)
                {
                    (*i).print_LINE();
                    break;
                }
            }
            break;
        case '3':
            for (auto i = string_to_search.begin(); i != string_to_search.end(); i++)
            {
                temp = temp * 10 + (int)(*i) - 48;        //ѕри поиске по числу преобразуем строку в число
            }

            for (auto i = this->vec.begin(); i < this->vec.end(); i++)
            {
                if ((*i).get_station_code() == temp)
                {
                    (*i).print_LINE();
                    break;
                }

            }
            break;
        case 'q':
            break;
        default:
            std::cout << "What?\n";
        }
        auto end = std::chrono::high_resolution_clock().now();
        std::chrono::duration<double> result = end - begin;
        std::cout << "END. Search in Victor is " << result.count() << std::endl << std::endl;
        return this->vec.end();
    }
}


//__________________________¬ывод вектора в консоль__________________________
void Vec::print_Vec()
{
    std::cout << "--------------------------------Vector start--------------------------------" << std::endl;
    for (auto i = this->vec.begin(); i != this->vec.end(); i++)
    {
        (*i).print_LINE();
    }
    std::cout << "--------------------------------Vector ended--------------------------------" << std::endl;
}