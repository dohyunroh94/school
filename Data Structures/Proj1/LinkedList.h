/**************************************************************
 * File:    LinkedList.h
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for custom linked list
 * made for storing vehicle nodes
 *
 *************************************************************/

#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
public:

	//Constructor
	LinkedList();

	//Destructor
	~LinkedList();

	//-------------------------------------------------------
	// Name: add
	// PreCondition:  None
	// PostCondition: Adds a new vehicle node with information to the linked list
	//---------------------------------------------------------
	void add(int type, int timeEntered, int timeLeft, int clearTime);

	//-------------------------------------------------------
	// Name: NumberOfSpecificVehicle
	// PreCondition:  Vehicle type must be valid
	// PostCondition: returns the number of specified vehicles in list
	//---------------------------------------------------------
	int NumOfSpecificVehicle(int vType);

	//-------------------------------------------------------
	// Name: NumOfVehicles
	// PreCondition:  None
	// PostCondition: returns the number of total vehicles in list
	//---------------------------------------------------------
	int NumOfVehicles();

	//-------------------------------------------------------
	// Name: TotalWaitTime
	// PreCondition:  None
	// PostCondition: Calculates total wait time of all vehicles that were
	// in a queue
	//---------------------------------------------------------
	int TotalWaitTime();

	//-------------------------------------------------------
	// Name: AverageWaitTime
	// PreCondition:  None
	// PostCondition: Calculates the average wait time of a vehicle
	// in a queue
	//---------------------------------------------------------
	float AverageWaitTime();

	//-------------------------------------------------------
	// Name: IsEmpty
	// PreCondition:  None
	// PostCondition: Checks whether the list is empty or not
	//---------------------------------------------------------
	bool IsEmpty();

private:

	Node *FRONT;
	Node *REAR;
	Node *CURSOR;
	Node *INSERT;
	Node *PREVIOUS;

};
#endif
