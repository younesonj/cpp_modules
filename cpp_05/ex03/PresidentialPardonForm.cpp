#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other)
: AForm(other), _target(other._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
