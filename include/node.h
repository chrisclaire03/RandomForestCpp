/// Node
/// @author: Christopher Claire
/// @lastmodified: 4/10/2024

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

        ~Node(){
            if(!isLeaf()){
                delete left;
                delete right;
            }

        }

        Node(const Node& other){
            if(other.isLeaf()){
                Node(other.label);
            }
            else{
                Node(other.featureIndex, other.threshold, other.left, other.right);
            }   
        }

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

        bool isLeaf() const{
            if(left == nullptr && right == nullptr){
                return true;
            }
            else{
                return false;
            }
        }
};

#endif