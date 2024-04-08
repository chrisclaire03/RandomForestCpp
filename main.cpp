/// Random Forest Main
/// @author: Christopher Claire
/// @lastmodified: 4/6/2024
//sepal_length,sepal_width,petal_length,petal_width,species

#include "include/randomForest.h"
#include<iostream>

int main(int argc, char *argv[]){
    if(argc != 3){
        std::cerr << "incorrect use of arguments" << std::endl;
        return 1;
    }

    Data data;
    std::string dataset = argv[1];
    int targetFeatureIndex = std::stoi(argv[2]);
    data.loadDataFromCSV(dataset, targetFeatureIndex);
    std::pair<Data,Data> splitDataset = data.splitData(0.9);
    Data train = splitDataset.first;
    Data test = splitDataset.second;
    std::vector<double> input = {4.6,3.4,1.4,0.3};
    RandomForest rf(10,10,5,3,5);
    rf.train(train);
    for(int i = 0; i < test.getSampleSize(); i++){
        if(rf.predict(test.getFeatureVector(i)) == test.getLabel(i)){
            std::cout << "Correct Prediction" << std::endl;
        }
        else{
            std::cout << "Incorrect Prediction" << std::endl;
        }
    }
    
    return 0;
}