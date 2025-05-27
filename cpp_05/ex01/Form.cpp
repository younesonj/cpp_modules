#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), is_signed(false), to_sign(1), to_exec(1)
{}

Form::~Form()
{}

Form::Form(const std::string _name, int ts, int tex): name(_name), is_signed(false), to_sign(ts), to_exec(tex)
{
    if (ts < 1 || tex < 1)
        throw GradeTooHighException();
    else if (ts > 150 || tex > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& f) : name(f.getName()), is_signed(f.isSigned()), to_sign(f.toSign()), to_exec(f.toExec())
{}

Form &Form::operator=(const Form& f)
{
    if (this != &f)
    {
        is_signed = f.isSigned();
        to_sign = f.toSign();
        to_exec = f.toExec();
    }
    return (*this);
}

const std::string Form::getName() const
{
    return (name);
}

bool Form::isSigned() const
{
    return (is_signed);
}

int Form::toSign() const
{
    return (to_sign);
}

int Form::toExec() const
{
    return (to_exec);
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= to_sign)
        is_signed = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream & operator << (std::ostream &out, const Form& f)
{
    out << f.getName() << ", signed: " << f.isSigned() << ", required grade to => sign: " << f.toSign() << ", execute: " << f.toExec() << ".";
	return (out);
}
