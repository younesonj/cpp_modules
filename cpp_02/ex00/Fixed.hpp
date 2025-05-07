#include <iostream>

class Fixed{
    private:
        int val;
        static const int frac;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed &rhs);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
