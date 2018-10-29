/**************************************************************
 * File:    Sweet.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for Sweet class
 * Contains food name, FOOD_TYPE.
 *
 *************************************************************/


#include "Sweet.h"

// Constructor
Sweet::Sweet(string sName, double dCost):Food(sName, SWEET, dCost){


}

// printFood()
// Writes to a given file the name of
// the food
void Sweet::printFood(ofstream* file){

	(*file) << m_sName;

}




