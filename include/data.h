/// Data Class
/// @author: Christopher Claire
/// @lastmodified: 4/6/2024

#ifndef DATA_H
#define DATA_H

#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<random>
#include<algorithm>

class Data{
    private:
        std::vector<std::vector<double>> features;
        std::vector<std::string> labels;
        std::vector<int> featureIndices;
    public:
        Data(){};
        Data(std::vector<std::vector<double>> featureVector,std::vector<std::string> labelVector): features(featureVector), labels(labelVector){
            for(int i = 0; i < (int)featureVector[0].size(); i++){
                featureIndices.push_back(i);
            }
        };
        Data(std::vector<std::vector<double>> featureVector,std::vector<std::string> labelVector, std::vector<int> features):
        features(featureVector), labels(labelVector), featureIndices(features){};
        void loadDataFromCSV(std::string& csvFileName, int targetFeatureIndex);
        void printData();
        Data bootstrapData(int numSamples, int numFeatures);
        
        std::pair<Data, Data> splitData(double trainRatio);

        int getFeatureSize() const {
            return features[0].size();
        };
        int getSampleSize() const {
            return features.size();
        };

        std::vector<double> getFeatureVector(int index) const {return features[index];}

        int getFeatureIndex(int index) const{return featureIndices[index];}
        std::vector<int> getFeatureIndices() const{return featureIndices;}

        double getFeature(int featureIndex, int sampleIndex) const{
            if(featureIndex < getFeatureSize() && sampleIndex < getSampleSize()){
                return features[sampleIndex][featureIndex];
            }
            else{
                return -1;
            }
        }
        
        bool isPure() const;

        std::string getLabel(int index) const {return labels[index];}


};

#endif