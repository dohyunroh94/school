/**************************************************************
 * File:    HashTable.cpp
 * Project: CMSC 341 - Project 5 - Hash table
 * Author : Dohyun Roh
 * Date   : 12/1/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation for hash table class
 *
 *************************************************************/
#include "HashTable.h"
#include "HashLibrary.h"

// Constructors

// For no bases provided case
HashTable::HashTable(int size, int (*hashFunction)(std::string word), HashTable::FUNC_TYPE type){

	m_size = size;
	m_hashFunction = hashFunction;
	m_type = type;
	m_buckets.resize(size);

	// Sets these to NULL and -1 as polynomial is never used
	m_polyHashFunction = NULL;
	m_base = -1;

}

// For bases provided case
HashTable::HashTable(int size, int base){

	m_size = size;
	m_polyHashFunction = &polynomialHash;
	m_hashFunction = NULL;
	m_base = base;
	m_type = HashTable::POLY;

	m_buckets.resize(size);
}

// insert
// Inserts the word into one of the buckets based on
// calculated hash value
void HashTable::insert (std::string word){

	int hashValue = 0;

	// For non polynomial hash function tables
	// (Will have default base value of -1 (unused))
	if (m_base == -1){

		// Uses specified hash function
		hashValue = (*m_hashFunction)(word);
		hashValue = (hashValue % m_size);

	// For polynomial hash function tables
	} else {

		// Will always use polynomial hash function
		hashValue = (*m_polyHashFunction)(word ,m_base);
		hashValue = (hashValue % m_size);
	}

	// Uses calculated hash value as index for which bucket to insert in
	m_buckets[hashValue].push_back(word);


}

// getNumberOfCollisions
// Counts the total number of collisions in the
// hash table (not really a "getter function" because
// it calculates it every time)
// (Note: Uses vector as way of chaining for collision
// handling)
int HashTable::getNumberOfCollisions(){

	int collisions = 0;

	// Checks how many buckets had more than
	// two words in it (which counts as just one collision)
	for (int index = 0; index < m_size; index++){

		if (m_buckets[index].size() > 1){

			collisions++;

		}

	}

	return collisions;

}

// Getters

int HashTable::getSize(){

	return m_size;

}

int HashTable::getBase(){

	return m_base;

}

HashTable::FUNC_TYPE HashTable::getType(){

	return m_type;

}
