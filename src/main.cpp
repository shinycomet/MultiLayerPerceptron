#include <string>
#include <cstring>
#include <iostream>
#include "Perceptron.h"

void help(){
    std::cout << std::endl;
    std::cout << "| ---------------- HELP SECTION ---------------- | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| Type    : --help for help                      | " << std::endl;
    std::cout << "| Compile : make  ->  ./bin/main a b c d e f g   | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| -------------- ARGUMENT SECTION -------------- | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| 1(a)-Number of iterations (epochs) (unsigned), | " << std::endl;
    std::cout << "| 2(b)-Learning rate                 (float),    | " << std::endl;
    std::cout << "| 3(c)-Number of inputs              (unsigned), | " << std::endl;
    std::cout << "| 4(d)-Number of hidden layers       (unsigned), | " << std::endl;
    std::cout << "| 5(e)-Number of neurons per layer   (unsigned), | " << std::endl;
    std::cout << "| 6(f)-Number of outputs             (unsigned), | " << std::endl;
    std::cout << "| 7(g)-Activation function           (string)    | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| ------ 7(g)ACTIVATION FUNCTIONS SECTION ------ | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| Different types of activation functions  :     | " << std::endl;
    std::cout << "| Tanh (tanh)                                    | " << std::endl;
    std::cout << "| Relu (relu)                                    | " << std::endl;
    std::cout << "| Softmax (softmax)                              | " << std::endl;
    std::cout << "| Sigmoid (sigmoid)                              | " << std::endl;
    std::cout << "| Identity (identity)                            | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| ---------------- GOOD TO KNOW ---------------- | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| Total nb of layers  : 1 + hidden layers + 1    | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| --------------- EXTRA DEBUGGING -------------- | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "| Segmentation fault debugging :                 | " << std::endl;
    std::cout << "| -1- Missing arguments (command line)           | " << std::endl;
    std::cout << "| -2- Too many arguments (command line)          | " << std::endl;
    std::cout << "|                                                | " << std::endl;
    std::cout << "|----------------------------------------------- | " << std::endl;
    std::cout << std::endl;
}

Perceptron check_command_validity(char ** argv){
    float learningRate   = atoi(argv[1]);
    unsigned epochs      = atoi(argv[2]);
    unsigned input       = atoi(argv[3]);
    unsigned nbLayers    = atoi(argv[4]);
    unsigned depthLayers = atoi(argv[5]);
    unsigned output      = atoi(argv[6]);

    Perceptron temp(learningRate,epochs,input,nbLayers,depthLayers,output);
    return temp;
}

Perceptron parse_command_line(char ** argv) {
    if (!strcmp(argv[1], "--help"))
        help();
    else
        return check_command_validity(argv);
    exit(0);
}

int main(int argc, char ** argv) {
    srand(static_cast<unsigned>(time(0))); // random seed
    Perceptron p = parse_command_line(argv);
    p.initLayers();
    p.collectData("data/data.txt",20);
    p.trainAlgorithm();
    return 0;
}
