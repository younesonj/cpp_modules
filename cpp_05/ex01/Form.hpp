#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool _signed;
        const int to_sign;
        const int to_exec;

    public:
        Form();
        Form(const std::string _name, const int _to_sign, const int _to_exec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string getName() const;
        bool isSigned() const;
        int toSign() const;
        int toExec() const;
        void beSigned(Bureaucrat &b);


        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade too high!");
                };
        };
        class GradeTooLowException
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade too Low!");
                };
        };

};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif