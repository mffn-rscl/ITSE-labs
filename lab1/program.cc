#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cassert>
const unsigned int option = (19%5) + 5; 

int decimal_solution(std::string solution) {
    int bin_num = 0;
    int option = solution.length();

    for (int i = 0; i < option; i++)bin_num += ((solution[option - i - 1] - '0') * pow(2, i)); 

    return bin_num;
}

std::string binary_summator(std::string a, std::string b) {
    std::string binary_sum = "";
    int sum = 0, len = a.length() - 1, remainder = 0;
    while (len >= 0 || remainder == 1) {
        sum = (len >= 0 ? a[len] - '0' : 0) + (len >= 0 ? b[len] - '0' : 0) + remainder;
        remainder = sum / 2;
        sum %= 2;
        binary_sum = std::to_string(sum) + binary_sum;
        len--;
    }
    return binary_sum;
}


int main()
{
    std::string a, b,solution;
    std::cout << "  Завдання: Написати програму яка виконує додавання двох чисел введених" << std::endl;
    std::cout << "з клавіатури у бінарному вигляді, а виводить на екран результат додавання" << std::endl;
    std::cout << " (у бінарному вигляді) та введені числа і їх суму у десятковій формі.\n" << std::endl;
    
    std::cout << "Введіть перший доданок у бінарному вигляді: ";
    std::getline(std::cin, a);
    assert(a.length() == option);
    
    std::cout << "Введіть другий доданок у бінарному вигляді: ";
    std::getline(std::cin, b);
    assert(b.length() == option);
    solution = binary_summator(a, b);
    std::cout << "Сума введених чисел у бінарному вигляді:";
    std::cout << solution << std::endl;

    std::cout << "Сума введених чисел у десятковому вигляді:";
    std::cout << decimal_solution(solution) << std::endl;
    return 0;
}