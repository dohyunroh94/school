/**************************************************************
 * File:    Node.h
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation of Node
 *
 *
 *************************************************************/

#include "Node.h"
#include <iomanip>

using namespace std;

Node::Node(){

	// empty
	n_type = 0;
	n_timeEntered = 0;
	n_timeLeft = 0;
	n_clearTime = 0;
	link = NULL;

}


