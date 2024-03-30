#ifndef CSV_SYM_PARSER_HPP
#define CSV_SYM_PARSER_HPP

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class CSVSymParser
{
public:
    static std::vector<std::string> parse(const std::string &filename)
    {
        std::ifstream file(filename);
        std::vector<std::string> data;
        std::string line;

        // Skip the first line
        std::getline(file, line);

        while (std::getline(file, line))
        {
            size_t pos = line.find(':');
            if (pos != std::string::npos)
            {
                line = line.substr(0, pos);
            }

            line.erase(std::remove(line.begin(), line.end(), '/'), line.end());

            data.push_back(line);
        }

        return data;
    }
};

#endif