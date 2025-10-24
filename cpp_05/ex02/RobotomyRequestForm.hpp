#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const& target);
    RobotomyRequestForm(RobotomyRequestForm const& other);
    RobotomyRequestForm& operator=(RobotomyRequestForm const& other);
    ~RobotomyRequestForm();

    // Override the pure virtual function
    void execute(Bureaucrat const& executor) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP