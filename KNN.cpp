#include "KNN.h"
#include <cmath>
#include <limits>
#include <algorithm>
#include <map>

using namespace std;

KNN::KNN(int kValue, string similarityMeasure) 
    : k(kValue), similarity_measure(similarityMeasure) {
}

double KNN::euclidean_distance(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    int len = min(a.size(), b.size()); 
    for (int i = 0; i < len; ++i) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

double KNN::dtw(const vector<double>& a, const vector<double>& b) {
    int n = a.size();
    int m = b.size();
    
    vector<vector<double>> d(n + 1, vector<double>(m + 1, numeric_limits<double>::infinity()));
    d[0][0] = 0.0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            double cost = pow(a[i - 1] - b[j - 1], 2);
            d[i][j] = cost + min({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]});
        }
    }
    return sqrt(d[n][m]);
}

int KNN::predict(const TimeSeriesDataset& trainData, const vector<double>& testSeries) {
    vector<pair<double, int>> distances;
    int n_train = trainData.getNumberOfSamples();

    for (int i = 0; i < n_train; ++i) {
        double dist = 0.0;
        vector<double> trainSeries = trainData.getDataSample(i);

        if (similarity_measure == "dtw") {
            dist = dtw(testSeries, trainSeries);
        } else {
            dist = euclidean_distance(testSeries, trainSeries);
        }
        distances.push_back({dist, trainData.getLabel(i)});
    }

    sort(distances.begin(), distances.end());

    map<int, int> class_counts;
    for (int i = 0; i < k && i < (int)distances.size(); ++i) {
        class_counts[distances[i].second]++;
    }

    int best_label = -1;
    int max_count = -1;
    for (auto const& [label, count] : class_counts) {
        if (count > max_count) {
            max_count = count;
            best_label = label;
        }
    }
    return best_label;
}

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& ground_truth) {
    int correct = 0;
    int n_test = testData.getNumberOfSamples();

    for (int i = 0; i < n_test; ++i) {
        vector<double> testSeries = testData.getDataSample(i);
        int predictedLabel = predict(trainData, testSeries);
        
        if (predictedLabel == ground_truth[i]) {
            correct++;
        }
    }
    return (double)correct / n_test;
}