#include "Bureaucrat.hpp"

int main ()
{
	{
		try
		{
			Bureaucrat b("Younes", 0);
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl; 
	{
		try
		{
			Bureaucrat a("Jhon", 150);
			std::cout << a << std::endl;
			a.increment();
			std::cout << a << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}