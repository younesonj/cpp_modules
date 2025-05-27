#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string _name, int _grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat &operator=(const Bureaucrat& b);
        class GradeTooHighException{
            public:
                const char *what() const throw();
        };
        class GradeTooLowException{
            public:
                const char *what() const throw();
        };
        const std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(Form &f) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& b);


#endif