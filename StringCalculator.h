#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
 int add(const std::string& input);
private:
 std::vector<int> parseNumbers(const std::string& input, const std::string& delimiter);
 void checkForNegatives(const std::vector<int>& numbers);
};

#endif 
