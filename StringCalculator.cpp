#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class StringCalculator {
public:
    int add(const std::string& input) {
        if (input.empty()) {
            return 0;
        }

        std::string delimiter = ",";
        std::string numbers = input;

        // Check for custom delimiter
        if (input.find("//") == 0) {
            size_t pos = input.find('\n');
            delimiter = input.substr(2, pos - 2);
            numbers = input.substr(pos + 1);
        }

        // Replace newline characters with the delimiter
        std::replace(numbers.begin(), numbers.end(), '\n', ',');

        std::vector<std::string> tokens = split(numbers, delimiter);
        validateAndSum(tokens);
        
        return sum(tokens);
    }

private:
    std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0, end;

        while ((end = str.find(delimiter, start)) != std::string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + delimiter.length();
        }
        tokens.push_back(str.substr(start));
        
        return tokens;
    }

    void validateAndSum(const std::vector<std::string>& tokens) {
        std::vector<int> negatives;
        for (const std::string& token : tokens) {
            int num = std::stoi(token);
            if (num < 0) {
                negatives.push_back(num);
            }
        }
        if (!negatives.empty()) {
            throw std::runtime_error("negatives not allowed: " + joinNegatives(negatives));
        }
    }

    int sum(const std::vector<std::string>& tokens) {
        int total = 0;
        for (const std::string& token : tokens) {
            int num = std::stoi(token);
            if (num <= 1000) {
                total += num;
            }
        }
        return total;
    }

    std::string joinNegatives(const std::vector<int>& negatives) {
        std::string result;
        for (size_t i = 0; i < negatives.size(); ++i) {
            result += std::to_string(negatives[i]);
            if (i != negatives.size() - 1) {
                result += ",";
            }
        }
        return result;
    }
};

