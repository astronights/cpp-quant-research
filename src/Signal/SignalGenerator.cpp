#include "SignalGenerator.h"

SignalGenerator::SignalGenerator() {}
SignalGenerator::~SignalGenerator() {}

std::vector<Signal> SignalGenerator::generateSignals(const std::vector<MarketData>& marketData) {

    std::vector<Signal> signals;

    // Example: Generate signals based on historical market data
    for (const auto& data : marketData) {

        Signal signal;
        signal.timestampNano = data.timestampNano;
        signal.value = 1;
        signals.push_back(signal);
    }

    return signals;
}