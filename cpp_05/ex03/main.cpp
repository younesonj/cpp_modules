#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
// #include <unistd.h>


int main()
{
    std::cout << "\n---------------Test with valaible Form Name---------------\n\n";
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
    std::cout << "\n---------------Test with a unvalaible Form Name---------------\n\n";
    AForm *test;
    test = someRandomIntern.makeForm("makaynch", "Bender");
    std::cout << "\n---------------Test END-------------------------------\n";
    delete rrf;
    delete test;
    return 0;
}
