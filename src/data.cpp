#include "../include/data.h"

void Data::loadDataFromCSV(std::string& csvFileName, int targetFeatureIndex){
    std::ifstream csvFile(csvFileName);
    if(!csvFile.is_open()){
        throw std::runtime_error("Unable to load file: " + csvFileName);
    }
    std::string line;

    while(std::getline(csvFile,line)){
        std::vector<double> featureVector;
        std::stringstream ss(line);
        std::string featureVal;
        int currentIndex = 0;
        while(std::getline(ss, featureVal, ',')){
            if(currentIndex != targetFeatureIndex){
                featureVector.push_back(std::stod(featureVal));
            }
            else{
                labels.push_back(featureVal);
            }
            currentIndex++;
        }
        features.push_back(featureVector);
    }

    csvFile.close();
}

void Data::printData(){
    for(int i = 0; i < features.size(); i++){
        for(int j = 0; j < features[i].size(); j++){
            std::cout << features[i][j] << " ";
        }
        std::cout << ": " << labels[i] << std::endl;
    }
}

/*
void Data::addDataPoint(const std::vector<double>& feature, int label){
    features.push_back(feature);
    labels.push_back(label);
}


std::vector<std::vector<double>>& Data::getFeatures(){
    return features;
}

std::vector<int>& Data::getLabels(){
    return labels;
}
*/