#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>
#include <exception>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(char *str);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        bool is_operator(char c);
        int calculatrice_lhbal(int n1, int n2,  char op);
        
};




#endif