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

// => validators
bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    
    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        return false;
    
    if (dash1 != '-' || dash2 != '-')
        return false;
    
    if (year < 2009 || year > 2025)
        return false;
    
    if (month < 1 || month > 12)
        return false;
    
    if (year == 2009 && month == 1 && day == 1)
        return false;
    
    int maxDays;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        maxDays = isLeap ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    }
    else {
        maxDays = 31;
    }
    
    if (day < 1 || day > maxDays)
        return false;
    
    return true;
}
int BitcoinExchange::isValidValue(const std::string &value) {
    std::istringstream iss(value);
    double num;
    if (!(iss >> num))
        return -1;
    return (num < 0) ? 0 : (num > 1000) ? 1 : 2;
}

// load db
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

double BitcoinExchange::getBitcoinRate(const std::string &date)
{
    std::map<std::string, double>::iterator it = btcRates.lower_bound(date);

    if (it == btcRates.end())
        --it;
    else if (it->first != date && it != btcRates.begin())
        --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }

    std::string line;
    bool fLineCheck = false;

    while (std::getline(file, line))
    {
        if (!fLineCheck)
        {
            fLineCheck = true;
            if (line != "date | value")
            {
                std::cerr << "Error: Input file format is incorrect. First line must be 'date | value'." << std::endl;
                return;
            }
            continue;
        }

        std::istringstream ss(line);
        std::string date, valueStr;
        double value;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            trimspace(date);
            trimspace(valueStr);

            if (!isValidDate(date))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            int valueCheck = isValidValue(valueStr);
            if (valueCheck == -1)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            if (valueCheck == 0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            if (valueCheck == 1)
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }

            value = std::atof(valueStr.c_str());

            double rate = getBitcoinRate(date);

            double res = value * rate;

            std::cout << date << " => " << value << " = " << res << std::endl;
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
    file.close();
}

void BitcoinExchange::trimspace(std::string &str)
{
    size_t start = str.find_first_not_of(" ");

    size_t end = str.find_last_not_of(" ");

    if (start == std::string::npos || end == std::string::npos)
    {
        str.clear();
    }
    else
    {
        str = str.substr(start, end - start + 1);
    }
}