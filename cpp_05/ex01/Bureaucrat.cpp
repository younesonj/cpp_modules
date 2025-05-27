#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    grade = _grade;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.getName()), grade(b.getGrade())
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat&b)
{
    if (this != &b)
    {
        grade = b.getGrade();
    }
    return (*this);
}

const std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::increment()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement()
{
    if (grade == 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (out);
}

void Bureaucrat::signForm(Form &f) const
{
    Bureaucrat b = *this;
    try
    {
        f.beSigned(b);
		std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
		std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}
