B = bin
O = obj
S = src
FLAGS = -c -Wall

all: $(O) $(B) $(B)/main

$(B)/main: $(O)/Perceptron.o 
	g++ $(CFLAGS) $(LIBS) $(S)/main.cpp -o $(B)/main $(O)/*.o 
	
$(O)/AlgorithmTraining.o: $(O)/Perceptron.o $(O)/Layer.o $(O)/Neuron.o
	g++ $(FLAGS) $(CFLAGS) $(LIBS) $(S)/AlgorithmTraining.cpp -o $(O)/AlgorithmTraining.o 	
	
$(O)/Perceptron.o: $(O)/AlgorithmTraining.o $(O)/Layer.o 
	g++ $(FLAGS) $(CFLAGS) $(LIBS) $(S)/Perceptron.cpp -o $(O)/Perceptron.o 
	
$(O)/Layer.o: $(O)/Neuron.o
	g++ $(FLAGS) $(CFLAGS) $(LIBS) $(S)/Layer.cpp -o $(O)/Layer.o 
	
$(O)/Neuron.o: 
	g++ $(FLAGS) $(CFLAGS) $(LIBS) $(S)/Neuron.cpp -o $(O)/Neuron.o 

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)

clean: $(O) $(B)
	rm -rf $(O)
	rm -rf $(B)
	
