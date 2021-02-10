//
// Created by adrien on 10/02/2021.
//

#include "AlgorithmTraining.h"

AlgorithmTraining::AlgorithmTraining(unsigned _epochs, float _learningRate) {
    epochs       = _epochs;
    learningRate = _learningRate;
    display();
}

void AlgorithmTraining::display() {
    std::cout<<"e : "<< epochs << " lR : " << learningRate << std::endl;
}