#include "Vector.h"


std::mutex console_mtx;
std::mutex cache_mtx;


auto Search(Catalog& some_catalog, Cache& some_cache, std::string test)
{
    auto Cat_ptr = &some_catalog;
    auto Cache_ptr = &some_cache;    
    auto c = std::this_thread::get_id();
    std::ifstream auto_test;
    auto_test.open(test);
    if (auto_test.is_open())
    {
        std::string Search_str;
        std::string line;
        Line* ptr;
        bool H_M;
        do
        {
            console_mtx.lock();
            std::cout << "ID: " << c << ") Binary search?    y - yes, n - no: " << std::endl;
            console_mtx.unlock();
            //std::cin >> line;
            getline(auto_test, line);
            console_mtx.lock();
            std::cout << "ID: " << c << ")  " << line << std::endl;
            console_mtx.unlock();
            if (line == "y")
            {
                console_mtx.lock();
                std::cout << "ID: " << c << ") Enter string to search" << std::endl;
                console_mtx.unlock();
                //std::cin >> Search_str;
                getline(auto_test, Search_str);
                console_mtx.lock();
                std::cout << "ID: " << c << ")  " << Search_str << std::endl;
                std::cout << "ID: " << c << ") Search by...\n" << "  1 - Item Number\n" <<
                    "  2 - Category\n" << "  3 - Vendor code\n" <<
                    "  4 - Name\n" << "  5 - Price\n" <<
                    "  6 - quantity of goods\n" << "Enter -q- to exit\n";
                console_mtx.unlock();
                //std::cin >> line;
                getline(auto_test, line);
                console_mtx.lock();
                std::cout << "ID: " << c << ")  " << line << std::endl;
                ptr = some_cache.search_in_cache(Search_str, line[0]);
                H_M = some_cache.hit;
                console_mtx.unlock();
                if (H_M)
                {
                    std::cout << "ID: " << c << ") HIT cache\n";
                    ptr->print_LINE();
                }
                else
                {
                    std::cout << "ID: " << c << ") MISS cache\n";
                    auto from_catalog = some_catalog.bin_searcher(Search_str, line[0]);
                    cache_mtx.lock();
                    some_cache.to_cache(from_catalog);
                    cache_mtx.unlock();
                }
            }
            else
            {
                console_mtx.lock();
                std::cout << "ID: " << c << ") Enter string to search" << std::endl;
                console_mtx.unlock();
                getline(auto_test, Search_str);
                console_mtx.lock();
                std::cout << "ID: " << c << ")  " << Search_str << std::endl;
                //std::cin >> Search_str;
                std::cout << "ID: " << c << ") Search by...\n" << "  1 - Item Number\n" <<
                    "  2 - Category\n" << "  3 - Vendor code\n" <<
                    "  4 - Name\n" << "  5 - Price\n" <<
                    "  6 - quantity of goods\n" << "Enter -q- to exit\n";
                console_mtx.unlock();
                getline(auto_test, line);
                console_mtx.lock();
                std::cout << "ID: " << c << ")  " << line << std::endl;
                //std::cin >> line;
                ptr = some_cache.search_in_cache(Search_str, line[0]);
                H_M = some_cache.hit;
                console_mtx.unlock();
                if (H_M)
                {
                    std::cout << "ID: " << c << ") HIT cache\n";
                    ptr->print_LINE();
                }
                else
                {
                    std::cout << "ID: " << c << ") MISS cache\n";
                    auto from_catalog = some_catalog.searcher(Search_str, line[0]);
                    cache_mtx.lock();
                    some_cache.to_cache(&(*from_catalog));
                    cache_mtx.unlock();
                }
            }
            console_mtx.lock();
            std::cout << "ID: " << c << ") Again?    y - yes, n - no:\n";
            console_mtx.unlock();
            getline(auto_test, line);
            console_mtx.lock();
            std::cout << "ID: " << c << ")  " << line << std::endl << std::endl << std::endl;
            console_mtx.unlock();
        } while (line == "y");
    }
    else
    {
        std::cout << "ID: " << c << ") User is disconnected\n";
    }
    
}


int main()
{
    setlocale(LC_ALL, "ru");
    Catalog victor("Vlad_by.csv");
    Cache cache;
    std::thread t1(&Search,std::ref(victor), std::ref(cache), "auto_test1.txt");
    std::thread t2(&Search, std::ref(victor), std::ref(cache), "auto_test2.txt");

    t1.join();
    t2.join();
    return 0;
    
    
}


//работа с кешем: unordered_map
//потоки , lock_guard, unic_lock
//четверг 17:00