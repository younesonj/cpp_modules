#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool is_signed;
        int to_sign;
        int to_exec;
    public:
        Form();
        Form(const std::string _name, int to_sign, int to_exec);
        ~Form();
        Form(const Form& f);
        Form &operator=(const Form& f);


        class GradeTooHighException{
            public:
                const char *what() const throw();
        };
        class GradeTooLowException{
            public:
                const char *what() const throw();
        };
        const std::string getName() const;
        bool isSigned() const;
        int toSign() const;
        int toExec() const;
        void beSigned(Bureaucrat &b);

};

std::ostream & operator << (std::ostream &out, const Form& f);

#endif