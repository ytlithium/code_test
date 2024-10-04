// trade_process.h
//
// Purpose: 
// 1. Design the structure to store trade information for each instrument.
// 2. Process the input csv data to generate the statistics for each instrument and output to csv.
// 
// @author Li Yuanting
// @version 1.0 10/4/2024

#ifndef TRADE_PROCESS_H
#define TRADE_PROCESS_H

#include <string>
#include <map>

// Class to store all information for each instrument
class InstrumentInfo {
public:
    // Constructors
    InstrumentInfo() : lastTimeStamp(0), maxTimeGap(0), totalVolume(0), totalValue(0), maxPrice(0) {}

    // Member variables to hold statistics, we can make them private if needed(Then we need to add some interfaces)
    long long lastTimeStamp;   // Last recorded timestamp of trade
    long long maxTimeGap;      // Maximum time gap between trades
    long long totalVolume;     // Total volume traded
    long long totalValue;      // Sum of (Price * Quantity) for weighted average price calculation
    int maxPrice;              // Maximum price traded

    // Update the information for a symbol based on each trade information from input.csv
    void updateStats(long long timeStamp, int quantity, int price);

    // Calculate the weighted average price from total value and total volume
    long long getWeightedAveragePrice() const;
};

// Function for process input.csv -> output.csv
void processFile(const std::string& inputFile, const std::string& outputFile);

#endif
