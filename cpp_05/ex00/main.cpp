#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    {
        try{
            Bureaucrat b1("Alice", 42);
            std::cout << b1 << std::endl;

            b1.incrementGrade();
            std::cout << "After increment: " << b1 << std::endl;

            b1.decrementGrade();
            std::cout << "After decrement: " << b1 << std::endl;
        } 
        catch (const std::exception& e){
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try{
            Bureaucrat b2("Bob", 1);
            std::cout << b2 << std::endl;

            b2.incrementGrade();
        } 
        catch (const Bureaucrat::GradeTooHighException& e){
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try{
            Bureaucrat b3("Charlie", 150);
            std::cout << b3 << std::endl;

            b3.decrementGrade();
        } 
        catch (const Bureaucrat::GradeTooLowException& e){
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}