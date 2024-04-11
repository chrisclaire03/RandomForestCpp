/// Decision Tree
/// @author: Christopher Claire
/// @lastmodified: 4/6/2024

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
        Node* buildTree(const Data& data, int depth);
        Node* createLeafNode(const Data& data);
        Node* copy(Node* cur);
        double calculateGini(const Data& data, int featureIndex, double threshold);
        std::string predict(const std::vector<double>& input, Node* curNode);
        void clean(Node* cur);
    public:
        DecisionTree(int maxDepth, int minSamplesSplit) : root(nullptr), maxDepth(maxDepth), minSamplesSplit(minSamplesSplit){};
        ~DecisionTree(){delete root;};
        DecisionTree(const DecisionTree& other) : root(copy(other.root)), maxDepth(other.maxDepth), minSamplesSplit(other.minSamplesSplit){};
        void train(const Data& trainData);
        std::string predict(const std::vector<double>& input);
};

#endif