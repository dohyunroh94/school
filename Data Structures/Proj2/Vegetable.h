/**************************************************************
 * File:    Vegetable.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for vegetable class
 * Contains food name, FOOD_TYPE.
 *
 *************************************************************/
#include "Food.h"
#ifndef VEGETABLE_H_
#define VEGETABLE_H_


using namespace std;

class Vegetable:public Food{

	public:

		// Constructor
		Vegetable(string sName, double dCost);

		// printFood()
		void printFood(ofstream* file);

};



#endif /* VEGETABLE_H_ */
