#ifndef MARKET_DATA_PROCESSOR_H
#define MARKET_DATA_PROCESSOR_H

#include <string>
#include <vector>
#include <cstdint>
#include <chrono>

class MarketData {
    public:
        std::string keySymbol;
        std::chrono::nanoseconds timestampNano;
        double lastPrice;
        long lastQty;
        double ask1p;
        long ask1q;
        double ask2p;
        long ask2q;
        double ask3p;
        long ask3q;
        double ask4p;
        long ask4q;
        double ask5p;
        long ask5q;
        double bid1p;
        long bid1q;
        double bid2p;
        long bid2q;
        double bid3p;
        long bid3q;
        double bid4p;
        long bid4q;
        double bid5p;
        long bid5q;

        MarketData(std::string, std::chrono::nanoseconds, std::vector<double>);
};


class MarketDataProcessor {

    private:
        std::vector<MarketData> marketData;
        std::vector<MarketData> getMarketData();
        void setMarketData(const std::vector<MarketData>& marketData);

    public:
        MarketDataProcessor() {};
        ~MarketDataProcessor() {};

        bool read(const std::string& folder);
        std::vector<MarketData> process(std::vector<MarketData>& marketData);
        void printStatistics();

};

#endif