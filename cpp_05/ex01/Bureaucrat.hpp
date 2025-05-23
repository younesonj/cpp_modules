#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat{
    private:
        std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        Bureaucrat(std::string _name, int grade);

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
    
        class GradeTooHighException : public std::exception{
            public:
                const char *what() const throw()
                {
                    return ("Grade too high");
                };
        };
        class GradeTooLowException : public std::exception{
            public:
                const char *what() const throw()
                {
                    return ("Grade too low");
                };
        };
        void signForm(Form &form) const;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &b);

#endif