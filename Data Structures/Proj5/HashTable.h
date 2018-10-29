/**************************************************************
 * File:    HashTable.h
 * Project: CMSC 341 - Project 5 - Hash table
 * Author : Dohyun Roh
 * Date   : 12/1/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for Hash Table class
 * Uses vector of vector of strings to imitate actual
 * hash table with chaining as collision handling method
 *
 *************************************************************/

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <vector>
#include <string>

class HashTable{


	public:

		// Enum type to specify which hash function it uses
		enum FUNC_TYPE{

			LEN, SUM, SUM_PROD, POLY

		};

		// Constructors

		// For non-base provided case
		HashTable(int size, int (*hashFunction)(std::string word), FUNC_TYPE);

		// For base provided case
		HashTable(int size, int base);

		//-------------------------------------------------------
		// Name: insert
		// PreCondition: valid string is provided
		// PostCondition: string is inserted into a specified hash value index into
		// the hash table
		//---------------------------------------------------------
		void insert (std::string);

		//-------------------------------------------------------
		// Name: getNumberOfCollisions
		// PreCondition: none
		// PostCondition: Calculates the number of collisions in
		// the hash table
		//---------------------------------------------------------
		int getNumberOfCollisions();

		// Getters

		int getSize();
		int getBase();
		FUNC_TYPE getType();

	private:

		// Size and base values
		int m_size;
		int m_base;

		// Pointers for hash functions
		int (*m_hashFunction)(std::string word);

		// (This one is used only for polynomial case)
		int (*m_polyHashFunction)(std::string word, int base);

		// Type of hash function
		FUNC_TYPE m_type;

		// Vector of vector of strings used store buckets and keys
		// (used to represent hash table)
		std::vector <std::vector<std::string> > m_buckets;

};
#endif /* HASHTABLE_H_ */
