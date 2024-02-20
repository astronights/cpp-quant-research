#ifndef SIGNAL_GENERATOR_H
#define SIGNAL_GENERATOR_H

#include <vector>
#include <chrono>
#include "MarketDataProcessor.h"

struct Signal {
    std::chrono::nanoseconds timestampNano;
    double value;
};

class SignalGenerator {

    public:
        SignalGenerator();
        ~SignalGenerator();

        std::vector<double> generateSignals(const std::vector<MarketData>& marketData);

};

#endif