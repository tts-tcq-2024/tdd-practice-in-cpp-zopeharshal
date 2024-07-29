#include <sstream>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <vector>

#include "StringCalculator.h"

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }
   
    return 0; // Initial implementation to pass the first test
}
int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    return std::stoi(numbers); // Handle single number (if not empty)
}


int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::stringstream ss(numbers);
    std::string number;
    int sum = 0;

    while (std::getline(ss, number, ',')) {
        sum += std::stoi(number);
    }
    return sum;
}
#include <algorithm>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiters = ",\n";
    std::stringstream ss(numbers);
    std::string number;
    int sum = 0;

    while (std::getline(ss, number, ',')) {
        std::stringstream numStream(number);
        while (std::getline(numStream, number, '\n')) {
            sum += std::stoi(number);
        }
    }
    return sum;
}
int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiters = ",\n";
    std::string numStr = numbers;

   
    if (numbers.find("//") == 0) {
        size_t pos = numbers.find("\n");
        std::string customDelim = numbers.substr(2, pos - 2);
        delimiters += customDelim; 
        numStr = numbers.substr(pos + 1); 
    }

    std::stringstream ss(numStr);
    std::string number;
    int sum = 0;

    while (std::getline(ss, number, ',')) {
        std::stringstream numStream(number);
        while (std::getline(numStream, number, '\n')) {
            sum += std::stoi(number);
        }
    }
    return sum;
}


int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiters = ",\n";
    std::string numStr = numbers;
    std::vector<int> negatives;

    if (numbers.find("//") == 0) {
        size_t pos = numbers.find("\n");
        std::string customDelim = numbers.substr(2, pos - 2);
        delimiters += customDelim; 
        numStr = numbers.substr(pos + 1); 
    }

    std::stringstream ss(numStr);
    std::string number;
    int sum = 0;

    while (std::getline(ss, number, ',')) {
        std::stringstream numStream(number);
        while (std::getline(numStream, number, '\n')) {
            int num = std::stoi(number);
            if (num < 0) {
                negatives.push_back(num);
            } else if (num <= 1000) {
                sum += num;
            }
        }
    }

    if (!negatives.empty()) {
        std::string errorMsg = "negatives not allowed: ";
        for (int neg : negatives) {
            errorMsg += std::to_string(neg) + " ";
        }
        throw std::runtime_error(errorMsg);
    }

    return sum;
}
