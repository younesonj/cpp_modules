#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public :
        void    set_first_name(std::string input)
        {
            first_name = input;
        }
        void    set_last_name(std::string input)
        {
            last_name = input;
        }
        void    set_nickname(std::string input)
        {
            nickname = input;
        }
        void    set_phone_number(std::string input)
        {
            phone_number = input;
        }
        void    set_darkest_secret(std::string input)
        {
            darkest_secret = input;
        }

        std::string    get_first_name()
        {
            return (first_name);
        }
        std::string    get_last_name()
        {
            return (last_name);
        }
        std::string    get_nickname()
        {
            return (nickname);
        }
        std::string    get_phone_number()
        {
            return (phone_number);
        }
        std::string    get_darkest_secret()
        {
            return (darkest_secret);
        }
};

class PhoneBook
{
    private :
        Contact contacts[8];
        int size;
    public :
        void    initialize()
        {
            size = 0;
        }
        bool    string_is_digit(std::string s)
        {
            for (int i = 0; s[i]; i++)
                if (!isdigit(s[i]))
                    return (false);
            return (true);

        }

//*********************************************************** */
        void add_contact()
        {
            size++;
            std::string input;


//firstname
            std::cout << "Enter first name: ";
            std::getline(std::cin, input);
            contacts[(size - 1) % 8].set_first_name(input);

// lastname
            std::cout << "Enter last name: ";
            std::getline(std::cin, input);
            contacts[(size - 1) % 8].set_last_name(input);

// nickname
            std::cout << "Enter nickname: ";
            std::getline(std::cin, input);
            contacts[(size - 1) % 8].set_nickname(input);

// phone number
            while (1)
            {
                std::cout << "Enter phone number: ";
                std::getline(std::cin, input);
                if (string_is_digit(input) == true)
                    break;
                std::cout << "Only digits allowed!\n";
            }
            contacts[(size - 1) % 8].set_phone_number(input);

// darkest secret
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            contacts[(size - 1) % 8].set_darkest_secret(input);


            // contacts[(size - 1) % 8].print_all();

        }
//************************************************************** */

        void    print_spaces(std::string s)
        {
            for (int i = 0; i < 10 - (int)s.length(); i++)
                std::cout << " ";
        }

        void    print_data(std::string data)
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

        void    print_contacts()
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

        void    print_index()
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
                    return;
                if (!(ind >= 0 && ind <= 7) || (ind > size -1))
                {
                    std::cout << "Invalid not found!\n";
                    ind = -1;
                }
            }
            std::cout << "First name : " << contacts[ind].get_first_name() << std::endl;
            std::cout << "Last name : " << contacts[ind].get_last_name() << std::endl;
            std::cout << "Nickname : " << contacts[ind].get_nickname() << std::endl;
            std::cout << "Phone number : " << contacts[ind].get_phone_number() << std::endl;
            std::cout << "Darkest secret : " << contacts[ind].get_darkest_secret() << std::endl;


        }

};



int main ()
{
    std::string input;
    PhoneBook phone_book;
    phone_book.initialize();


    std::cout << "* * * * * * * * * * * * * * * *\n";
    std::cout << "*                             *\n";
    std::cout << "*  WELCOME TO THE PHONEBOOK   *\n";
    std::cout << "*                             *\n";
    std::cout << "* * * * * * * * * * * * * * * *\n";

    while (1)
    {
        std::cout << "Enter ADD, SEARCH or EXIT : ";
        if (!std::getline(std::cin, input))
            break;

        if (input == "ADD")
        {
            phone_book.add_contact();
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
    
}