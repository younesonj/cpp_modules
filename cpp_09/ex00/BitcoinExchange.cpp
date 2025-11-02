#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : btcRates(other.btcRates) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->btcRates = other.btcRates;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open database file." << std::endl;
        return false;
    }

    for (std::string line; std::getline(file, line);)
    {
        std::istringstream ss(line);
        std::string date;
        double price;

        if (std::getline(ss, date, ',') && (ss >> price))
            btcRates[date] = price;
    }

    file.close();
    return true;
}
