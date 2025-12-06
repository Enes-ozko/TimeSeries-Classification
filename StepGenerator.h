#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H
#include "TimeSeriesGenerator.h"
#include <vector>
using namespace std;

class StepGenerator: public TimeSeriesGenerator{
    private:
        int min=0 ;
        int max=100;
        int saut();


    public:
        StepGenerator();
        StepGenerator(int seedValue, int minValue, int maxValue);
        virtual ~StepGenerator() = default; 
        vector<double> generateTimeSeries(int n) override;



};
#endif