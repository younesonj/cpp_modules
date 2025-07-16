#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default") , grade(150)
{}

Bureaucrat::Bureaucrat(std::string n, int g) : name (n)
{
    if (g < 1)
        throw GradeTooHighException();
    else if (g > 150)
        throw GradeTooLowException();
    grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()) , grade(other.getGrade())
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        grade = other.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{}

const std::string &Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << " , bureaucrat grade " << b.getGrade() << ".";
    return (out);
}

void Bureaucrat::signForm(Form& form) const
{
    try {
        form.beSigned(*this);
        std::cout << getName() << " signs " << form.getName() << "." << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << getName() << " cannot sign " << form.getName() 
                  << " because their grade is too low." << std::endl;
    }
}
