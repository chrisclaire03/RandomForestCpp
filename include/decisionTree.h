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
        Node* buildTree(Data data, int depth);
        Node* createLeafNode(Data data);
        double calculateGini(Data data, int featureIndex, double threshold);
        std::string predict(const std::vector<double>& input, Node* curNode);
        void clean(Node* cur);
    public:
        DecisionTree(int maxDepth, int minSamplesSplit) : root(nullptr), maxDepth(maxDepth), minSamplesSplit(minSamplesSplit){};
        ~DecisionTree(){clean(root); root = nullptr;};
        void train(Data trainData);
        std::string predict(const std::vector<double>& input);
};

#endif