/// Node
/// This...
/// @author: Christopher Claire
/// @lastmodified: 3/7/2024

#ifndef NODE_H
#define NODE_H
#include<string>

class Node{
    public:
        int featureIndex;
        double threshold;
        std::string label;
        Node* left;
        Node* right;


        Node(int bestFeatureIndex, double bestThreshold, Node* leftChild, Node* rightChild){
            featureIndex = bestFeatureIndex;
            threshold = bestThreshold;
            left = leftChild;
            right = rightChild;
        };

        Node(std::string aLabel){
            label = aLabel;
            left = nullptr;
            right = nullptr;
        }

        bool isLeaf(){
            if(left == nullptr && right == nullptr){
                return true;
            }
            else{
                return false;
            }
        }
};

#endif