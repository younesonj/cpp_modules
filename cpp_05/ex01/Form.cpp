#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), is_signed(false), to_sign(1), to_exec(1) {}

Form::Form(const std::string n, int to_s, int to_e)  : name(n), is_signed(false), to_sign(to_s), to_exec(to_e) 
{
    if (to_s < 1 || to_e < 1)
        throw GradeTooHighException();
    else if (to_s > 150 || to_e > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), is_signed(other.is_signed), to_sign(other.to_sign), to_exec(other.to_exec) {}

Form &Form::operator=(const Form& other)
{
    if (this != &other)
    {
        is_signed = other.is_signed;
    }
    return (*this);
}

Form::~Form() {}

const std::string &Form::getName() const {
    return (name);
}

bool Form::getIsSigned() const {
    return (is_signed);
}

int Form::getToSign() const {
    return (to_sign);
}

int Form::getToExec() const {
    return (to_exec);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > to_sign)
        throw GradeTooLowException();
    is_signed = true;
}

std::ostream &operator << (std::ostream &out, const Form &f)
{
    out << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
        << ", To Sign: " << f.getToSign() << ", To Execute: " << f.getToExec() << ".";
    return out;
}
