#include "../include/data.h"

void Data::loadDataFromCSV(std::string& csvFileName, int targetFeatureIndex){
    std::ifstream csvFile(csvFileName);
    if(!csvFile.is_open()){
        throw std::runtime_error("Unable to load file: " + csvFileName);
    }
    std::string line;

    while(std::getline(csvFile,line)){
        std::vector<double> featureVector;
        std::stringstream ss(line);
        std::string featureVal;
        int currentIndex = 0;
        while(std::getline(ss, featureVal, ',')){
            if(currentIndex != targetFeatureIndex){
                featureVector.push_back(std::stod(featureVal));
            }
            else{
                labels.push_back(featureVal);
            }
            currentIndex++;
        }
        features.push_back(featureVector);
    }

    csvFile.close();
}

void Data::printData(){
    for(int i = 0; i < (int)features.size(); i++){
        for(int j = 0; j < (int)features[i].size(); j++){
            std::cout << features[i][j] << " ";
        }
        std::cout << ": " << labels[i] << std::endl;
    }
}

Data Data::bootstrapData(int numSamples, int numFeatures){   
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> sampleDistribution(0, features.size() - 1);
    std::uniform_int_distribution<int> featureDistribution(0,features[0].size() - 1);

    std::vector<int> sampledFeatures;
    for(int i = 0; i < numFeatures; i++){
        int randomIndex = featureDistribution(gen);
        sampledFeatures.push_back(randomIndex);
    }

    std::vector<std::string> bootstrappedLabels;
    std::vector<std::vector<double>> bootstrappedFeatures;

    for(int i = 0; i < numSamples; i++){
        int randomIndex = sampleDistribution(gen);
        std::vector<double> tempFeatureVector;
        for(int& index : sampledFeatures){
            tempFeatureVector.push_back(features[randomIndex][index]);
        }
        bootstrappedFeatures.push_back(tempFeatureVector);
        bootstrappedLabels.push_back(labels[randomIndex]);
    }

    return Data(bootstrappedFeatures,bootstrappedLabels, sampledFeatures);
}

bool Data::isPure() const {
    std::string firstLabel = labels[0];
    for(int i = 1; i < (int)labels.size(); i++){
        if(labels[i] != firstLabel){
            return false;
        }
    }
    return true;
}

std::pair<Data, Data> Data::splitData(double trainRatio){
    int trainSize = static_cast<int>(getSampleSize() * trainRatio);

    std::vector<int> indices(getSampleSize());
    std::iota(indices.begin(), indices.end(), 0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(indices.begin(), indices.end(), gen);

    std::vector<int> trainIndices(indices.begin(), indices.begin() + trainSize);
    std::vector<int> testIndices(indices.begin() + trainSize,indices.end());

    std::vector<std::vector<double>> trainFeatures;
    std::vector<std::string> trainLabels;
    for(int index : trainIndices){
        trainFeatures.push_back(features[index]);
        trainLabels.push_back(labels[index]);
    }

    std::vector<std::vector<double>> testFeatures;
    std::vector<std::string> testLabels;
    for(int index : testIndices){
        testFeatures.push_back(features[index]);
        testLabels.push_back(labels[index]);
    }

    Data trainData(trainFeatures, trainLabels);
    Data testData(testFeatures, testLabels);

    return std::make_pair(trainData, testData);
}
