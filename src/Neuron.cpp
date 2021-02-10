//
// Created by adrien on 10/02/2021.
//

#include "Neuron.h"

Neuron::Neuron(unsigned _number_weights) {
    number_weights = _number_weights;

    if(number_weights>0) {
        weights.reserve(number_weights);
        for (unsigned i = 0; i < number_weights; ++i)
            weights.push_back(floor(static_cast<float> (rand()) / static_cast<float> (RAND_MAX)*scale)/scale);
    }

    bias  = floor(static_cast<float> (rand()) / static_cast<float> (RAND_MAX)*scale)/scale;
    value = floor(static_cast<float> (rand()) / static_cast<float> (RAND_MAX)*scale)/scale;
}

void Neuron::display() {
    std::cout<< value;

    if(number_weights>0) {
        std::cout<<" : ( " << bias << " ) ";
        for (unsigned i = 0; i < number_weights; ++i)
            std::cout << weights.at(i) << " ";
    }

    std::cout<<std::endl;
}