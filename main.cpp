#include "include/MarketData/MarketDataProcessor.h"

#include <iostream>
#include <string>
#include <vector>


int main(int argc, char* argv[]) {
    std::cout << "Starting Quant Research Simulation..." << std::endl;

    MarketDataProcessor* mdp = new MarketDataProcessor();
    mdp->read("../data");
    mdp->printStatistics();
    
    getchar();
    return 0;
}