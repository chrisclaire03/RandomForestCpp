#include "../include/decisionTree.h"

void DecisionTree::train(Data &trainData){
    root = buildTree(trainData, 0);
}

Node* DecisionTree::buildTree(Data& data, int depth){
    if(depth >= maxDepth){
        return createLeafNode(data);
    }
    
    int bestFeatureIndex = -1;
    double bestThreshold = 0.0;
    double bestGini = 1.0;

    for(int i = 0; i < data.getFeatureSize(); i++){
        for(int j = 0; j < data.getSampleSize(); j++){
            double possibleThreshold = data.getFeature(i,j);
            double gini = calculateGini(data,i,possibleThreshold);
            if(gini < bestGini){
                bestFeatureIndex = i;
                bestThreshold = possibleThreshold;
                bestGini = gini;
            }
        }
    }
}

double calculateGini(Data& data, int featureIndex, double threshold){
    int totalSamples = data.getSampleSize();
    int leftCount = 0;
    int rightCount = 0;

    std::unordered_map<std::string, int> classCountsLeft;
    std::unordered_map<std::string, int> classCountsRight;

    for(int i = 0; i < totalSamples; i++){
        if(data.getFeature(featureIndex, i) <= threshold){
            classCountsLeft[data.getLabel(i)]++;
            leftCount++;
        }
        else{
            classCountsRight[data.getLabel(i)]++;
            rightCount++;
        }
    }

    double leftGini = 0.0;
    if(leftCount > 0){
        for (const auto& classCount : classCountsLeft){
            double classProbability = static_cast<double>(classCount.second) / leftCount;
            leftGini += classProbability * (1.0 - classProbability);
        }
    }
    leftGini = leftGini * (static_cast<double>(leftCount)/totalSamples);

    double rightGini = 0.0;
    if(rightCount > 0){
        for (const auto& classCount : classCountsRight){
            double classProbability = static_cast<double>(classCount.second) / rightCount;
            rightGini += classProbability * (1.0 - classProbability);
        }
    }
    rightGini = rightGini * (static_cast<double>(rightCount)/totalSamples);

    return leftGini + rightGini;
}