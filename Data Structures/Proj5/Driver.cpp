/**************************************************************
 * File:    Driver.cpp
 * Project: CMSC 341 - Project 5 - Hash table
 * Author : Dohyun Roh
 * Date   : 12/1/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Driver file for testing hash tables.
 * Uses a vector of hash tables to find
 * out which hash table is the best
 * based on how many collisions each one has
 * given an input file
 *************************************************************/

#include "HashTable.h"
#include "HashLibrary.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>


using namespace std;

// isPrime
// returns true or false based on
// whether given number is prime or not
bool isPrime(int num){

	// Checks if there are other divisors besides 1 and itself
	for(int divisor= 2; divisor < num; divisor++){

		// If other divisor is found, not prime
		if ((num % divisor) == 0){

			return false;

		}

	}

	return true;

}

// readFile
// Reads words from file given into a vector of
// strings and returns the vector
vector<string> readFile(string filename){

	vector<string> words;
	string text;
	string word;
	istringstream stream;

	const char* name = filename.c_str();
	ifstream file;
	file.open(name);

	getline(file, text);
	stream.str(text);

	while(stream >> word){

		words.push_back(word);

	}

	return words;
}

int main(int argc, char *argv[]){

	// Variables used for extracting command line data
	string fileName;
	vector<string> listOfWords;
	int minSize;
	int maxSize;
	int minBase;
	int maxBase;

	// Used to store the prime numbers from min and max values
	vector<int>listOfPrimes;

	// Used to test each possible table
	vector<HashTable*> listOfTables;

	HashTable * currentTable;
	HashTable * bestTable;

	// Function pointers for hash functions
	int (*length)(string);
	int (*sum)(string);
	int (*sumProd)(string);

	length = &lengthHash;
	sum = &sumHash;
	sumProd = &sumProdHash;

	// When the bases are provided follows and all rules of input
	// are followed
	// (max base > min base, max size > min size, all numbers are positive)
	if (argc == 6 && (atoi(argv[5]) > atoi(argv[4]))
			&& (atoi(argv[3]) > atoi(argv[2])) &&
			((atoi(argv[5]) > 0) && (atoi(argv[4]) > 0)) &&
			((atoi(argv[3]) > 0) && (atoi(argv[2]) > 0))){

		// Grabs command line argumentss
		fileName = argv[1];
		minSize = atoi(argv[2]);
		maxSize = atoi(argv[3]);
		minBase = atoi(argv[4]);
		maxBase = atoi(argv[5]);

		listOfWords = readFile(fileName);

		// Makes a list of primes from the min and max size
		for(int index5 = minSize; index5 <= maxSize; index5++){

			if (isPrime(index5)){

				listOfPrimes.push_back(index5);

			}

		}

		// Fills the list of tables with tables of viable prime number sizes and bases
		for (unsigned int index6 = 0; index6 < listOfPrimes.size(); index6++){

			// Makes a table for every possible base between min and max
			for (int baseIndex = minBase; baseIndex < maxBase; baseIndex++){

				listOfTables.push_back(new HashTable(listOfPrimes[index6], baseIndex));

			}

		}


		// For every hash table in the list, inserts all the words from input file
		for (unsigned int index7 = 0; index7 < listOfTables.size(); index7++){

			currentTable = listOfTables[index7];

			for(unsigned int index8 = 0; index8 < listOfWords.size(); index8++){

				currentTable->insert(listOfWords[index8]);

			}

		}

		// Determines which table is best by smallest collision number

		// By default, sets best table to 1st one
		bestTable = listOfTables[0];

		// Checks tables to see which table has lowest collision number by
		// comparing currentTable collisions to the recent bestTable collisions
		for (unsigned int listOfTablesIndex = 0; listOfTablesIndex < listOfTables.size(); listOfTablesIndex++){

			currentTable = listOfTables[listOfTablesIndex];

			// bestTable changes if better table with lower collisions is found
			if (currentTable->getNumberOfCollisions() < bestTable->getNumberOfCollisions()){

				bestTable = currentTable;

			}

		}

		// Prints out possible bucket sizes from listOfPrimes
		cout << "Bucket Sizes: ";

		for (unsigned int primeIndex = 0; primeIndex < (listOfPrimes.size()-1); primeIndex++){

			cout << listOfPrimes[primeIndex] << ", ";

		}

		// prints last prime (due to comma issues)
		cout << listOfPrimes[listOfPrimes.size()-1] << endl;


		// Prints number of words inserted
		cout << "Loaded " << listOfWords.size() << " words from input.txt" << endl;

		// Recommends the best table with optimal size and base
		cout << "Recommend polynomial hash function with size: " << bestTable->getSize()
			<< ", base: " << bestTable->getBase() << ", collisions: "
			<< bestTable->getNumberOfCollisions();

		// Deletes the hash tables from vector
		for (unsigned int lastIndex  = 0; lastIndex < listOfTables.size(); lastIndex++){

			delete listOfTables[lastIndex];
			listOfTables[lastIndex] = NULL;
		}


	// Bases not provided (polynomial function not tested)
	// (Checks argument size, max size > min size, max > 0 min > 0
	} else if ((argc == 4) && (atoi(argv[3]) > atoi(argv[2])) &&
			 ((atoi(argv[3]) > 0) && (atoi(argv[2]) > 0))) {

		// Grabs command line args
		fileName = argv[1];
		minSize = atoi(argv[2]);
		maxSize = atoi(argv[3]);

		// Reads the file with function above
		listOfWords = readFile(fileName);

		// Makes a list of primes based on min and max size
		for(int index = minSize; index <= maxSize; index++){

			if (isPrime(index)){

				listOfPrimes.push_back(index);

			}

		}

		// Adds to list of hash tables for each prime number
		// 3 new hash tables for each function
		for (unsigned int index2 = 0; index2 < listOfPrimes.size(); index2++){

			listOfTables.push_back(new HashTable(listOfPrimes[index2], length, HashTable::LEN));
			listOfTables.push_back(new HashTable(listOfPrimes[index2], sum, HashTable::SUM));
			listOfTables.push_back(new HashTable(listOfPrimes[index2], sumProd, HashTable::SUM_PROD));

		}

		// Inserts the words into every single hash table
		for (unsigned int index3 = 0; index3 < listOfTables.size(); index3++){

			currentTable = listOfTables[index3];

			for(unsigned int index4 = 0; index4 < listOfWords.size(); index4++){

				currentTable->insert(listOfWords[index4]);

			}

		}

		// Determines which table is best by smallest collision number

		// By default, sets best table to 1st one
		bestTable = listOfTables[0];

		// Checks tables to see which table has lowest collision number by
		// comparing currentTable collisions to the recent bestTable collisions
		for (unsigned int listOfTablesIndex1 = 0; listOfTablesIndex1 < listOfTables.size(); listOfTablesIndex1++){

			currentTable = listOfTables[listOfTablesIndex1];

			// bestTable changes if better table with lower collisions is found
			if (currentTable->getNumberOfCollisions() < bestTable->getNumberOfCollisions()){

				bestTable = currentTable;

			}

		}

		// Prints out possible bucket sizes from listOfPrimes
		cout << "Bucket Sizes: ";

		for (unsigned int primeIndex1 = 0; primeIndex1 < (listOfPrimes.size()-1); primeIndex1++){

			cout << listOfPrimes[primeIndex1] << ", ";

		}

		// prints last prime (due to comma issues)
		cout << listOfPrimes[listOfPrimes.size()-1] << endl;


		// Shows number of words inserted
		cout << "Loaded " << listOfWords.size() << " words from input.txt" << endl;

		// Uses enum type FUNC_TYPE to determine whether the
		// best tables used length, sum, or sum producton hash function

		// Recommends the best table with optimal size and function type
		if ((bestTable->getType()) == HashTable::LEN){
			cout << "Recommend Length hash function with size: " << bestTable->getSize()
					<< ", collisions: "<< bestTable->getNumberOfCollisions();

		} else if ((bestTable->getType()) == HashTable::SUM){
			cout << "Recommend Sum hash function with size: " << bestTable->getSize()
					<< ", collisions: "<< bestTable->getNumberOfCollisions();

		} else {
			cout << "Recommend Sum Production hash function with size: " << bestTable->getSize()
					<< ", collisions: "<< bestTable->getNumberOfCollisions();

		}

		// Deletes the hash tables from vector
		for (unsigned int lastIndex1  = 0; lastIndex1 < listOfTables.size(); lastIndex1++){

			delete listOfTables[lastIndex1];
			listOfTables[lastIndex1] = NULL;
		}

	// If wrong number of inputs or wrong inputs, error message is provided
	} else {

		cout << "Usage: make run INPUT=<filename> MIN_SIZE=<positive integer> " <<
			"MAX_SIZE=<positive integer larger than MIN_SIZE> [MIN_BASE=<positive" <<
			"integer> MAX_BASE=<positive integer larger than MIN_BASE>]";

	}

	cout << endl;

}

