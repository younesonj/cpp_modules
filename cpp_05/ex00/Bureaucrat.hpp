#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade(); // decrease numeric grade (closer to 1)
    void decrementGrade(); // increase numeric grade (closer to 150)

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif