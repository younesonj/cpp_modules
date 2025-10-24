#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>


int main()
{
    std::cout << "=== AFORM EXECUTION TESTS ===" << std::endl << std::endl;

    // Test 1: ShrubberyCreationForm
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    try {
        ShrubberyCreationForm shrub("garden");
        Bureaucrat lowGrade("LowGuy", 150);    // Can't sign (needs 145)
        Bureaucrat midGrade("MidGuy", 140);    // Can sign but can't execute (needs 137)
        Bureaucrat highGrade("HighGuy", 130);  // Can sign and execute
        
        std::cout << shrub << std::endl;
        
        // Try signing with insufficient grade
        lowGrade.signForm(shrub);
        
        // Sign with sufficient grade
        midGrade.signForm(shrub);
        std::cout << "After signing: " << shrub << std::endl;
        
        // Try executing without sufficient grade
        midGrade.executeForm(shrub);
        
        // Execute with sufficient grade
        highGrade.executeForm(shrub);
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: RobotomyRequestForm (test multiple times for randomness)
    std::cout << "=== Test 2: RobotomyRequestForm ===" << std::endl;
    try {
        RobotomyRequestForm robot("Bender");
        Bureaucrat roboteer("Roboteer", 40);  // Can sign (72) and execute (45)
        
        std::cout << robot << std::endl;
        roboteer.signForm(robot);
        
        // Test multiple executions to see randomness
        std::cout << "\nExecuting 3 times to test randomness:" << std::endl;
        for (int i = 1; i <= 3; i++) {
            std::cout << "Attempt " << i << ": ";
            roboteer.executeForm(robot);
			sleep(1); // To change the seed for randomness
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 3: PresidentialPardonForm
    std::cout << "=== Test 3: PresidentialPardonForm ===" << std::endl;
    try {
        PresidentialPardonForm pardon("Arthur Dent");
        Bureaucrat president("President", 1);     // Can sign (25) and execute (5)
        Bureaucrat senator("Senator", 20);        // Can sign but not execute
        
        std::cout << pardon << std::endl;
        
        // Sign the form
        senator.signForm(pardon);
        std::cout << "After signing: " << pardon << std::endl;
        
        // Try executing without sufficient grade
        senator.executeForm(pardon);
        
        // Execute with sufficient grade
        president.executeForm(pardon);
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Error cases
    std::cout << "=== Test 4: Error Cases ===" << std::endl;
    try {
        ShrubberyCreationForm errorForm("test");
        Bureaucrat weakBureaucrat("Weak", 150);
        
        std::cout << "Trying to execute unsigned form:" << std::endl;
        weakBureaucrat.executeForm(errorForm);  // Should fail - not signed
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    // std::cout << std::endl << "=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}