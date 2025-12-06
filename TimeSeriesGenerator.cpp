#include "TimeSeriesGenerator.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib> 

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(1) {
    srand(seed);
}

TimeSeriesGenerator::TimeSeriesGenerator(int seedValue): seed(seedValue){
    srand(seed);
}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series){
    for (const double value : series) {
        cout << value << " ";
    }
    cout << endl; 
}