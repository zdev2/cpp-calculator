#include <iostream>
#include <string>
#include <sstream>

struct StringSplit {
    char character;
    int number;
};

StringSplit parseString(const std::string& str) {
    std::istringstream iss(str);
    StringSplit result;
    
    iss >> result.character >> result.number;
    
    if (iss.fail()) {
        throw std::invalid_argument("Input string does not match the format {char} {int}");
    }
    
    return result;
}