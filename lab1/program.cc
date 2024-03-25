#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cassert>
 const unsigned int option = (19%5) + 5; 
int decimal_solution(std::string solution)
{
    int bin_num = 0;
    for (int i = 0; i < option; i++)
        bin_num += ((static_cast<unsigned int>(solution[option - i - 1]) - 48) * pow(2, i));
    return bin_num;
}

std::string binary_solution(std::string a, std::string b)
{
    int bin_num = decimal_solution(a) + decimal_solution(b);
    std::string solution;

    while (bin_num != 0)
    {
        solution += (bin_num % 2) + '0';
        bin_num /= 2;
    }
    std::reverse(solution.begin(), solution.end());
    return solution;
}

int main()
{
    std::string a, b;
    std::cout << "  Завдання: Написати програму яка виконує додавання двох чисел введених" << std::endl;
    std::cout << "з клавіатури у бінарному вигляді, а виводить на екран результат додавання" << std::endl;
    std::cout << " (у бінарному вигляді) та введені числа і їх суму у десятковій формі.\n" << std::endl;
    
    std::cout << "Введіть перший доданок у бінарному вигляді: ";
    std::getline(std::cin, a);
    assert(a.length() == option);
    
    std::cout << "Введіть другий доданок у бінарному вигляді: ";
    std::getline(std::cin, b);
    assert(b.length() == option);

    std::cout << std::endl;
    std::cout << "Сума введених чисел у бінарному вигляді:";
    std::cout << a << " + " << b << " = " << binary_solution(a, b) << std::endl;

    std::cout << std::endl;
    std::cout << "Сума введених чисел у десятковому вигляді:";
    std::cout << decimal_solution(a) << " + " << decimal_solution(b) << " = " << decimal_solution(b) + decimal_solution(a) << std::endl;

    return 0;
}