#include "replace.hpp"

static std::string replaceAllOccurrences(const std::string &line, const std::string &s1, const std::string &s2)
{
    if (s1 == s2)
        return line;

    std::string result = line;
    size_t pos = 0;

    while ((pos = result.find(s1, pos)) != std::string::npos)
    {
        result = result.substr(0, pos) + s2 + result.substr(pos + s1.length());
        pos += s2.length();
    }

    return result;
}

bool performReplace(const std::string &filename,  const std::string &s1, const std::string &s2)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string outName = filename + ".replace";
    std::ofstream outputFile(outName.c_str());
    if (!outputFile.is_open())
    {
        std::cout << "Failed to create output file." << std::endl;
        inputFile.close();
        return false;
    }

    std::string line;

    while (std::getline(inputFile, line, '\0'))
    {
        std::string replaced = replaceAllOccurrences(line, s1, s2);
        outputFile << replaced;
        if (!inputFile.eof())
            outputFile << "\n";
    }

    inputFile.close();
    outputFile.close();
    return true;
}
