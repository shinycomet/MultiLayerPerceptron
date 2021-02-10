//
// Created by adrien on 09/02/2021.
//

#include "Perceptron.h"

Perceptron::Perceptron() {
    std::cout<<"Perceptron created : ";
}

Perceptron::Perceptron(float _lR, unsigned _e, unsigned _in,  unsigned _nbL, unsigned _dL, unsigned _out) {
    std::cout<<"Perceptron created via perceptron constructor"<<std::endl;
    learningRate = _lR;
    epochs       = _e;
    input        = _in;
    nbLayers     = _nbL;
    depthLayers  = _dL;
    output       = _out;
    display();
}

void Perceptron::initLayers() {
    unsigned index = 0;
    l.reserve(nbLayers+2);

    l.push_back(Layer(index++,input,depthLayers));

    for(uint i=0;i<nbLayers-1;++i)
        l.push_back(Layer(index++,depthLayers,depthLayers));

    l.push_back(Layer(index++,depthLayers,output));
    l.push_back(Layer(index++,output,0));

    for(uint i=0;i<nbLayers+2;++i)
        l.at(i).display();
}

bool Perceptron::openDataFile(std::string _data) {
    dataFile.open(_data);
    if(dataFile.is_open()) {
        std::string line;
        getline(dataFile,line);
        numberLines = std::stoi(line);
        fullData.reserve(numberLines);
        return true;
    }
    std::cout<<"Unable to open file"<<std::endl;
    std::exit(1);
}

void Perceptron::getAllData() {
    getDataFromFile();
    //checkData();
}

void Perceptron::getDataFromFile() {
    std::string s;
    std::vector<std::string> data;

    while(getline(dataFile,s) && size != 0) {
        data.push_back(s);
        size--;
    }

    fullData.insert(std::end(fullData),std::begin(data), std::end(data));
}

void Perceptron::closeDataFile() {
    dataFile.close();
}

void Perceptron::convertStoUintAndAffect() {
    for(unsigned i=0;i<fullData.size();++i){
        std::cout<<fullData.at(i)<< " ";
    }
}

void Perceptron::checkData() {
    std::cout<<"Number lines : " << numberLines << std::endl;
   for(unsigned i=0;i<fullData.size();++i)
       std::cout<<fullData.at(i)<< " ";

   std::cout<<std::endl;
}

void Perceptron::collectData(std::string data, unsigned _size){
    size = _size;

    if(openDataFile(data)){
        getAllData();
        closeDataFile();
    }
}

void Perceptron::trainAlgorithm() {
    algoT = new AlgorithmTraining(epochs, learningRate);
}

void Perceptron::display() {
    std::cout<<std::endl;
    std::cout << "|----------------PERCEPTRON CHARACTERISTICS----------------- | " << std::endl;
    std::cout << "|----------------------------------------------------------- | " << std::endl;
    std::cout << "|                                                            | " << std::endl;
    std::cout << "| ";
    std::cout << "lR  : " << learningRate << ", ";
    std::cout << "epo : " << epochs       << ", ";
    std::cout << "in  : " << input        << ", ";
    std::cout << "nbL : " << nbLayers     << ", ";
    std::cout << "dL  : " << depthLayers  << ", ";
    std::cout << "out : " << output       << std::endl;
    std::cout << "| Layer                                                      | " << std::endl;
    std::cout << "| (#indexLayer) depth_of_layer - next_depth_of_layer         | " << std::endl;
    std::cout << "| Neuron                                                     | " << std::endl;
    std::cout << "| value : (bias) weight1 weight2 weight3 .... weightN        | " << std::endl;
    std::cout << "|                                                            | " << std::endl;
    std::cout << "|----------------------------------------------------------- | " << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
void Perceptron::setPerceptron(float _lR, unsigned _e, unsigned _in,  unsigned _nbL, unsigned _dL, unsigned _out) {
    std::cout<<"via set procedure"<<std::endl;
    learningRate = _lR;
    epochs       = _e;
    input        = _in;
    nbLayers     = _nbL;
    depthLayers  = _dL;
    output       = _out;
    display();
}