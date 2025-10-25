#include "Functions.hpp"

int main ()
{

    for (int i = 0; i < 3; ++i)
    {
        Base* ptr = generate();
        identify(*ptr);
        delete ptr;
    }

    return 0;
}
