/**************************************************************
 * File:    TrafficSim.h
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for TrafficSim object.
 * Simulates a traffic stop
 *
 *************************************************************/
#include <queue>
#include "Vehicle.h"
#include "LinkedList.h"
#include "IntersectionFlowRate.h"

#ifndef TRAFFICSIM_H_
#define TRAFFICSIM_H_

using namespace std;

class TrafficSim{

	public:

		//Constructors
		TrafficSim();
		TrafficSim(char* filename);

		//Destructor
		~TrafficSim();

		//-------------------------------------------------------
		// Name: DoRun
		// PreCondition:  None
		// PostCondition: Simulates and displays a traffic stop for 2 min
		//---------------------------------------------------------
		void DoRun();

		//-------------------------------------------------------
		// Name: DoOneRun
		// PreCondition:  None
		// PostCondition: Performs one iteration of DoRun
		//---------------------------------------------------------

		void DoOneRun();

		//-------------------------------------------------------
		// Name: ReadFromFile
		// PreCondition:  name of input file must be valid
		// PostCondition: Reads in the flow rate values from text file
		// into IntersectionFlowRate object
		//---------------------------------------------------------
		void ReadFromFile(char* inputfile);

		void PrintBoard();

		//-------------------------------------------------------
		// Name: AddVehicle
		// PreCondition:  direction and type must be valid
		// PostCondition: adds a specific vehicle in any direction (queue)
		//---------------------------------------------------------
		void AddVehicle(int direction, int type);

	private:

		LinkedList * result; // List for removed vehicles
		queue <Vehicle*> * m_traffic; // represents North South East West bound cars
		IntersectionFlowRate * m_flowRate; // Flow Rates of vehicles from file
		int m_clock; // Timer

};
#endif
