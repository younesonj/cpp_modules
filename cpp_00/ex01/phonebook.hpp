#include "contact.hpp"

class PhoneBook
{
    private :
        Contact contacts[8];
        int size;
    public :
        void    initialize();
        bool    string_is_digit(std::string s);
        int     add_contact();
        void    print_spaces(std::string s);
        void    print_data(std::string data);
        void    print_contacts();
        void    print_index();

};