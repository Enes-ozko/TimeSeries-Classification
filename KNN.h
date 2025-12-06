#ifndef KNN_H
#define KNN_H
#include "TimeSeriesDataset.h"
#include <string>
#include <vector>

using namespace std;

class KNN {
private:
    int k;
    string similarity_measure;

    double euclidean_distance(const vector<double>& a, const vector<double>& b);
    double dtw(const vector<double>& a, const vector<double>& b);
    int predict(const TimeSeriesDataset& trainData, const vector<double>& testSeries);

public:
    KNN(int kValue, string similarityMeasure);
    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& ground_truth);
};

#endif