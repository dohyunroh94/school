/**************************************************************
 * File:    HashLibrary.cpp
 * Project: CMSC 341 - Project 5 - Hash table
 * Author : Dohyun Roh
 * Date   : 12/1/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation for hash library
 * Contains the various hash functions
 *************************************************************/

#include "HashLibrary.h"

// lengthHash
// Returns the word length
int lengthHash(std::string word){

	return word.length();
}

// sumHash
// Calculates sum of ascii values of characters in string
int sumHash(std::string word){

	int sum = 0;

	// Converts the characters from string into ascii values and sums them up
	for(unsigned int index = 0; index < word.length(); index++){

		char letter = word.at(index);

		sum += int(letter);

	}

	return sum;

}

// sumProdHash
// Calculates sum of product ascii values of characters and respective
// (index + 1) in string
int sumProdHash(std::string word){

	int sum = 0;

	// Sums the product of ascii values and index + 1 of chars in word
	for(unsigned int index = 0; index < word.length(); index++){

		char letter = word.at(index);

		// Sums (ascii value) x (index + 1)
		sum += int(letter) * (index + 1);

	}

	return sum;

}

// polynomialHash
// Calculates sum of product ascii values of characters and
// base raised to respective index
int polynomialHash(std::string word, int base){

	int sum = 0;

	for(unsigned int index = 0; index < word.length(); index++){

		char letter = word.at(index);

		// Sums up (ascii value of char x base to the power of index)
		sum += int(letter) * int((pow(double(base), double(index))));

	}

	return sum;
}


