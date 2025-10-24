#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        // no members to copy
        (void)other;
    }
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
    std::string names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i = 0;
    while (i < 3 && names[i] != formName)
        i++;
    switch (i) {
        case 0:
            std::cout << "Intern create " << names[0] << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern create " << names[1] << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern create " << names[2] << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Form type does not exist!" << std::endl;
            return (NULL);
    }
}
