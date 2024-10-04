// Exercise.cpp
//
// Purpose: Main file to compile the program to process the trade data.
// 
// @author Li Yuanting
// @version 1.0 10/4/2024

#include "trade_process.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // As the given command, we want three params.
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.csv> <output.csv>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    // process input.csv -> output.csv
    processFile(inputFile, outputFile);
    std::cout << "Processing complete. Results saved to " << outputFile << std::endl;

    return 0;
}
