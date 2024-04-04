/// Data Class
/// This...
/// @author: Christopher Claire
/// @lastmodified: 3/7/2024

#ifndef DATA_H
#define DATA_H

#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<random>

class Data{
    private:
        std::vector<std::vector<double>> features;
        std::vector<std::string> labels;
    public:
        Data(){};
        Data(const std::vector<std::vector<double>>& featureVector,const std::vector<std::string>& labelVector): features(featureVector), labels(labelVector){};
        void loadDataFromCSV(std::string& csvFileName, int targetFeatureIndex);
        void printData();
        Data bootstrapData(int numSamples, int numFeatures);


};

#endif