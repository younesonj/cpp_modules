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

        bool operator>(const Fixed& f) const;
        bool operator<(const Fixed& f) const;
        bool operator>=(const Fixed& f) const;
        bool operator<=(const Fixed& f) const;
        bool operator==(const Fixed& f) const;
        bool operator!=(const Fixed& f) const;

        Fixed operator+(const Fixed& f) const;
        Fixed operator-(const Fixed& f) const;
        Fixed operator*(const Fixed& f) const;
        Fixed operator/(const Fixed& f) const;

        Fixed& operator++();    // pre-increment
        Fixed operator++(int);  // post-increment
        Fixed& operator--();    // pre-decrement
        Fixed operator--(int);  // post-decrement

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
