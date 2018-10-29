/**************************************************************
 * File:    Fruit.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for fruit class
 * Contains food name, FOOD_TYPE.
 *
 *************************************************************/

#include "Food.h"
#ifndef FRUIT_H_
#define FRUIT_H_

using namespace std;

class Fruit : public Food{

	public:

		// Constructor
		Fruit(string sName, double dCost);

		// PrintFood()
		void printFood(ofstream* file);

};



#endif /* FRUIT_H_ */
