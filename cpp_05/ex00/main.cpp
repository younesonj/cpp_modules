#include "Bureaucrat.hpp"

int main ()
{
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.incrementGrade(); // This should throw GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        b2.decrementGrade(); // This should throw GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}