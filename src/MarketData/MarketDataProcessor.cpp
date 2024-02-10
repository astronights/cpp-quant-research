#include "MarketDataProcessor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <cstdint>
#include <chrono>

MarketData::MarketData(std::string keySymbol, std::chrono::nanoseconds timestampNano, std::vector<double> values) {
    this->keySymbol = keySymbol;
    this->timestampNano = timestampNano;
    this->lastPrice = values[0];
    this->lastQty = (long)values[1];
    this->ask1p = values[2];
    this->ask1q = (long)values[3];
    this->ask2p = values[4];
    this->ask2q = (long)values[5];
    this->ask3p = values[6];
    this->ask3q = (long)values[7];
    this->ask4p = values[8];
    this->ask4q = (long)values[9];
    this->ask5p = values[10];
    this->ask5q = (long)values[11];
    this->bid1p = values[12];
    this->bid1q = (long)values[13];
    this->bid2p = values[14];
    this->bid2q = (long)values[15];
    this->bid3p = values[16];
    this->bid3q = (long)values[17];
    this->bid4p = values[18];
    this->bid4q = (long)values[19];
    this->bid5p = values[20];
    this->bid5q = (long)values[21];
};

std::vector<MarketData> MarketDataProcessor::getMarketData() {
    return this->marketData;
};

void MarketDataProcessor::setMarketData(const std::vector<MarketData>& marketData) {
    this->marketData = marketData;
};

bool MarketDataProcessor::read(const std::string& folder) {

    std::vector<std::string> files;
    std::string path = folder + "/*.csv";
    int c = 0;
    for (const auto & entry : std::filesystem::directory_iterator(folder)) {
        if (entry.path().extension() == ".csv") {
            files.push_back(entry.path().string());
        }
        std::cout<< c << std::endl;
        if (c == 0) {
            break;
        }
        c++;
    }

    std::cout << "Number of files: " << files.size() << std::endl;
    std::vector<MarketData> marketData;

    for (const auto& file : files) {
        std::cout << "Reading file: " << file << std::endl;
        std::ifstream infile(file);
        std::string line;
        while (std::getline(infile, line)) {
            if (line.find("keySymbol") == 0) {
                continue;
            }
            std::istringstream iss(line);
            std::string symbol;
            std::chrono::nanoseconds timestampNano;
            std::vector<double> values(22);

            int counter = 0;
            std::string cell;
            
            while (std::getline(iss, cell, ',')) {
                if (counter == 0) {
                    symbol = cell;
                } else if (counter == 1) {
                    timestampNano = std::chrono::nanoseconds(std::stoll(cell));
                } else {
                    values[counter - 2] = std::stod(cell);
                }
                counter++;
            }

            MarketData data = MarketData(symbol, timestampNano, values);
            marketData.push_back(data);
        }

    }

    setMarketData(this->process(marketData));
    return true;
};

std::vector<MarketData> MarketDataProcessor::process(std::vector<MarketData>& marketData) {
    std::cout << "Processing market data (sorting by timestamp)" << std::endl;
    std::sort(marketData.begin(), marketData.end(), [](const MarketData& a, const MarketData& b) {
        return a.timestampNano < b.timestampNano;
    });
    return marketData;
};

void MarketDataProcessor::printStatistics() {
    std::cout << "Printing statistics" << std::endl;
    std::vector marketData = getMarketData();
    std::cout << "Number of records: " << marketData.size() << std::endl;
    std::cout << "Timestamp range: " << marketData[0].timestampNano.count() << " - " << marketData[marketData.size() - 1].timestampNano.count() << std::endl;
};