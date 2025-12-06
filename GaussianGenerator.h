#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H
#include "TimeSeriesGenerator.h"
#include <vector>
#include <string>
using namespace std;

class GaussianGenerator: public TimeSeriesGenerator{
    private:
        double mean;
        double std;
    public:
        GaussianGenerator() ;
        GaussianGenerator(int seedValue, double meanValue, double stdValue);
        vector<double> generateTimeSeries(int n) override;
        double getMean();
        double getStd();
    private:
        double box_muller();    
};

#endif