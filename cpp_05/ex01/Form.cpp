#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default") , _signed(false) , to_sign(1) , to_exec(1)
{

}

Form::Form(const std::string _name, const int _to_sign, const int _to_exec) : name(_name) , _signed(false) , to_sign(_to_sign) , to_exec(_to_exec)
{
    if (to_sign < 1 || to_exec < 1)
        throw GradeTooHighException();
    else if (to_sign > 150 || to_exec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name) , _signed(other._signed) , to_sign(other.to_sign) , to_exec(other.to_exec)
{

}

Form& Form::operator=(const Form& other)
{
    _signed = other._signed;
    return (*this);
}

Form::~Form()
{

}

const std::string Form::getName() const
{
    return (name);
}

bool Form::isSigned() const
{
    return (_signed);
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
        _signed = true;
    else
        throw (GradeTooLowException());
}



std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << f.getName() << ", signed: " << f.isSigned() <<  ", required grade to => sign: " << f.toSign() << ", execute: " << f.toExec() << "." << std::endl;
    return (out);
}