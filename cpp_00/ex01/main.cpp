#include "phonebook.hpp"

int main ()
{
    std::string input;
    PhoneBook phone_book;
    phone_book.initialize();
    std::cout << "*  WELCOME TO THE PHONEBOOK  *\n";
    while (1)
    {
        if(std::cin.eof())
            break;
        std::cout << "Enter ADD, SEARCH or EXIT : ";
        if (!std::getline(std::cin, input))
            break;
        if (input == "ADD")
        {
            if (phone_book.add_contact())
                return (1);
        }
        else if (input == "SEARCH")
        {
            phone_book.print_contacts();
            phone_book.print_index();
        }
        else if (input == "EXIT")
        {
            std::cout << "EXIT\n";
            break;
        }
        else
            std::cout << "Invalid input" << std::endl;
    }
    return (0);
}