/**************************************************************
 * File:    Vegetable.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for Vegetable class
 * Contains food name, FOOD_TYPE.
 *
 *************************************************************/


#include "Vegetable.h"

// Constructor
Vegetable::Vegetable(string sName, double dCost):Food(sName, VEGETABLE, dCost){


}

// printFood()
// Writes to a given file the name of
// the food
void Vegetable::printFood(ofstream* file){

	(*file) << m_sName;

}


