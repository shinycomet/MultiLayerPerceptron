//
// Created by adrien on 09/02/2021.
//

#include "Layer.h"

Layer::Layer(unsigned _index, unsigned _d, unsigned _nD) {
    depth      = _d;
    next_depth = _nD;
    index      = _index;

    init();
}

void Layer::init() {
    n.reserve(depth);
    for(uint i=0;i<depth;++i){
        n.push_back(Neuron(next_depth));
    }
}

void Layer::display() {

    std::cout<<"(#" << index << ") d " << depth << " - nD " << next_depth << std::endl;

    for(uint i=0;i<depth;++i)
        n.at(i).display();
    std::cout<<std::endl;
}