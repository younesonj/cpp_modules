#include <iostream>
#include <cmath>

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
        Fixed(const int n);
        Fixed(const float f);
        float toFloat( void ) const;
        int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
