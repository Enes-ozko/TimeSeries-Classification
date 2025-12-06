#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H
#include "TimeSeriesGenerator.h"
#include <vector>
using namespace std;

class SinWaveGenerator: public TimeSeriesGenerator{
    private:
        double amplitude=1.0;
        double frequency=1.0;
        double phase=0.0;

    public:
        SinWaveGenerator();
        SinWaveGenerator(int seedValue, double amplitudeValue, double frequencyValue, double phaseValue);
        virtual ~SinWaveGenerator() = default;
        vector<double> generateTimeSeries(int n) override;
};
#endif