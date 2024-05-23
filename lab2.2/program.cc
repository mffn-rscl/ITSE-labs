#include <iostream>
#include <string>
#include <cmath>

std::string getSumOfTwoBinaries(std::string bin1, std::string bin2) {
    std::string result = "";
    int sum = 0;
    int i = bin1.length() - 1, j = bin2.length() - 1;

    while (i >= 0 || j >= 0 || sum == 1) {
        if (i >= 0) {
            sum += bin1[i] - '0';
            --i;
        }
        if (j >= 0) {
            sum += bin2[j] - '0';
            --j;
        }
        result = char(sum % 2 + '0') + result;
        sum /= 2;
    }

    return result;
}

std::string multiplyTwoBinaries(std::string bin1, std::string bin2) {
    std::string result = "0";
    for (int i = bin2.length() - 1; i >= 0; --i) {
        if (bin2[i] == '1') {
            result = getSumOfTwoBinaries(result, bin1);
        }
        bin1 += "0";
    }
    return result;
}



int convertBinaryToDecimal(std::string bin) {
    int decimal = 0;
    int power = bin.length() - 1;
    for (char digit : bin) {
        if (digit == '1') {
            decimal += std::pow(2, power);
        }
        --power;
    }
    return decimal;
}

int main() {
    std::cout << "Introduction to Software Engineering, Labwork #2.2\nVariant 3" << std::endl;
    std::cout << "Task: Simulate the algorithm for multiplying numbers in fixed-point format after the lowest bit according to scheme #3 with a bit depth of 8 bits represented in direct code" << std::endl;
    std::string bin1, bin2;

    while (true) {
        std::cout << "Enter the first 8-bit binary: ";
        std::cin >> bin1;
        std::cout << "Enter the second 8-bit binary: ";
        std::cin >> bin2;

        if (bin1.length() != 8 || bin2.length() != 8) {
            std::cout << "Please enter the proper length number" << std::endl;
        } else {
            std::cout << "\n" << bin1 << " x " << bin2 << " = " << multiplyTwoBinaries(bin1, bin2) << "\n\n";
            std::cout << convertBinaryToDecimal(bin1) << " x " << convertBinaryToDecimal(bin2) << " = " 
                      << convertBinaryToDecimal(multiplyTwoBinaries(bin1, bin2)) << std::endl;
            break;
        }
    }

    return 0;
}