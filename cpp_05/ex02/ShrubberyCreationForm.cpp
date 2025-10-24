// ShrubberyCreationForm.cpp
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>
// # include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm_Def", 145, 137)
{
    _target = "default";
    // std::cout << "ShrubberyCreationForm default constructor is called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


// EXECUTE FUNCTION

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::FormNotSigned();

    std::string     filename = _target + "_shrubbery";
    std::ofstream   outFile(filename.c_str());

    outFile << "        *\n";
    outFile << "       ***\n";
    outFile << "      *****\n";
    outFile << "     *******\n";
    outFile << "    *********\n";
    outFile << "   ***********\n";
    outFile << "  *************\n";
    outFile << " ***************\n";
    outFile << "*****************\n";
    outFile << "       |||\n";
    outFile << "       |||\n";
    outFile << "     __|||__\n";
    outFile << "    |       |\n";
    outFile << "    |_______|\n";

    outFile.close();
}