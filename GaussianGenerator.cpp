#include "TimeSeriesGenerator.h"
#include "GaussianGenerator.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib> 
using namespace std;

GaussianGenerator::GaussianGenerator():
    TimeSeriesGenerator(0), mean(0), std(1) {
}

GaussianGenerator::GaussianGenerator(int seedValue, double meanValue, double stdValue):
    TimeSeriesGenerator(seedValue), mean(meanValue), std(stdValue){        
}

vector<double> GaussianGenerator::generateTimeSeries(int n){
    vector<double> series;
    series.reserve(n);
    for(int i=0; i<n; i++){
        series.push_back(box_muller());
    }
    return series;
}

double GaussianGenerator::box_muller() {                     
    double u1 = (rand() + 1.0) / ((double)RAND_MAX + 1.0);
    double u2 = (rand() + 1.0) / ((double)RAND_MAX + 1.0);
    
    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return (mean + std * z);
}

double GaussianGenerator::getMean(){
    return mean;
}

double GaussianGenerator::getStd(){
    return std;
}