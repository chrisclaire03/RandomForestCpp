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
    public:
        Data(){};
        Data(std::vector<std::vector<double>> featureVector,std::vector<std::string> labelVector): features(featureVector), labels(labelVector){};
        void loadDataFromCSV(std::string& csvFileName, int targetFeatureIndex);
        void printData();
        Data bootstrapData(int numSamples, int numFeatures);
        
        std::pair<Data, Data> splitData(double trainRatio);

        int getFeatureSize() {
            return features[0].size();
        };
        int getSampleSize(){
            return features.size();
        };

        std::vector<double> getFeatureVector(int index){return features[index];}

        double getFeature(int featureIndex, int sampleIndex){
            if(featureIndex < getFeatureSize() && sampleIndex < getSampleSize()){
                return features[sampleIndex][featureIndex];
            }
            else{
                return -1;
            }
        }
        
        bool isPure();

        std::string getLabel(int index){return labels[index];}


};

#endif