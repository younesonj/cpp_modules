#include "Span.hpp"
#include <cstdlib>
#include <ctime>

void    printvector(std::vector<int> container, unsigned int count)
{
    for (size_t i = 0; i < count; i++)
    {
        std::cout << container[i];
        if (i + 1 != count)
            std::cout << " ";
    }
    std::cout <<std::endl;
}

int main()
{
    try
    {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Span sp = Span(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Span sp = Span(4);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;


    try
    {
        Span sp = Span(10001);
        for (size_t i = 0; i < 10001; i++)
            sp.addNumber(i + 1);
        

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}