#include "Bureaucrat.hpp"
#include "AForm.hpp"

// orthodox canonical Aform
Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        grade = other.grade; // name is const, don't assign
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm& Aform) const {
    try
    {
        Aform.beSigned(*this);
        std::cout << name << " signed " << Aform.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << Aform.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &AForm) const
{
    try 
    {
        AForm.execute(*this);
        std::cout << this->getName() << " executed " << AForm.getName() << std::endl;
    } 
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't execute " << AForm.getName()
                  << " because " << e.what() << std::endl;
    }
}
