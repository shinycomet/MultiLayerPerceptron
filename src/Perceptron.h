//
// Created by adrien on 09/02/2021.
//


#ifndef MULTILAYERPERCEPTRON_PERCEPTRON_H
#define MULTILAYERPERCEPTRON_PERCEPTRON_H

#include "Layer.h"
#include "AlgorithmTraining.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class AlgorithmTraining; //not nice to do it but works

class Perceptron {
public :
    Perceptron();
    Perceptron(float, unsigned, unsigned, unsigned, unsigned, unsigned);
    void setPerceptron(float, unsigned, unsigned, unsigned, unsigned, unsigned);

    void initLayers();

    void collectData(std::string, unsigned);

    bool openDataFile(std::string);
    void getAllData();
    void getDataFromFile();
    void closeDataFile();

    void trainAlgorithm();
    void loopEpochs();
    void convertStoUintAndAffect();

    void checkData();//debug
    void display();

private :
    AlgorithmTraining * algoT;
    std::fstream dataFile;
    float learningRate;
    std::vector<Layer> l;
    std::vector<std::string> fullData;
    unsigned epochs, input, nbLayers, depthLayers, output, numberLines, size;
};


#endif //MULTILAYERPERCEPTRON_PERCEPTRON_H
