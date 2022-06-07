#include <fstream>
#include <string>
#include "class_Vec.h"


int main()
{
    std::ifstream file_out;
    std::string line;
    std::string answer;
    Vec victor;
    file_out.open("stations.csv");
    std::cout << "Start!!!" << std::endl << std::endl;
    std::chrono::steady_clock::time_point begin, end;
    if (file_out.is_open())
    {
        begin = std::chrono::high_resolution_clock().now();
        while (getline(file_out, line))
        {
            if (line[0] <= 58 && line[0] >= 47)
            {
                LINE temp(line);
                victor.add_LINE(temp);
            }
            else
            {
                continue;
            }
        }
        end = std::chrono::high_resolution_clock().now();
    }
    file_out.close();
    std::chrono::duration<double> result = end - begin;
    std::cout << "END. Write in Victor is " << result.count() << std::endl << std::endl;
    victor.print_Vec();
    std::string Search_str;
    do
    {
        std::cout << "Enter string to search" << std::endl;
        std::cin >> Search_str;
        victor.searcher(Search_str);
        std::cout << "Again?    y - yes, n - no: ";
        std::cin >> answer;
    } while (answer == "y");
}


//обычный или бинарный поиск по выбору юзера по любому из полей (lower_bound upper_bound)
//файл с миллионами строк
