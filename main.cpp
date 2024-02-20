#include "include/MarketData/MarketDataProcessor.h"
#include "include/Signal/SignalGenerator.h"

#include <iostream>
#include <string>
#include <vector>


int main(int argc, char* argv[]) {
    std::cout << "Starting Quant Research Simulation..." << std::endl;

    MarketDataProcessor* mdp = new MarketDataProcessor();
    mdp->read("../data");
    mdp->printStatistics();

    SignalGenerator* sg = new SignalGenerator();
    std::vector<Signal> signals = sg->generateSignals(mdp->getMarketData());
    
    getchar();
    return 0;
}