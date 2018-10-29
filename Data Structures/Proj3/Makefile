all: AugmentedBinarySearchTree.o BinarySearchTree.o Proj3Aux.o Proj3.o
	g++ -Wall Proj3.o Proj3Aux.o AugmentedBinarySearchTree.o BinarySearchTree.o -o output.out

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -Wall -c BinarySearchTree.cpp

AugmentedBinarySearchTree.o: AugmentedBinarySearchTree.cpp
	g++ -Wall -c AugmentedBinarySearchTree.cpp
	
Proj3Aux.o: Proj3Aux.cpp
	g++ -Wall -c Proj3Aux.cpp
	
Proj3.o: Proj3.cpp
	g++ -Wall -c Proj3.cpp


# -f removes any error messages if the file is not present
clean:
        rm -rf *.o
        rm -f *.out
        rm -f *~ *.h.gch *#
run:
	./output.out $(FILE) $(COMMANDS)
