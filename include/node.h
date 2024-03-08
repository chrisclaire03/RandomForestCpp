/// Node
/// This...
/// @author: Christopher Claire
/// @lastmodified: 3/7/2024

#ifndef NODE_H
#define NODE_H

class Node{
    public:
        int featureIndex;
        double threshold;
        int label;
        bool isLeaf;
        Node* left;
        Node* right;

        Node(int bestFeatureIndex, double bestThreshold){
            featureIndex = bestFeatureIndex;
            threshold = bestThreshold;
            isLeaf = false;
            left = nullptr;
            right = nullptr;
        };

        Node(bool leaf,int aLabel){
            isLeaf = leaf;
            label = aLabel;
            left = nullptr;
            right = nullptr;
        };
};

#endif