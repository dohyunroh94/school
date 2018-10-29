/**************************************************************
 * File:    Sweet.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for Sweet class
 * Contains food name, FOOD_TYPE.
 *
 *************************************************************/


#include "Food.h"
#ifndef SWEET_H_
#define SWEET_H_

using namespace std;

class Sweet:public Food{

	public:

		// Constructor
		Sweet(string sName, double dCost);

		// printFood()
		void printFood(ofstream* file);

};
#endif /* SWEET_H_ */
