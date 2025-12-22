#include "replace.hpp"

std::string interpretEscapes(const std::string &src)
{
    std::string result;
    result.reserve(src.size());

    for (size_t i = 0; i < src.size(); i++)
    {
        if (src[i] == '\\' && i + 1 < src.size())
        {
            char next = src[i + 1];
            if (next == 'n') {
                result += '\n';
                i++;
                continue;
            }
            if (next == 't') {
                result += '\t';
                i++;
                continue;
            }
        }
        result += src[i];
    }
    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./Replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string raw_s1 = argv[2];
    std::string raw_s2 = argv[3];

    std::string s1 = interpretEscapes(raw_s1);
    std::string s2 = interpretEscapes(raw_s2);

    if (s1.empty())
    {
        std::cout << "s1 must not be empty." << std::endl;
        return 1;
    }

    if (!performReplace(filename, s1, s2))
    {
        std::cout << "Error during replacement." << std::endl;
        return 1;
    }

    return 0;
}
