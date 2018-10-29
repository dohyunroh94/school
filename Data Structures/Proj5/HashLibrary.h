/**************************************************************
 * File:    HashLibrary.h
 * Project: CMSC 341 - Project 5 - Hash table
 * Author : Dohyun Roh
 * Date   : 12/1/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for hash library
 * Contains the various hash functions
 *************************************************************/


#ifndef HASHLIBRARY_H_
#define HASHLIBRARY_H_

#include <string>
#include "math.h"

	//-------------------------------------------------------
	// Name: lengthHash
	// PreCondition: valid string
	// PostCondition: Calculates the hash value
	// based on the length of the string
	//---------------------------------------------------------
	int lengthHash(std::string word);

	//-------------------------------------------------------
	// Name: sumHash
	// PreCondition: valid string
	// PostCondition: Calculates the hash value
	// based on the sum of the value of ascii values of chars in string
	//---------------------------------------------------------
	int sumHash(std::string word);

	//-------------------------------------------------------
	// Name: sumProdHash
	// PreCondition: valid string
	// PostCondition: Calculates the hash value
	// based on the sum of the value of ascii values of chars in string
	// multiplied by the index plus 1
	//---------------------------------------------------------
	int sumProdHash(std::string word);

	//-------------------------------------------------------
	// Name: polynomailHash
	// PreCondition: valid string
	// PostCondition: Calculates the hash value
	// based on sum of the value of ascii values of chars in string
	// multiplied by power of base (based on index)
	//---------------------------------------------------------
	int polynomialHash(std::string word, int base);

#endif /* HASHLIBRARY_H_ */
