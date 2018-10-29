/**************************************************************
 * File:    Meat.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for meat class
 * Contains food name, FOOD_TYPE.
 *
 *************************************************************/


#include "Food.h"

#ifndef MEAT_H_
#define MEAT_H_

using namespace std;

class Meat: public Food{

	public:

		// Constructor
		Meat(string sName, double dCost);

		// PrintFood()
		void printFood(ofstream* file);

};


#endif /* MEAT_H_ */
