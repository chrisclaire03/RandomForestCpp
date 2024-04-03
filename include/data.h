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

class Data{
    private:
        std::vector<std::vector<double>> features;
        std::vector<std::string> labels;
        void addDataPoint(const std::vector<double>& feature, int label);
    public:
        Data(){}
        void loadDataFromCSV(std::string& csvFileName, int targetFeatureIndex);
        void printData();
        std::vector<std::vector<double>>& getFeatures();
        std::vector<int>& getLabels();
};

#endif