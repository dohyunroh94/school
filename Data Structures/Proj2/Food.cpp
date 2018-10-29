/**************************************************************
 * File:    Food.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for food class
 * Contains food name, FOOD_TYPE, and cost of food
 *
 *************************************************************/


#include <iostream>
#include <fstream>
#include "Food.h";
using namespace std;

// Constructor
// Initializes the data members
Food::Food(string sName, FOOD_TYPE etype, double dCost){

	m_sName = sName;
	m_etype = etype;
	m_dCost = dCost;

}

// Getters
Food::FOOD_TYPE Food::getType(){

	return m_etype;
}

double Food::getPrice(){

	return m_dCost;

}



// printFood()
// Writes to a given file the name of
// the food
void Food::printFood(ofstream* file){

	(*file) << m_sName;

}


