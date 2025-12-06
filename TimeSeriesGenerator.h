#ifndef TIMESSERIESGENERATOR_H
#define TIMESSERIESGENERATOR_H
#include <vector>
#include <string>
using namespace std;

class TimeSeriesGenerator{
    private:
        int seed;
 
    public:
        TimeSeriesGenerator() ;
        TimeSeriesGenerator(int seedValue);
        virtual ~TimeSeriesGenerator() = default; 
        virtual vector<double> generateTimeSeries(int)=0;
        static void printTimeSeries(const vector<double>& series);

};

#endif