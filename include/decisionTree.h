/// Decision Tree
/// This...
/// @author: Christopher Claire
/// @lastmodified: 3/7/2024

#ifndef DECISION_TREE_H
#define DECISION_TREE_H

#include "node.h"
#include "data.h"
#include<cmath>
#include<unordered_map>


class DecisionTree{
    private:
        Node* root;
        int maxDepth;
        int minSamplesSplit;
        Node* buildTree(Data& data, int depth);
        Node* createLeafNode(Data& data);
        double calculateGini(Data& data, int featureIndex, double threshold);
        std::string predict(const std::vector<double>& input, Node* curNode);
    public:
        DecisionTree(int maxDepth, int minSamplesSplit) : root(nullptr), maxDepth(maxDepth), minSamplesSplit(minSamplesSplit){};
        void train(Data &trainData);
        std::string predict(const std::vector<double>& input);

};

#endif