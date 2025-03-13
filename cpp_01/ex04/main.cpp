#include <iostream>
#include <fstream>

int main (int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        return (1);
    }
    std::string     src = av[1];
    std::string     dest = src + ".replace";

    std::ifstream inputfile(src.c_str());
    if (!inputfile.is_open())
    {
        std::cerr << "Error: Could not open file " << src << std::endl;
        return (1);
    }

    std::ofstream outputfile(dest.c_str());
    if (!outputfile.is_open())
    {
        std::cerr << "Error : Could not open file " << dest << std::endl;
        return (1);
    }

    std::string line;
    while (std::getline(inputfile, line))
    {
        outputfile << line << std::endl;
    }

    outputfile.close();
    inputfile.close();
    return (0);
}
