#include "Vector.h"


int main()
{
    std::string line;
    Catalog victor("stations.csv");
    std::string Search_str;
    do
    {
        std::cout << "Binary search?    y - yes, n - no: " << std::endl;
        std::cin >> line;
        if (line == "y") 
        {
            std::cout << "Enter string to search" << std::endl;
            std::cin >> Search_str;
            std::cout << "Search by...\n" << "\t1 - Item Number\n" << "\t2 - Name\n" << "\t3 - Station code\n" << "Enter -q- to exit\n";
            std::cin >> line;
            victor.bin_searcher(Search_str, line[0]);
        }
        else
        {
            std::cout << "Enter string to search" << std::endl;
            std::cin >> Search_str;
            std::cout << "Search by...\n" << "\t1 - Item Number\n" << "\t2 - Name\n" << "\t3 - Station code\n" << "Enter -q- to exit\n";
            std::cin >> line;
            victor.searcher(Search_str, line[0]);
        }
        std::cout << "Again?    y - yes, n - no: ";
        std::cin >> line;
    } while (line == "y");

    return 0;
}


