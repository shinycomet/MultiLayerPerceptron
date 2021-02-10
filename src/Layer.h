//
// Created by adrien on 09/02/2021.
//

#ifndef MULTILAYERPERCEPTRON_LAYER_H
#define MULTILAYERPERCEPTRON_LAYER_H

#include "Neuron.h"

#include <vector>
#include <iostream>

class Layer {
public :
    Layer(unsigned, unsigned, unsigned);
    void display();
    void init();

private :
    unsigned depth, next_depth, index;
    std::vector<Neuron> n;
};


#endif //MULTILAYERPERCEPTRON_LAYER_H
