/**************************************************************
 * File:    LinkedList.cpp
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation for custom linked list
 * made for storing vehicle nodes
 *
 *************************************************************/
#include <iostream>

using namespace std;

#include "LinkedList.h"

// Constructor
LinkedList::LinkedList()
{
	FRONT = NULL;
	REAR = NULL;
	PREVIOUS = NULL;
	CURSOR = NULL;
	INSERT = NULL;

}

// Destructor
LinkedList::~LinkedList()
{

	// Goes through the list until the end
	// (would point to null) and deletes
	// all nodes
	while(FRONT!= NULL){

	  CURSOR = FRONT;
      FRONT = FRONT -> link;
	  delete CURSOR;

  }

  CURSOR = NULL;

}

//add
//Receives information of a vehicle object and
//stores that in a new node, which is added to
//the list
void LinkedList::add(int type, int timeEntered, int timeLeft, int clearTime)
{

	INSERT = new Node();

	// Sets all the info accordingly
	INSERT -> n_type =  type;
	INSERT -> n_timeEntered = timeEntered;
	INSERT -> n_timeLeft =  timeLeft;
	INSERT -> n_clearTime = clearTime;
	INSERT -> link = NULL;

	// If it is the first item
	if(IsEmpty()){

		FRONT = INSERT;

	// If last added item
	// will "link" it to PREVIOUS
	}else{

		REAR -> link = INSERT;

	}

	// the latest item becomes REAR
	REAR = INSERT;
}

//NumOfSpecificVehicle
// Finds the total number of specified vehicle
int LinkedList::NumOfSpecificVehicle(int vType){

	int numOfSpecificVehicle = 0;

	// Starts at the beginning
	if (CURSOR == NULL){
		CURSOR = FRONT;
	}

	// If vehicle type matches
	// with current node
	if ((CURSOR->n_type) == vType){
		numOfSpecificVehicle++;
	}

	// Moves on to next node
	CURSOR = CURSOR->link;

	// Will recursively call until the end of list
	if ((CURSOR->link) != NULL){
		numOfSpecificVehicle += (this->NumOfSpecificVehicle(vType));
	}

	CURSOR = NULL;
	return numOfSpecificVehicle;

}

// NumOfVehicles
// Finds the total number of vehicles in list
int LinkedList::NumOfVehicles(){

	int numOfVehicles = 0;

	// Starts from first item
	if (CURSOR == NULL){
		CURSOR = FRONT;
	}

	// Default increment
	numOfVehicles++;

	// Moves to next item
	CURSOR = CURSOR->link;

	// Recursively calls until the end
	if ((CURSOR->link) != NULL){
		numOfVehicles += (this->NumOfVehicles());
	}

	CURSOR = NULL;
	return numOfVehicles;

}

int LinkedList::TotalWaitTime(){

	int time = 0;
	if (CURSOR == NULL){
		CURSOR = FRONT;
	}

	time += ((CURSOR->n_timeLeft) - (CURSOR->n_timeEntered));

	CURSOR = CURSOR->link;

	if ((CURSOR->link) != NULL){
		time += (this->TotalWaitTime());
	}

	CURSOR = NULL;
	return time;
}

float LinkedList::AverageWaitTime(){

	return ((float)(this->TotalWaitTime()))/((float)(this->NumOfVehicles()));

}

bool LinkedList::IsEmpty()
{
	if ((FRONT == NULL) && (REAR == NULL)){
		return true;
	}

	return false;
}
