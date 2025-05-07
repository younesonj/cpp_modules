#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    val = 0;
}

Fixed::Fixed(const Fixed &original)
{
    std::cout << "Copy constructor called\n";
    *this = original;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        this->val = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return (val);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    val = raw;
}


// neeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeew


Fixed::Fixed(const int n)
{
    val = n << frac;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f)
{
    val = (int)roundf(f * (1 << frac));
    std::cout << "Float constructor called\n";
}

float Fixed::toFloat( void ) const
{
    return( (float)val / (1 << frac));
}

int Fixed::toInt( void ) const
{
    return (val >> frac);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}
