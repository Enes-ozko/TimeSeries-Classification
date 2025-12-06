#include "TimeSeriesGenerator.h"
#include "StepGenerator.h"
#include <vector>
#include <string>
using namespace std;

StepGenerator::StepGenerator() : TimeSeriesGenerator(), min(0), max(100) {}

StepGenerator::StepGenerator(int seedValue, int minValue, int maxValue):
    TimeSeriesGenerator(seedValue),min(minValue),max(maxValue){
            
}

int StepGenerator::saut(){
    return min + (rand() % (max - min + 1));
    
}
    
vector<double> StepGenerator::generateTimeSeries(int n){
    vector<double> series;
    int value = 0; 
    series.push_back(value);

    for(int i = 1; i < n; i++){
        if(rand() % 2 == 0){
            value = saut();
        }
        series.push_back(value);
    }
    return series;
}
   