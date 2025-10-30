#include "iter.hpp"

template <typename T> void printElement(const T& element)
{
    std::cout << element << std::endl;
}

void to_uppercase(char& c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

int main ()
{
    int Arr[] = {1, 2, 3, 4, 5};
    std::cout << "Printing integer array elements:" << std::endl;
    ::iter(Arr, 5, printElement<int>);

    std::cout << std::endl;

    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Printing character array elements:" << std::endl;
    ::iter(charArr, 5, printElement<char>);
    
    std::cout << std::endl;


    std::string strArr[] = {"Hello", "World", "from", "iter", "function"};
    std::cout << "Printing string array elements:" << std::endl;
    ::iter(strArr, 5, printElement<std::string>);

    std::cout << std::endl;

    char charArr2[] = {'a', 'b', 'c', 'd', 'e'};
    ::iter(charArr2, 5, to_uppercase);
    std::cout << "Printing character array elements after converting to lower case:" << std::endl;
    ::iter(charArr2, 5, printElement<char>);
}