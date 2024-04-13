#include <iostream>
#include <string>
#include <cmath>
const int option = 19%16;

int find(std::string bin_num)
{
    int counter=0, len=bin_num.length();
    for (;counter < len; counter++)if(bin_num[counter] == '.')break;
    return counter;    
}

double from_binary_to_frac(std::string bin_num)
{
    double decimal = 0.0;
    int deg = bin_num.length()-find(bin_num)-1,counter =0;
for (int counter = 0; counter < bin_num.length(); counter++)
    {
        if (bin_num[counter] != '.')
        {
            decimal += static_cast<double>((bin_num[counter] - '0') * pow(2, deg));
            deg--;
        }
    }
    return decimal/2.0;
}

std::string from_dir_to_add(std::string &bin_num)
{
    std::string solution = bin_num;
    int pos = bin_num.length()-1;
    
    while(pos >= 0 && bin_num[pos] != '1')pos--;
    
    for (int i = pos; i>=0; i--) (bin_num[i] =='0') ? solution[i] = '1' : solution[i] = '0';        

    return solution;
}

int main()
{
    std::string str;
    std::cout << "a)Переведення дробових чисел з 2 в 10." <<std::endl;
    std::cout << "b)Перетворення цілих чисел з прямого коду в додатковий при довжині розрядної сітки 32. " << std::endl;
    std::cout << "\nОберіть номер завдання, яке потрібно виконати (a,b): ";
    char choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 'a':
        std::cout << "\nIn: ";
        getline(std::cin,str);
        std::cout << "\nрезультат: " << from_binary_to_frac(str) << std::endl;
        break;
    
    case 'b':
        std::cout << "\nIn: ";
        getline(std::cin,str);
        std::cout << "\nрезультат: " << from_dir_to_add(str) << std::endl;

        break;
    
    default:
        std::cout << "incorrect input." << std::endl;
        break;
    }
    return 0;
}