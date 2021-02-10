//
// Created by adrien on 10/02/2021.
//

#ifndef MULTILAYERPERCEPTRON_ALGORITHMTRAINING_H
#define MULTILAYERPERCEPTRON_ALGORITHMTRAINING_H

#include "Neuron.h"
#include "Layer.h"
#include "Perceptron.h"

class AlgorithmTraining {
public :
    AlgorithmTraining(unsigned, float);
    void display();

private :
    float learningRate;
    unsigned epochs;
};


#endif //MULTILAYERPERCEPTRON_ALGORITHMTRAINING_H
