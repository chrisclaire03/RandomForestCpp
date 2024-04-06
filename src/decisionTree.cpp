#include "../include/decisionTree.h"

void DecisionTree::train(Data &trainData){
    root = buildTree(trainData, 0);
}

Node* DecisionTree::buildTree(Data& data, int depth){
    if(depth >= maxDepth || data.isPure()){
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

    std::vector<std::vector<double>> leftFeatures;
    std::vector<std::vector<double>> rightFeatures;

    std::vector<std::string> leftLabels;
    std::vector<std::string> rightLabels;

    int featuresSize;

    for(int i = 0; i < data.getSampleSize(); i++){
        std::vector<double> temp;
        for(int j = 0; j < featuresSize; j++){
            if(j != bestFeatureIndex){
                temp.push_back(data.getFeature(j,i));
            }
        }
        if(data.getFeature(bestFeatureIndex, i) <= bestThreshold){
            leftFeatures.push_back(temp);
            leftLabels.push_back(data.getLabel(i));
        }
        else{
            rightFeatures.push_back(temp);
            rightLabels.push_back(data.getLabel(i));
        }
    }

    Data leftSubset(leftFeatures,leftLabels);
    Data rightSubset(rightFeatures, rightLabels);

    Node* leftChild = buildTree(leftSubset, depth + 1);
    Node* rightChild = buildTree(rightSubset, depth + 1);

    return new Node(bestFeatureIndex,bestThreshold, leftChild, rightChild);
    
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

Node* createLeafNode(Data& data){
    std::unordered_map<std::string, int> labelCounts;
    for(int i = 0; i < data.getSampleSize(); i++){
        labelCounts[data.getLabel(i)]++;
    }
    std::string mostCommonLabel = "";
    int maxCount = 0;
    for(const auto& label : labelCounts){
        if(label.second > maxCount){
            mostCommonLabel = label.first;
        }
    }

    return new Node(mostCommonLabel);
}

std::string DecisionTree::predict(const std::vector<double>& input){
    return predict(input, root);
}

std::string DecisionTree::predict(const std::vector<double>& input, Node* cur){
    if(cur->isLeaf()){
        return cur->label;
    }
    if(input[cur->featureIndex] <= cur->threshold){
        return predict(input, cur->left);
    }
    else{
        return predict(input, cur->right);
    }
}