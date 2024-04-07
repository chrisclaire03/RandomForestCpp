#include "../include/randomForest.h"

void RandomForest::train(Data& trainData){
    for(int i = 0; i < numTrees; i++){
        DecisionTree tree(maxDepth, minSamplesSplit);
        Data bootstrappedData = trainData.bootstrapData(samplesPerTree,featuresPerTree);
        tree.train(bootstrappedData);
        trees.push_back(tree);
    }
}

std::string RandomForest::predict(std::vector<double> input){
    std::unordered_map<std::string, int> classCounts;
    for(int i = 0; i < numTrees; i++){
        classCounts[trees[i].predict(input)]++;
    }

    std::string output = "";
    int outputCount = 0;
    for(const auto& classCount : classCounts){
        if(classCount.second > outputCount){
            output = classCount.first;
            outputCount = classCount.second;
        }
    }

    return output;
}