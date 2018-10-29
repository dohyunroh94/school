/**************************************************************
 * File:    Vehicle.h
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for Vehicle object.
 * Represents a vehicle motorcycle, car, or truck
 * depending on type value
 *************************************************************/


#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle{

	public:

		// Note: 1 is motorcycle
		//		 2 is car
		//		 3 is truck
		Vehicle(int type);

		// Setters
		void setType(int carType);
		void setTimeEntered(int carTimeEntered);
		void setClearTime(int clearTime);

		// Getters
		int getType();
		int getTimeEntered();
		int getClearTime();



	private:

		int m_type;
		int m_timeEntered; // Time vehicle entered a queue
		int m_clearTime;

};
#endif
