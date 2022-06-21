#include "Vector.h"


int main()
{
    std::string line;
    Catalog victor("stations.csv");
    Cache cache;
    Line* ptr;
    std::string Search_str;
    std::ifstream auto_test;
    auto_test.open("auto_test1.txt");
    do
    {
        std::cout << "Binary search?    y - yes, n - no: " << std::endl;
        //std::cin >> line;
        getline(auto_test, line);
        std::cout << "  " << line << std::endl;
        if (line == "y") 
        {
            std::cout << "Enter string to search" << std::endl;
            //std::cin >> Search_str;
            getline(auto_test, Search_str);
            std::cout << "  " << Search_str << std::endl;
            std::cout << "Search by...\n" << "\t1 - Item Number\n" << "\t2 - Name\n" << "\t3 - Station code\n" << "Enter -q- to exit\n";
            //std::cin >> line;
            getline(auto_test, line);
            std::cout << "  " << line << std::endl;
            ptr = cache.search_in_cache(Search_str, line[0]);
            if (cache.hit)
            {
                std::cout << "HIT cache\n";
                ptr->print_LINE();
            }
            else
            {
                std::cout << "Error cache\n";
                auto from_catalog = victor.bin_searcher(Search_str, line[0]);
                cache.to_cache(*from_catalog);
            }
        }
        else
        {
            std::cout << "Enter string to search" << std::endl;
            getline(auto_test, Search_str);
            std::cout << "  " << Search_str << std::endl;
            //std::cin >> Search_str;
            std::cout << "Search by...\n" << "\t1 - Item Number\n" << "\t2 - Name\n" << "\t3 - Station code\n" << "Enter -q- to exit\n";
            getline(auto_test, line);
            std::cout << "  " << line << std::endl;
            //std::cin >> line;
            ptr = cache.search_in_cache(Search_str, line[0]);
            if (cache.hit)
            {
                std::cout << "HIT cache\n";
                ptr->print_LINE();
            }
            else
            {
                std::cout << "Error cache\n";
                auto from_catalog = victor.searcher(Search_str, line[0]);
                cache.to_cache(&(*from_catalog));
            }
        }
        std::cout << "Again?    y - yes, n - no:\n";
        getline(auto_test, line);
        std::cout << "  " << line << std::endl << std::endl << std::endl;
    } while (line == "y");
    return 0;



    //std::chrono::steady_clock::time_point begin, end;
    //std::unordered_map<int, int> aby;
    //aby.max_load_factor(64);
    //std::vector<int> b;
    //for (auto i = 0; i < 1000000; i++)
    //{
    //    aby[i] = i;
    //    b.push_back(i);
    //}
    //begin = std::chrono::high_resolution_clock().now();
    //aby.find(500000);
    //end = std::chrono::high_resolution_clock().now();
    //std::chrono::duration<double> result = (end - begin) * 1000000.;
    //std::cout << "1)" << result.count() << std::endl;

    //begin = std::chrono::high_resolution_clock().now();
    //for (auto& i : b)
    //    if (b[i] == 500000)
    //        break;
    //end = std::chrono::high_resolution_clock().now();
    //result = (end - begin) * 1000000.;
    //std::cout << "2)" << result.count() << std::endl;
    ///*for (auto i = aby.begin(); i != aby.end(); i++)
    //    std::cout << (*i).first << ":" << (*i).second << std::endl;*/
    //std::cout << "\n" << aby.bucket_count() << " " << aby.max_bucket_count() << std::endl;
}


//работа с кешем: unordered_map
//потоки
//понельник 17:00