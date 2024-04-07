/// Random Forest
/// This...
/// @author: Christopher Claire
/// @lastmodified: 3/7/2024

#ifndef RANDOM_FOREST_H
#define RANDOM_FOREST_H

#include "decisionTree.h"

class RandomForest{
    public:
        RandomForest(int numTrees, int maxDepth, int minSamplesSplit, int featuresPerTree, int samplesPerTree)
        :numTrees(numTrees), maxDepth(maxDepth), minSamplesSplit(minSamplesSplit), featuresPerTree(featuresPerTree), samplesPerTree(samplesPerTree){};

        std::string predict(std::vector<double> input);
        void train(Data& trainData);

    private:
        std::vector<DecisionTree> trees;
        int numTrees;
        int maxDepth;
        int minSamplesSplit;
        int featuresPerTree;
        int samplesPerTree;
};


#endif
