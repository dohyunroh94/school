/**************************************************************
 * File:    Food.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for food class
 * Contains food name, FOOD_TYPE, and cost of food
 *
 *************************************************************/


#include <string>
#include <fstream>
#ifndef FOOD_H_
#define FOOD_H_

using namespace std;

class Food{

	public:

		// Enum type that represents the 5 types of food
		enum FOOD_TYPE{SWEET, STARCH, MEAT, VEGETABLE, FRUIT};

		// Constructor
		Food(string sName, FOOD_TYPE etype, double dCost);

		// Getters
		FOOD_TYPE getType();

		double getPrice();

		// PrintFood()
		// Precondition: None
		// Postcondition: Prints food name onto a given file
		void printFood(ofstream* file);

	protected:

		// Data members
		string m_sName;
		FOOD_TYPE m_etype;
		double m_dCost;

};
#endif
