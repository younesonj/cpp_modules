#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib> // for atof

class BitcoinExchange
{
private:
    std::map<std::string, double> btcRates;

    bool isValidDate(const std::string &date);
    int isValidValue(const std::string &value);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string &filename);
    double getBitcoinRate(const std::string &date);
    void processInputFile(const std::string &filename);
    void trimspace(std::string &str);
};