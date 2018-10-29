/**************************************************************
 * File:    Starch.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for starch class
 * Contains food name, FOOD_TYPE.
 *
 *************************************************************/


#include "Starch.h"

// Constructor
Starch::Starch(string sName, double dCost):Food(sName, STARCH, dCost){


}

// printFood()
// Writes to a given file the name of
// the food
void Starch::printFood(ofstream* file){

	(*file) << m_sName;

}


