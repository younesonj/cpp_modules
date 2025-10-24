#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
    std::string const	_name;
    bool				_signed;
    int const			_gradeToSign;
    int const			_gradeToExecute;

    
    public:
        //orthodox canonical form
        AForm();
        AForm(std::string const& name, int gradeToSign, int gradeToExecute);
        AForm(AForm const& other);
        AForm& operator=(AForm const& other);
        virtual ~AForm();  // Virtual destructor for proper inheritance

        //getters
        std::string const&	getName() const;
        bool				isSigned() const;
        int					getGradeToSign() const;
        int					getGradeToExecute() const;


        void				beSigned(Bureaucrat const& b);
        
        // Pure virtual function - makes this class abstract
        virtual void		execute(Bureaucrat const& executor) const = 0;

        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSigned : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, AForm const& f);

#endif // AFORM_HPP