all: HashLibrary.o HashTable.o Driver.o
	g++ -Wall HashLibrary.o HashTable.o Driver.o -o output.out

HashLibrary.o: HashLibrary.cpp
	g++ -Wall -c HashLibrary.cpp

HashTable.o: HashTable.cpp
	g++ -Wall -c HashTable.cpp

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
run:
	./output.out $(INPUT) $(MIN_SIZE) $(MAX_SIZE) $(MIN_BASE) $(MAX_BASE)