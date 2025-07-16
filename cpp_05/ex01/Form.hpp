#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool is_signed;
        const int to_sign;
        const int to_exec;
    public:
        Form();
        Form(const std::string n, int to_s, int to_e);
        Form(const Form& other);
        Form &operator=(const Form& other);
        ~Form();
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw(){
                    return "Grade too high!";
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw(){
                    return "Grade too low!";
                }
        };
        const std::string &getName() const;
        bool getIsSigned() const;
        int getToSign() const;
        int getToExec() const;
        void beSigned(const Bureaucrat &bureaucrat);
        

};

std::ostream &operator << (std::ostream &out, const Form &f);


#endif