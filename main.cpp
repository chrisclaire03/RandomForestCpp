/// Random Forest Main
/// Usage: ./rf data.csv targetFeatureIndex numTrees maxDepth minSamplesSplit featurePerTree samplesPerTree
/// @author: Christopher Claire
/// @lastmodified: 4/10/2024

#include "include/randomForest.h"
#include<iostream>

int main(int argc, char *argv[]){
    if(argc != 8){
        std::cerr << "incorrect use of arguments" << std::endl;
        return 1;
    }

    std::string dataset = argv[1];
    int targetFeatureIndex = std::stoi(argv[2]);
    int numTrees = std::stoi(argv[3]);
    int maxDepth = std::stoi(argv[4]);
    int minSamplesSplit = std::stoi(argv[5]);
    int featuresPerTree = std::stoi(argv[6]);
    int samplesPerTree = std::stoi(argv[7]);

    Data data;
    data.loadDataFromCSV(dataset, targetFeatureIndex);
    std::pair<Data,Data> splitDataset = data.splitData(0.9);
    Data train = splitDataset.first;
    Data test = splitDataset.second;

    RandomForest rf(numTrees, maxDepth, minSamplesSplit, featuresPerTree, samplesPerTree);
    rf.train(train);
    
    for(int i = 0; i < test.getSampleSize(); i++){
        if(rf.predict(test.getFeatureVector(i)) == test.getLabel(i)){
            std::cout << "Correct Prediction" << std::endl;
        }
        else{
            std::cout << "Incorrect Prediction" << std::endl;
        }
    }
    
    return 0;
}