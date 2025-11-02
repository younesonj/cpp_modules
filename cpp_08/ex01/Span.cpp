#include "Span.hpp"
// #include <exception>


Span::Span() : N(0)
{}

Span::Span(unsigned int _N) : N(_N)
{}

Span::Span(const Span& other) : N(other.N) , numbers(other.numbers)
{}

Span &Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->numbers = other.numbers;
    }
    return (*this);
}

Span::~Span()
{}

void Span::addNumber(int nb)
{
    if (numbers.size() >= N)
        throw std::out_of_range("Span is already full");
    else
        numbers.push_back(nb);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    int minSpan = std::numeric_limits<int>::max();
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    for (size_t i = 1; i < sorted.size(); i++)
    {
        minSpan = std::min(minSpan, sorted[i] - sorted[i-1]);
        if (minSpan == 0)
            return (0);
    }
    return (minSpan);
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return (max - min);
}

unsigned int Span::getN() const
{
    return (this->N);
}

const std::vector<int> &Span::getnumbers() const
{
    return (this->numbers);
}