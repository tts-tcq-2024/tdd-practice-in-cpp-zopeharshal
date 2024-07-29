#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>

int StringCalculator::add(const std::string& input) {
 if (input.empty()) {
     return 0;
 }

 std::string delimiter = ",";
 if (input.substr(0, 2) == "//") {
     size_t delimiterPos = input.find("\n");
     delimiter = input.substr(2, delimiterPos - 2);
     input = input.substr(delimiterPos + 1);
 }

 std::vector<int> numbers = parseNumbers(input, delimiter);
 checkForNegatives(numbers);

 int sum = 0;
 for (int number : numbers) {
     if (number <= 1000) {
         sum += number;
     }
 }

 return sum;
}

std::vector<int> StringCalculator::parseNumbers(const std::string& input, const std::string& delimiter) {
 std::vector<int> numbers;
 std::stringstream ss(input);
 std::string number;
 while (std::getline(ss, number, *delimiter.c_str())) {
     numbers.push_back(std::stoi(number));
 }
 return numbers;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
 std::vector<int> negatives;
 for (int number : numbers) {
     if (number < 0) {
         negatives.push_back(number);
     }
 }
 if (!negatives.empty()) {
     std::string message = "negatives not allowed: ";
     for (int negative : negatives) {
         message += std::to_string(negative) + " ";
     }
     throw std::runtime_error(message);
 }
}
