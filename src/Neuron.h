//
// Created by adrien on 10/02/2021.
//

#ifndef MULTILAYERPERCEPTRON_NEURON_H
#define MULTILAYERPERCEPTRON_NEURON_H

#include <cmath>
#include <vector>
#include <iostream>

class Neuron {
public :
    Neuron(unsigned);
    void display();

private :
    float value, bias;
    std::vector<float> weights;
    unsigned number_weights, scale = 1000.0;
};


#endif //MULTILAYERPERCEPTRON_NEURON_H
