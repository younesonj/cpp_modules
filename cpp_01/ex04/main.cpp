#include <iostream>
#include <fstream>

std::string ultimate(std::string line, std::string search, std::string replace)
{
    size_t pos = 0;
    pos = line.find(search, pos);
    while (pos != (size_t)-1)
    {
        line = line.substr(0, pos) + replace + line.substr(search.length() + pos);
        pos += replace.length();
        pos = line.find(search, pos);
    }
    return(line);
}

int main (int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Number of arguments invalid!" << std::endl;
        return (1);
    }

    std::string input_file_name = av[1];
    std::ifstream input(input_file_name.c_str());
    if (!input.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return (1);
    }


    std::string output_file_name = input_file_name + ".replace";
    std::ofstream output(output_file_name.c_str());
    if (!output.is_open())
    {
        input.close();
        std::cerr << "Error opening file!" << std::endl;
        return (1);
    }

    std::string search = av[2], replace = av[3];
    std::string line;
    while (getline(input, line))
    {
        if (search.empty() || replace.empty())
            output << line << std::endl;
        else
            output << ultimate(line, search, replace) << std::endl;
    }

    input.close();
    output.close();

    return (0);
}
