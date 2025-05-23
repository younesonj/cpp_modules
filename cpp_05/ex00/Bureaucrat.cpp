#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    name = "default";
    grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    this->name = other.getName();
    this->grade = other.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        name = other.getName();
        grade = other.getGrade();
    }
    return (*this);
};

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    grade = _grade;
}

const std::string& Bureaucrat::getName() const
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
    {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
    {
        throw GradeTooLowException();
    }
    grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (out);
}
