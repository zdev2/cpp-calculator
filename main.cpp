#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>

#include "helpers.hpp"
#include "split.hpp"
using namespace std;

string input;
int total;

int main() {
    cls();
    gotoxy(0, 0); cout << "==================================" << endl;
    gotoxy(0, 1); cout << "= Input:                         =" << endl;
    gotoxy(0, 2); cout << "= Total: 0                       =" << endl;
    gotoxy(0, 3); cout << "==================================" << endl;
    
    while (input != "end") {
        gotoxy(9, 1); cout << "                    ";
        gotoxy(9, 1); cin >> input;
        
        try {
            StringSplit result = parseString(input);
            
            if (result.character == '+') {
                total += result.number;
            } else if (result.character == '-') {
                total -= result.number;
            } else if (result.character == '*') {
                total *= result.number;
            } else if (result.character == '/') {
                if (result.number == 0) {
                    gotoxy(0, 4);
                    throw std::invalid_argument("Division by zero");
                    gotoxy(0, 5); cin.get(); 
                    gotoxy(0, 4); cout << "                   ";
                }
                total /= result.number;
            } else if (result.character == '=' && result.number == 0) {
                gotoxy(0, 8);       
                exit(0);
            } else {
                gotoxy(0, 4); cout << "> Invalid Char!";
                gotoxy(0, 5); cin.get(); 
                gotoxy(0, 4); cout << "                   ";
            }
            gotoxy(9, 2); cout << total << "        ";
        } catch (const std::invalid_argument& e) {
            gotoxy(0, 4); cout << "> Error: " << e.what();
            gotoxy(0, 5); cin.get(); 
            gotoxy(0, 4); cout << "                                                                                              ";
        }
        
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    return 0;
}