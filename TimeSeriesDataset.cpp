#include "TimeSeriesDataset.h"
#include <cmath>
#include <numeric>

TimeSeriesDataset::TimeSeriesDataset(bool znormalizeValue, bool isTrainValue)
    : znormalize(znormalizeValue), isTrain(isTrainValue), maxLength(0), numberOfSamples(0) {
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    if (series.size() > maxLength) {
        maxLength = series.size();
    }

    if (znormalize) {
        vector<double> normalized = normalize_z_series(series);
        data.insert(data.end(), normalized.begin(), normalized.end());
    } else {
        data.insert(data.end(), series.begin(), series.end());
    }

    labels.push_back(label);
    numberOfSamples++;
}

vector<double> TimeSeriesDataset::normalize_z_series(const vector<double>& series) const {
    if (series.empty()) return series;

    double sum = accumulate(series.begin(), series.end(), 0.0);
    double mean = sum / series.size();

    double sq_sum = 0.0;
    for (double x : series) {
        sq_sum += pow(x - mean, 2);
    }
    double std_dev = sqrt(sq_sum / series.size());

    if (std_dev == 0) return vector<double>(series.size(), 0.0);

    vector<double> normalized_series;
    normalized_series.reserve(series.size());
    for (double x : series) {
        normalized_series.push_back((x - mean) / std_dev);
    }
    return normalized_series;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

vector<double> TimeSeriesDataset::getDataSample(int index) const {
    vector<double> sample;
    int start = index * maxLength;
    int end = start + maxLength;
    
    for (int i = start; i < end; ++i) {
        sample.push_back(data[i]);
    }
    return sample;
}

int TimeSeriesDataset::getLabel(int index) const {
    return labels[index];
}