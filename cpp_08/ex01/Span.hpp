#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

class Span{
    private:
        unsigned int N;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int _N);
        Span(const Span& other);
        Span &operator=(const Span& other);
        ~Span();

        void addNumber(int nb);
        int shortestSpan();
        int longestSpan();
        unsigned int getN() const;
        const std::vector<int> &getnumbers() const;
};

#endif