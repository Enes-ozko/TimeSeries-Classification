#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H
#include <vector>
using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

    std::vector<double> normalize_z_series(const vector<double>& series) const;

public:
    TimeSeriesDataset(bool znormalizeValue, bool isTrainValue);
    virtual ~TimeSeriesDataset() = default;

    void addTimeSeries(const vector<double>& series, int label=0);
    int getNumberOfSamples() const;
    int getMaxLength() const;
    vector<double> getDataSample(int index) const;
    int getLabel(int index) const;
};

#endif