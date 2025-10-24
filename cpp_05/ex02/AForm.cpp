// AForm.cpp
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
: _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(const std::string& _name, int _gradeToSign, int _gradeToExecute)
: _name(_name), _signed(false), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // _name, _gradeToSign and _gradeToExecute are const and cannot be assigned to
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

/* Exceptions */

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade too low";
}

const char* AForm::FormNotSigned::what() const throw()
{
    return "AForm: form not signed";
};

/* stream operator */

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm \"" << f.getName() << "\" (signed: " << (f.isSigned() ? "yes" : "no")
       << ", sign grade: " << f.getGradeToSign() << ", exec grade: " << f.getGradeToExecute() << ")";
    return os;
}