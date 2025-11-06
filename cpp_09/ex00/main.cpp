#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
    (void)av;
    if (ac != 2)
        return (std::cerr << "Error: could not open file." << std::endl, 1);
    try
    {
        BitcoinExchange btc = BitcoinExchange();
        if (!btc.loadDatabase("data.csv"))
            throw std::runtime_error ("Error: failed to load database.");
        btc.processInputFile(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}

