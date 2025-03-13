#include "phonebook.hpp"

void    PhoneBook::initialize()
{
    size = 0;
}
bool    PhoneBook::string_is_digit(std::string s)
{
    for (int i = 0; s[i]; i++)
        if (!isdigit(s[i]))
            return (false);
    return (true);

}

int is_printable(std::string s)
{
    for (int i = 0; s[i]; i++)
        if (!(s[i] >= 32 && s[i] <= 126))
            return (1);
    return (0);
}

int PhoneBook::add_contact()
{
    size++;
    std::string input;


//firstname 

    while (1)
    {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input))
            return (1);
        if (!input.empty() && !is_printable(input))
            break ;
        std::cout << "Invalid input! Please enter a valid printable input." << std::endl;
    }
    contacts[(size - 1) % 8].set_first_name(input);

// lastname
    while (1)
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input))
            return (1);
        if (!input.empty() && !is_printable(input))
            break ;
        std::cout << "Invalid input! Please enter a valid printable input." << std::endl;
    }
    contacts[(size - 1) % 8].set_last_name(input);

// nickname
    while (1)
    {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, input))
            return (1);
        if (!input.empty() && !is_printable(input))
            break ;
        std::cout << "Invalid input! Please enter a valid printable input." << std::endl;
    }
    contacts[(size - 1) % 8].set_nickname(input);

// phone number
    while (1)
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input))
            return (1);
        if (string_is_digit(input) == true && !input.empty() && !is_printable(input))
            break;
        std::cout << "Invalid input! Please enter a valid printable input." << std::endl;
    }
    contacts[(size - 1) % 8].set_phone_number(input);

// darkest secret
    while (1)
    {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input))
            return (1);
        if (!input.empty() && !is_printable(input))
            break ;
        std::cout << "Invalid input! Please enter only digits and printable characters." << std::endl;
    }
    contacts[(size - 1) % 8].set_darkest_secret(input);

    return (0);
}
//************************************************************** */

void    PhoneBook::print_spaces(std::string s)
{
    for (int i = 0; i < 10 - (int)s.length(); i++)
        std::cout << " ";
}

void    PhoneBook::print_data(std::string data)
{
    if (data.length() <= 10)
    {
        std::cout << data;
        return ;
    }
    for (int i = 0; i < 9; i++)
        std::cout << data[i];
    std::cout << ".";
}

void    PhoneBook::print_contacts()
{
    int len = size > 8 ? 8 : size;
    for (int i = 0; i < len ; i++)
    {
        std::cout << "         " << i << "|";
        print_spaces(contacts[i].get_first_name());
        print_data(contacts[i].get_first_name());
        std::cout << "|";

        print_spaces(contacts[i].get_last_name());
        print_data(contacts[i].get_last_name());
        std::cout << "|";

        print_spaces(contacts[i].get_nickname());
        print_data(contacts[i].get_nickname());

        std::cout << std::endl;
    }
}

void    PhoneBook::print_index()
{
    if (!size)
    {
        std::cout << "No contacts found!\n";
        return ;
    }
    int ind = -1;
    while (!(ind >= 0 && ind <= 9))
    {
        std::cout << "Enter the index : ";
        if (!(std::cin >> ind))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return;
        }
        if (!(ind >= 0 && ind <= 7) || (ind > size -1))
        {
            std::cout << "Invalid not found!\n";
            ind = -1;
        }
    }
    std::cin.ignore(10000, '\n');
    std::cout << "First name : " << contacts[ind].get_first_name() << std::endl;
    std::cout << "Last name : " << contacts[ind].get_last_name() << std::endl;
    std::cout << "Nickname : " << contacts[ind].get_nickname() << std::endl;
    std::cout << "Phone number : " << contacts[ind].get_phone_number() << std::endl;
    std::cout << "Darkest secret : " << contacts[ind].get_darkest_secret() << std::endl;
}