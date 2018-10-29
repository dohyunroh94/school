/**************************************************************
 * File:    InterSectionFlowRate.h
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for IntersectionFlowRate
 * Used as an object to store the vehicle
 * flow rates obtained from text file
 *
 *************************************************************/

#ifndef INTERSECTIONFLOWRATE_H_
#define INTERSECTIONFLOWRATE_H_

class IntersectionFlowRate{

	public:

		// Constructor
		IntersectionFlowRate(int FlowRateMotorCycle[],
				int FlowRateCar[], int FlowRateTruck[]);

		// Setters for flowRates
		void setFlowRateMotorCycle(int motorFlow[]);
		void setFlowRateCar(int carFlow[]);
		void setFlowRateTruck(int truckFlow[]);

		// Getters for flowRates
		int* getFlowRateMotorCycle();
		int* getFlowRateCar();
		int* getFlowRateTruck();



	private:

		// Data members to store the flow rates
		int m_FlowRateMotorCycle[4];
		int m_FlowRateCar[4];
		int m_FlowRateTruck[4];


};
#endif
/* INTERSECTIONFLOWRATE_H_ */
