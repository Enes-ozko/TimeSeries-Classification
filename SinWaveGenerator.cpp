#include "TimeSeriesGenerator.h"
#include "SinWaveGenerator.h"
#include <vector>
#include <string>
#include <cmath>
using namespace std;


SinWaveGenerator::SinWaveGenerator() :
    TimeSeriesGenerator(0), amplitude(1.0), frequency(1.0), phase(0.0) {
}

SinWaveGenerator::SinWaveGenerator(int seedValue, double amplitudeValue, double frequencyValue, double phaseValue):
    TimeSeriesGenerator(seedValue), amplitude(amplitudeValue), frequency(frequencyValue), phase(phaseValue){
            
}

vector<double> SinWaveGenerator::generateTimeSeries(int n){
    vector<double> series;
    for(int x=0; x<n; x++){
        double value = amplitude * sin(frequency * x + phase);
        series.push_back(value);
    }
    return series;
}
