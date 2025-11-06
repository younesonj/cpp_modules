#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char *str){
    std::istringstream iss(str);
    std::string token;
    while (iss >> token)
    {
        if (token.size() > 1)
            throw (std::runtime_error("Error: input not valid!"));
        if (isdigit(token[0]))
        {
            _stack.push(token[0] - 48);
        }
        else if (is_operator(token[0]))
        {
            if (_stack.size() < 2)
                throw (std::runtime_error("Error!"));
            int n1 = _stack.top();
            _stack.pop();
            int n2 = _stack.top();
            _stack.pop();
            _stack.push(calculatrice_lhbal(n2, n1, token[0]));
        }
        else
            throw (std::runtime_error("Error!"));
    }
    if (_stack.size() != 1)
    {
        if (_stack.size() == 0)
            throw std::runtime_error("Error!");
        else
            throw (std::runtime_error("Error!"));
    }
    std::cout << _stack.top() << std::endl;
}
RPN::RPN(const RPN &other) {
    _stack = other._stack;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}


bool RPN::is_operator(char c)
{
    return ((c == '+' || c == '*' || c == '/' || c == '-') ? true : false);     
}

int RPN::calculatrice_lhbal(int n1, int n2,  char op)
{
    switch (op)
    {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            if (n2 == 0)
                throw std::runtime_error("Error: division by zero!!!");
            return n1 / n2;
        default:
            throw std::runtime_error("Error: operator invalid!");
    }
}