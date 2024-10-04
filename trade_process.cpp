// trade_process.cpp
//
// 1. Design the structure to store trade information for each instrument.
// 2. Process the input csv data to generate the statistics for each instrument and output to csv.
// 
// @author Li Yuanting
// @version 1.0 10/4/2024

#include "trade_process.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

// Update the information for a symbol based on each trade information from input.csv
void InstrumentInfo::updateStats(long long timeStamp, int quantity, int price) {
    // Calculate the time gap if it's not the first trade for the symbol
    if (lastTimeStamp != 0) {
        long long timeGap = timeStamp - lastTimeStamp;
        maxTimeGap = std::max(maxTimeGap, timeGap);
    }

    // Update the last timestamp
    lastTimeStamp = timeStamp;

    // Update total volume and total value
    totalVolume += quantity;
    totalValue += quantity * price;

    // Update max price
    maxPrice = std::max(maxPrice, price);
}

// Calculate weighted average price
long long InstrumentInfo::getWeightedAveragePrice() const {
    // Handle the case for total volume = 0(Although it may not happen in this trading system, just in case)
    return totalVolume ? totalValue / totalVolume : 0;
}

// Function for process input.csv -> output.csv
void processFile(const std::string& inputFile, const std::string& outputFile) {
    // Initialize the input and output file
    std::ifstream infile(inputFile);
    std::ofstream outfile(outputFile);

    // Handle the case if the files are not able to open.
    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    // Use a map to hold instrument statistics, it can be automatically sorted by symbol names
    std::map<std::string, InstrumentInfo> symbolStats;
    std::string line;

    // Read each line of trade information from the input file
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string token;

        // As the given structure of input, parse the line for TimeStamp, Symbol, Quantity, and Price
        std::getline(ss, token, ',');
        long long timeStamp = std::stoll(token);

        std::getline(ss, token, ',');
        std::string symbol = token;

        std::getline(ss, token, ',');
        int quantity = std::stoi(token);

        // As the assumption, price is always integer
        std::getline(ss, token, ',');
        int price = std::stoi(token);

        // Get or create the information for the symbol
        symbolStats[symbol].updateStats(timeStamp, quantity, price);
    }

    // Write header if needed (I think it's more human readable if giving the csv a header XD, but here to make sure they are the same I commentted it)
    //outfile << "Symbol,MaxTimeGap,Volume,WeightedAveragePrice,MaxPrice\n";

    // Output the ordered information for each symbol to output.csv
    for (const auto& [symbol, stats] : symbolStats) {
        outfile << symbol << "," << stats.maxTimeGap << "," << stats.totalVolume << "," << stats.getWeightedAveragePrice() << "," << stats.maxPrice << std::endl;
    }

    infile.close();
    outfile.close();
}
