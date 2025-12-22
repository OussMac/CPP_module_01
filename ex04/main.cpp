#include <fstream>
#include <iostream>
#include <string>


int main(int argc, char *argv[]) 
{
    if (argc != 4) {
        std::cout << "Usage ./Replace <filename> s1 s2" << std::endl;
        return 1;
    }
    if (argv[2][0] == '\0' || argv[3][0] == '\0') {
        std::cout << "Replace strings must not be empty." << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cout << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    
    std::string preLine;
    bool preFound = false;
    size_t prePos = 0;
    while (std::getline(inputFile, preLine)) {
        while ((prePos = preLine.find(s1)) != std::string::npos) {
            preFound = true;
            if (preFound)
                break ;
        }
    }
    if (!preFound)
    {
        inputFile.close();
        std::cout << "String '" << s1 << "' not found in file."<< std::endl;
        return 1;
    }
    inputFile.clear();
    inputFile.seekg(0);
    
    std::string out_filename = filename + ".replace";
    std::ofstream outputFile(out_filename.c_str());
    if (!outputFile.is_open()) {
        inputFile.close();
        std::cout << "Failed to create output file." << std::endl;
        return 1;
    }
    std::string line;
    size_t pos = 0;
    while(std::getline(inputFile, line)) {
       while ((pos = line.find(s1)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        }
        if (!inputFile.eof())
            outputFile << line << std::endl;
        else
            outputFile << line;
    }
    inputFile.close();
    outputFile.close();

    return 0;
}