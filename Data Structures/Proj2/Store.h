/**************************************************************
 * File:    Store.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for Store class
 * Represents a store with a vector of stacks that
 * represent each food type and holds foods of that type
 *************************************************************/


#include <iostream>
#include "Food.h";
#include <vector>;
#include <stack>;


#ifndef STORE_H_
#define STORE_H_

class Store{

	public:

		// Constructor
		Store();

		// Destructor
		~Store();

		// Getters
		Food* getFoodByType(Food::FOOD_TYPE);
		bool isEmpty(Food::FOOD_TYPE);

		// addFood()
		// preconditions: none
		// postconditions: will add Food object to m_bins
		void addFood(Food*);

		// stockStore
		// preconditions: file must be valid
		// postconditions: Fills m_bins vector of stacks
		// with food from an input file
		void stockStore(string filename);

		// printStore
		// preconditions: None
		// postconditions: Writes to a file
		// the foods the store has
		void printStore(ofstream*);

	private:

		// Note: For this program
		// each stack represents a food type
		// indexes 0, 1, 2, 3, 4
		// will represent
		// Meat, Fruit, Vegetable, Starch, Sweet
		// respectively
		vector<stack <Food*> > m_bins;

};
#endif /* STORE_H_ */
