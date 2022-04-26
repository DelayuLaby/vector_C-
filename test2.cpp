#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>


using namespace std;

class LINE
{
    string Item_number;
    string Name;
    string Station_code;
public:
    LINE(string& str)
    {
        if (str != "Item number;Name;Station code")
        {
            string::iterator pos = str.begin();
            for (auto i = str.begin(); i < str.end() - 1; i++)
            {
                if ((int)(*i) == 59)
                {
                    break;
                }
                Item_number.push_back(*i);
                pos++;
            }
            pos++;
            for (auto i = pos; i < str.end() - 1; i++)
            {
                if ((int)(*i) == 59)
                {
                    break;
                }
                Name.push_back(*i);
                pos++;
            }
            pos++;
            for (auto i = pos; i < str.end() - 1; i++)
            {
                if ((int)(*i) == '\0')
                {
                    break;
                }
                Station_code.push_back(*i);
            }
        }
    }

    LINE(): Item_number(""), Name(""), Station_code(""){}
    
    string Get_Item_Number()
    {
        return this->Item_number;
    }

    string Get_Name()
    {
        return this->Name;
    }

    string Get_Station_code()
    {
        return this->Station_code;
    }

    void PrintLINE()
    {
        cout << "Item_number: " << this->Item_number << "; Name: " << this->Name << "; Station_code: " << Station_code << endl;
    }

    LINE operator=(LINE& obj)
    {
        this->Item_number = obj.Get_Item_Number();
        this->Name = obj.Get_Name();
        this->Station_code = obj.Get_Station_code();
        return *this;
    }

};

struct Vec
{
    std::vector<LINE> vec;
    Vec()
    {
        cout << "Vector for Excel created." << endl;
    }
    void AddLINE(LINE obj)
    {
        vec.push_back(obj);
    }
    void PrintVec()
    {
        cout << "--------------------------------Vector start--------------------------------" << endl;
        for (auto i = this->vec.begin(); i < this->vec.end(); i++)
        {
            (*i).PrintLINE();
        }
        cout << "--------------------------------Vector ended--------------------------------" << endl;
    }

    LINE operator[](int index)
    {
        return *(this->vec.begin() + index);
    }

    //void Sort_by_Item_number(std::vector<LINE>::iterator l, std::vector<LINE>::iterator r)
    //{
    //    LINE temp;
    //    /*std::vector<LINE>::iterator left = this->vec.begin();
    //    std::vector<LINE>::iterator right = this->vec.end() - 1;*/
    //    std::vector<LINE>::iterator midle = l + this->vec.size()/2;
    //    do
    //    {
    //        while ((*l).Get_Item_Number() < (*midle).Get_Item_Number()) l++;
    //        while ((*midle).Get_Item_Number() < (*r).Get_Item_Number()) r--;
    //        if (l < r)
    //        {
    //            temp = (*l);
    //            (*l) = (*r);
    //            (*r) = temp;
    //            l++;
    //            r--;
    //        }
    //    } while (l < r);
    //    if()
    //}

};


int main()
{

    ifstream file_out;
    string line;
    int count = 0;
    Vec victor;
    file_out.open("stations.csv");
    cout << "Start!!!" << endl << endl;
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    if (file_out.is_open())
    {
        begin = std::chrono::high_resolution_clock().now();
        while (getline(file_out, line))
        {
            LINE temp(line);
            victor.AddLINE(temp);
        }
        end = std::chrono::high_resolution_clock().now();
    }
    file_out.close();
    victor.PrintVec();
    std::chrono::duration<double> result = end - begin;
    cout << "END. Write in Victor is " << result.count() << endl << endl;
}


