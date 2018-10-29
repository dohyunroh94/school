/**************************************************************
 * File:    Starch.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for starch class
 * Contains food name, FOOD_TYPE.
 *
 *************************************************************/

#include "Food.h"
#ifndef STARCH_H_
#define STARCH_H_

using namespace std;

class Starch:public Food{


	public:

		// Constructor
		Starch(string sName, double dCost);

		// printFood
		void printFood(ofstream* file);

};



#endif /* STARCH_H_ */
