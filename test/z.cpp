#include <iostream>
#include <string>

int main() {
    std::string input;
    
    std::cout << "Enter a full line: ";
    std::cin >> input;  // Reads a full line including spaces

    std::cout << "You entered: " << input << std::endl;
    return 0;
}
