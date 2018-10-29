/**************************************************************
 * File:    Vehicle.cpp
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for Vehicle object.
 * Represents a vehicle motorcycle, car, or truck
 * depending on type value
 *************************************************************/
#include <iostream>
#include "Clear.h"
#include "Vehicle.h"

using namespace std;

	Vehicle::Vehicle(int type){

		// Motorcycle, Car, Truck (1, 2, 3)
		m_type = type;

		// Depending on type
		// will be assigned proper
		// clear time (obtained from "Clear.h")
		if (type == 1){

			m_clearTime = Motor;

		}
		else if(type == 2){

			m_clearTime = Car;

		}

		else if(type == 3){

			m_clearTime = Truck;

		// Should never happen
		} else {

			m_clearTime = 0;
		}

		m_timeEntered = 0;


	}

	//Setter
	void Vehicle::setType(int carType){

		m_type = carType;

	//Setter
	}
	void Vehicle::setTimeEntered(int carTimeEntered){

		m_timeEntered = carTimeEntered;

	}

	//Setter
	void Vehicle::setClearTime(int clearTime){

		m_clearTime = clearTime;

	}

	//Getter
	int Vehicle::getType(){

		return m_type;

	}

	//Getter
	int Vehicle::getTimeEntered(){

		return m_timeEntered;

	}

	//Getter
	int Vehicle::getClearTime(){

		return m_clearTime;

	}


