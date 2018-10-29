/**************************************************************
 * File:    InterSectionFlowRate.cpp
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation for the InterSectionFlowRate object
 *
 *************************************************************/

#include "IntersectionFlowRate.h"

using namespace std;


// Constructor
// Accepts 3 arrays as the flow rate sets
IntersectionFlowRate::IntersectionFlowRate(int FlowRateMotorCycle[],
		int FlowRateCar[], int FlowRateTruck[]){

	// Uses for loops to store the values manually from given arrays
	for (int index1 = 0; index1 < 4; index1++){

		m_FlowRateMotorCycle[index1] = FlowRateMotorCycle[index1];

	}

	for (int index2 = 0; index2 < 4; index2++){

		m_FlowRateCar[index2] = FlowRateCar[index2];

	}

	for (int index3 = 0; index3 < 4; index3++){

		m_FlowRateTruck[index3] = FlowRateTruck[index3];

	}



}

//Setter
void IntersectionFlowRate::setFlowRateMotorCycle(int motorFlow[]){

	//Uses for loop to set values from parameter array to the
	//data member array
	for (int index = 0; index < 4; index++){

		m_FlowRateMotorCycle[index] = motorFlow[index];

	}

}

//Setter
void IntersectionFlowRate::setFlowRateCar(int carFlow[]){

	//Uses for loop to set values from parameter array to the
	//data member array
	for (int index = 0; index < 4; index++){

		m_FlowRateCar[index] = carFlow[index];

	}

}

//Setter
void IntersectionFlowRate::setFlowRateTruck(int truckFlow[]){

	//Uses for loop to set values from parameter array to the
	//data member array
	for (int index = 0; index < 4; index++){

		m_FlowRateTruck[index] = truckFlow[index];

	}

}

//Getter
int* IntersectionFlowRate::getFlowRateMotorCycle(){

	//Returns a pointer that points to the array
	int * motorFlow;
	motorFlow = m_FlowRateMotorCycle;
	return motorFlow;

}

//Getter
int* IntersectionFlowRate::getFlowRateCar(){

	//Returns a pointer that points to the array
	int * carFlow;
	carFlow = m_FlowRateCar;
	return carFlow;

}

//Getter
int* IntersectionFlowRate::getFlowRateTruck(){

	//Returns a pointer that points to the array
	int * truckFlow;
	truckFlow = m_FlowRateTruck;
	return truckFlow;

}




