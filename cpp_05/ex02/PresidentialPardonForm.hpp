#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

public:
    // Orthodox Canonical Form
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const& target);
    PresidentialPardonForm(PresidentialPardonForm const& other);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
    ~PresidentialPardonForm();

    // Override the pure virtual function
    void execute(Bureaucrat const& executor) const;

};

#endif // PRESIDENTIALPARDONFORM_HPP