/**************************************************************
 * File:    TrafficSim.cpp
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation for a TrafficSim object.
 * Simulates a traffic stop
 *
 *************************************************************/


#include "TrafficSim.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

// Constructor
TrafficSim::TrafficSim(){

	// Reads default name
	ReadFromFile("input1.txt");

	// Array of queues with vehicle pointers created
	m_traffic = new queue<Vehicle*>[4];
	queue<Vehicle*> add;

	// A copy of the same queue is added for all four directions
	for (int index = 0; index < 4; index++){
		m_traffic[index]= add;
	}

	result = new LinkedList();
	m_clock = 0;


}

// Constructor
TrafficSim::TrafficSim(char* filename){

	// Reads in file (flow rates)
	ReadFromFile(filename);

	// Array of queues with vehicle pointers created
	m_traffic = new queue<Vehicle*>[4];
	queue<Vehicle*> add;

	// A copy of the same queue is added for all four directions
	for (int index = 0; index < 4; index++){
		m_traffic[index]= add;
	}

	result = new LinkedList();
	m_clock = 0;


}

// Destructor
TrafficSim::~TrafficSim(){

	// Uses pointers to store data, then delete
	LinkedList * del1 = result;
	delete del1;
	del1 = NULL;

	IntersectionFlowRate * del2 = m_flowRate;
	delete del2;
	del2 = NULL;


	Vehicle * del3;
	queue <Vehicle*> * del4;

	// Iterates m_traffic array, finding
	// every single queue element, popping
	//, and then deleting them.
	for (int index = 0; index < 4; index++){

		while(!(m_traffic[index].empty())){
			del3 = m_traffic[index].front();
			m_traffic[index].pop();
			delete del3;
			del3 = NULL;
		}

	}

	del4 = m_traffic;
	delete [] del4;
	del4 = NULL;

}

//ReadfromFile
//Reads a text file in and stores the contents
//in IntersectionFlowRate object
void TrafficSim::ReadFromFile(char* inputfile){

	ifstream file;
	string line;
	string Direction;

	int motorCycle = 0;
	int car = 0;
	int truck = 0;
	int index = 0;

	// Arrays to store text file characters
	int motorCycles[4];
	int cars[4];
	int trucks[4];

	// Open file
	file.open(inputfile);


	// Checks every line of file1
	while (getline(file, line)){

		// Used to extract the data
		istringstream sStream(line);

		// Obtains data from file
		sStream >> Direction; // Dummy variable
		sStream >> motorCycle;
		sStream >> car;
		sStream >> truck;

		motorCycles[index] = motorCycle;
		cars[index] = car;
		trucks[index] = truck;


		index++;
	}

	int *m = motorCycles;
	int *c = cars;
	int *t= trucks;

	// Flow rates obtained
	m_flowRate = new IntersectionFlowRate(m, c, t);

}

// PrintBoard
// Prints current traffic
void TrafficSim::PrintBoard(){

	cout << "   SB";

	//Prints x based on how many elements are in the queue

	// For 6 or more elements
	if (m_traffic[1].size() >= 6) {
		cout << " x ";
	} else {
		cout << "   ";
	}

	cout << m_traffic[1].size() << endl;

	// For 5 or more elements
	if (m_traffic[1].size() >= 5) {
		cout << "      x" << endl;
	} else {
		cout << endl;
	}


	// For 4 or more elements
	if (m_traffic[1].size() >= 4) {
		cout << "      x" << endl;
	} else {
		cout << endl;
	}

	// For 3 or more elements
	if (m_traffic[1].size() >= 3) {
		cout << "      x" << endl;
	} else {
		cout << "" << endl;
	}

	cout << "EB    ";

	// For 3 or more elements
	if (m_traffic[1].size() >= 2) {
		cout << "x" << endl;
	} else {
		cout << "" << endl;
	}

	// Checks if EB is 2 digit number (affects spacing)
	if (m_traffic[2].size() < 10){
		cout << m_traffic[2].size() << "     ";
	} else {
		cout << m_traffic[2].size() << "    ";
	}

	// Checks which vehicle is on top for south bound queue
	// prints m, c or t accordingly
	if (!(m_traffic[1].empty())){
		if ((m_traffic[1].front()->getType()) == 1){
			cout << "m" << endl;
		} else if ((m_traffic[1].front()->getType()) == 2){
			cout << "c" << endl;
		} else if ((m_traffic[1].front()->getType()) == 3){
			cout << "t" << endl;
		}

	} else {
		cout << endl;
	}


	//Prints x based on how many elements are in the Eastbound queue
	// For 6 or more elements
	if (m_traffic[2].size() >= 6) {
		cout << "x";
	} else {
		cout << " ";
	}

	if (m_traffic[2].size() >= 5) {
		cout << "x";
	} else {
		cout << " ";
	}

	// For 4 or more elements
	if (m_traffic[2].size() >= 4) {
		cout << "x";
	} else {
		cout << " ";
	}

	// For 3 or more elements
	if (m_traffic[2].size() >= 3) {
		cout << "x";
	} else {
		cout << " ";
	}

	// For 2 or more elements
	if (m_traffic[2].size() >= 2) {
		cout << "x";
	} else {
		cout << " ";
	}


	// Checks which vehicle is on top for east bound queue
	// prints m, c or t accordingly
	if (!(m_traffic[2].empty())){
		if (((m_traffic[2].front()->getType()) == 1)){
			cout << "m";
		} else if ((m_traffic[2].front()->getType()) == 2){
			cout << "c";
		} else if ((m_traffic[2].front()->getType()) == 3){
			cout << "t";
		}

	}else {
		cout << " ";
	}

	// Center of traffic
	cout << " ";

	// Checks which vehicle is on top for west bound queue
	// prints m, c or t accordingly
	if (!(m_traffic[3].empty())){
		if ((m_traffic[3].front()->getType()) == 1 ){
			cout << "m";
		} else if ((m_traffic[3].front()->getType()) == 2){
			cout << "c";
		} else if ((m_traffic[3].front()->getType()) == 3){
			cout << "t";
		}

	} else {
		cout << " ";
	}

	//Prints x based on how many elements are in the west queue
	// For 2 or more elements
	if (m_traffic[3].size() >= 2) {
		cout << "x";
	} else {
		cout << " ";
	}

	// For 3 or more elements
	if (m_traffic[3].size() >= 3) {
		cout << "x";
	} else {
		cout << " ";
	}

	// For 4 or more elements
	if (m_traffic[3].size() >= 4) {
		cout << "x";
	} else {
		cout << " ";
	}

	// For 5 or more elements
	if (m_traffic[3].size() >= 5) {
		cout << "x";
	} else {
		cout << " ";
	}

	// For 6 or more elements
	if (m_traffic[3].size() >= 5) {
		cout << "x" << endl;
	} else {
		cout << " " << endl;
	}

	// Checks which vehicle is on top for north bound queue
	// prints m, c or t accordingly
	if (!(m_traffic[0].empty())){
		if ((m_traffic[0].front()->getType()) == 1 ){
			cout << "      m" << endl;
		} else if ((m_traffic[0].front()->getType()) == 2){
			cout << "      c" << endl;
		} else if ((m_traffic[0].front()->getType()) == 3){
			cout << "      t" << endl;
		}
	} else {
		cout << endl;
	}

	//Prints x based on how many elements are in the Northnbound queue
	// For 2 or more elements
	if (m_traffic[0].size() >= 2) {
		cout << "      x";
	} else {
		cout << "       ";
	}

	cout << "    WB" << endl;

	// For 3 or more elements
	if (m_traffic[0].size() >= 3) {
		cout << "      x";
	} else {
		cout << "       ";
	}

	// Checks if WB is 2 digit number (affects spacing)
	if (m_traffic[3].size() < 10){
		cout << "     " << m_traffic[3].size() << endl;
	} else {
		cout << "    " << m_traffic[3].size() << endl;
	}

	// For 4 or more elements
	if (m_traffic[0].size() >= 4) {
		cout << "      x" << endl;
	} else {
		cout << "       " << endl;
	}

	// For 5 or more elements
	if (m_traffic[0].size() >= 5) {
		cout << "      x" << endl;
	} else {
		cout << "       " << endl;
	}

	cout << "   NB";

	// For 6 or more elements
	if (m_traffic[0].size() >= 6) {
		cout << " x ";
	} else {
		cout << "   ";
	}

	cout << m_traffic[0].size() << endl;

	// Checks how many digits the timer has (for spacing)
	if (m_clock < 10){
		cout << "at clock:   " << m_clock << endl;
	} else if (m_clock < 100){
		cout << "at clock:  " << m_clock << endl;
	} else {
		cout << "at clock: " << m_clock << endl;
	}
	cout << "--------------------------------------" << endl;
	cout << endl;



}

// AddVehicle
// Creates specified type of vehicle object and stores in m_traffic
// of specified direction queue
void TrafficSim::AddVehicle(int direction, int type){

	Vehicle * Addition = new Vehicle(type);

	m_traffic[direction].push(Addition);

}

// DoRun
// Simulates 120 seconds of traffic intersection
void TrafficSim::DoRun(){

	// Adds 2 cars on all directions
	AddVehicle(0 , 2);
	m_traffic[0].back()->setTimeEntered(0);
	AddVehicle(0 , 2);
	m_traffic[0].back()->setTimeEntered(0);

	AddVehicle(1 , 2);
	m_traffic[1].back()->setTimeEntered(0);
	AddVehicle(1 , 2);
	m_traffic[1].back()->setTimeEntered(0);

	AddVehicle(2 , 2);
	m_traffic[2].back()->setTimeEntered(0);
	AddVehicle(2 , 2);
	m_traffic[2].back()->setTimeEntered(0);

	AddVehicle(3 , 2);
	m_traffic[3].back()->setTimeEntered(0);
	AddVehicle(3 , 2);
	m_traffic[3].back()->setTimeEntered(0);

	// True will be green
	// False will be red
	bool northSouthLight = true; // For north/south bound cars
	bool eastWestLight = false; // For east/west bound cars

	// Variables for determining the 30 sec and 10 sec
	// rules (ns and ew are NorthSouth and EastWest)
	bool ns_greenForThirtySec = false;
	bool ew_greenForThirtySec = false;
	bool ew_greenForTenSec = false;

	// Used to determine if light just turned green
	bool ns_justTurnedGreen = false;
	bool ew_justTurnedGreen = false;


	// Wait time for front elements of queues
	// (1 for North, 2 for South, 3 for East, 4 for West)
	int timeAtFront1 = 0;
	int timeAtFront2 = 0;
	int timeAtFront3 = 0;
	int timeAtFront4 = 0;

	// Used for timing how long light was green
	int lightCounter = 0;

	// FlowRates for vehicles
	// Northbound
	int nMotor = 60/((m_flowRate->getFlowRateMotorCycle())[0]);
	int nCar =  60/((m_flowRate->getFlowRateCar())[0]);
	int nTruck = 60/((m_flowRate->getFlowRateTruck())[0]);

	// Southbound
	int sMotor = 60/((m_flowRate->getFlowRateMotorCycle())[1]);
	int sCar = 60/((m_flowRate->getFlowRateCar())[1]);
	int sTruck = 60/((m_flowRate->getFlowRateTruck())[1]);

	// Eastbound
	int eMotor = 60/((m_flowRate->getFlowRateMotorCycle())[2]);
	int eCar = 60/((m_flowRate->getFlowRateCar())[2]);
	int eTruck = 60/((m_flowRate->getFlowRateTruck())[2]);

	// Westbound
	int wMotor = 60/((m_flowRate->getFlowRateMotorCycle())[3]);
	int wCar = 60/((m_flowRate->getFlowRateCar())[3]);
	int wTruck = 60/((m_flowRate->getFlowRateTruck())[3]);

	// For loop that represents all 120 seconds of simulation
	for (m_clock = 0; m_clock <= 120; m_clock++){

		// First, determines whether lights need to change

		// Counts how long the light was on (for any direction)
		// Must be past first iteration
		if (m_clock > 0){
			lightCounter++;
		}

		// If green for north and south lights
		if (northSouthLight){

			// Past first iteration
			if (m_clock > 0){

				// Checks if the north and south queues
				// have a vehicle waiting in the front
				// if so, increments waiting time
				if (!(m_traffic[0].empty())){
					timeAtFront1++;
				}
				if (!(m_traffic[1].empty())){
					timeAtFront2++;
				}

			}

			// If light has been green for thirty seconds
			if (lightCounter > 30){
				ns_greenForThirtySec = true;
			}

			// If light has been thirty second either east or west queues aren't empty
			if (ns_greenForThirtySec && ((!(m_traffic[2].empty())) || (!(m_traffic[3].empty())))){

				// Sets the east and west light to green and
				// sets the north and south light to red
				northSouthLight = false;
				eastWestLight = true;

				// Resets justturnedGreen and greenForThirtySec
				ew_justTurnedGreen = true;
				ns_greenForThirtySec = false;

			}

			// If the light just switched
			if(ew_justTurnedGreen){

				// Automatically resets justTurnedGreen, greenForThirtySec
				// and greenForTensec
				ew_justTurnedGreen = false;
				ew_greenForThirtySec = false;
				ew_greenForTenSec = false;

				// Resets queue waiting times
				timeAtFront1 = 0;
				timeAtFront2 = 0;
				timeAtFront3 = 0;
				timeAtFront4 = 0;

				// Automatically increments wait time
				// right after light changes (if there is traffic)
				if (!(m_traffic[2].empty())){
					timeAtFront3++;
				}

				if (!(m_traffic[3].empty())){
					timeAtFront4++;
				}


				// Resets the light time
				lightCounter = 0;

			}

		}

		// If eastWest light is green
		else if (eastWestLight){

			if (m_clock > 0){

				// Checks if east and west queues have a vehicle waiting
				// increments time if so
				if (!(m_traffic[2].empty())){
					timeAtFront3++;
				}
				if (!(m_traffic[3].empty())){
					timeAtFront4++;
				}

			}

			// Checks if light was green for ten seconds
			if (lightCounter > 10){
				ew_greenForTenSec = true;
			}

			// If light was green for 10 seconds and both
			// east and west have no cars
			if (ew_greenForTenSec && ((m_traffic[2].empty()) && ((m_traffic[3].empty())))){

				// EastWest turns red
				// NorthSouth turns green
				eastWestLight = false;
				northSouthLight = true;

				// North south light just turned green
				ns_justTurnedGreen = true;

				// Resets eastWest values
				ew_greenForTenSec = false;
				ew_greenForThirtySec = false;


			}

			// Checks if eastWest light has been green for 30 sec
			if (lightCounter > 30){

				ew_greenForThirtySec = true;

			}

			// If eastWest light has been green for 30 sec
			if (ew_greenForThirtySec){

				// NorthSouth turns green
				// EastWest turns red
				eastWestLight = false;
				northSouthLight = true;

				// NorthSouth just turned green
				ns_justTurnedGreen = true;

				// EastWest values reset
				ew_greenForTenSec = false;
				ew_greenForThirtySec = false;


			}

			// If northSouth just turned green
			if (ns_justTurnedGreen){

				// Automatically resets northSouth values
				ns_justTurnedGreen = false;
				ns_greenForThirtySec = false;

				// Resets queue waiting times
				timeAtFront1 = 0;
				timeAtFront2 = 0;
				timeAtFront3 = 0;
				timeAtFront4 = 0;

				// Automatically increments wait time
				// right after light changes (if there is traffic)
				if (!(m_traffic[0].empty())){
					timeAtFront1++;
				}

				if (!(m_traffic[1].empty())){
					timeAtFront2++;
				}


				// Light time is set to 0
				lightCounter = 0;

			}

		}

		// Second, checks wait times to remove vehicles from queues of directions

		// For northSouth queues (when green)
		if (northSouthLight){

			// Determines whether to remove the north bound cars
			if (!(m_traffic[0].empty())){

				// Checks if the time waited match clear times
				// adds the vehicle to result and then removes from queue
				// resets waiting time
				if ( timeAtFront1 == (m_traffic[0].front()->getClearTime()) ){

					result->add((m_traffic[0].front()->getType()),
							(m_traffic[0].front()->getTimeEntered()),
							m_clock,(m_traffic[0].front()->getClearTime()));

					m_traffic[0].pop();
					timeAtFront1 =  0;

				}

			}

			// Determines whether to remove the south bound cars
			if (!(m_traffic[1].empty())){

				// Checks if the time waited match clear times
				// adds the vehicle to result and then removes from queue
				// resets waiting time
				if (timeAtFront2 == (m_traffic[1].front()->getClearTime()) ){

					result->add((m_traffic[1].front()->getType()),
						(m_traffic[1].front()->getTimeEntered()),
						m_clock,(m_traffic[1].front()->getClearTime()));

					m_traffic[1].pop();
					timeAtFront2 = 0;

				}

			}
		}

		// For eastWest queues (when green)
		if (eastWestLight){

			// Determines whether to remove the east bound cars
			if (!(m_traffic[2].empty())){

				// Checks if the time waited match clear times
				// adds the vehicle to result and then removes from queue
				// resets waiting time
				if ( timeAtFront3 == (m_traffic[2].front()->getClearTime())){

					result->add((m_traffic[2].front()->getType()),
							(m_traffic[2].front()->getTimeEntered()),
							m_clock,(m_traffic[2].front()->getClearTime()));

					m_traffic[2].pop();
					timeAtFront3 = 0;

				}


			}


			// Determines whether to remove the westbound cars
			if (!(m_traffic[3].empty())){

				// Checks if the time waited match clear times
				// adds the vehicle to result and then removes from queue
				// resets waiting time
				if (timeAtFront4 == (m_traffic[3].front()->getClearTime())){

					result->add((m_traffic[3].front()->getType()),
					(m_traffic[3].front()->getTimeEntered()),
					m_clock,(m_traffic[3].front()->getClearTime()));

					m_traffic[3].pop();
					timeAtFront4 = 0;

				}

			}
		}

		// Lastly, adds vehicles based on flow rate values
		// Checks if the current time is divisible by
		// the flowRate value (which is 60 divided by actual rate from
		// textfile) will add if sufficient time has passed


		// for Motorcycles
		if((m_clock != 0) && (((m_clock) % nMotor) == 0)){
			AddVehicle(0, 1);
			m_traffic[0].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % sMotor) == 0)){
			AddVehicle(1, 1);
			m_traffic[1].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % eMotor) == 0)){
			AddVehicle(2, 1);
			m_traffic[2].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % wMotor) == 0)){
			AddVehicle(3, 1);
			m_traffic[3].back()->setTimeEntered(m_clock);
		}


		// For cars
		if((m_clock != 0) && (((m_clock) % nCar) == 0)){
			AddVehicle(0, 2);
			m_traffic[0].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % sCar) == 0)){
			AddVehicle(1, 2);
			m_traffic[1].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % eCar) == 0)){
			AddVehicle(2, 2);
			m_traffic[2].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % wCar) == 0)){
			AddVehicle(3, 2);
			m_traffic[3].back()->setTimeEntered(m_clock);
		}


		// For trucks
		if((m_clock != 0) && (((m_clock) % nTruck) == 0)){
			AddVehicle(0, 3);
			m_traffic[0].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % sTruck) == 0)){
			AddVehicle(1, 3);
			m_traffic[1].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % eTruck) == 0)){
			AddVehicle(2, 3);
			m_traffic[2].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % wTruck) == 0)){
			AddVehicle(3, 3);
			m_traffic[3].back()->setTimeEntered(m_clock);
		}


		// Prints current state
		PrintBoard();


}

	// At the end of the loop
	// Displays number of vehicles, motorcycles, cars, and
	// trucks that passed through intersection
	// Also displays average wait time
	cout << "The final results are: " << endl;
	cout << "The number of vehicles that passed "
			"through the intersection is: " << result->NumOfVehicles() << endl;
	cout << "The number of motorcycles that passed through the intersection "
			"is: " << result->NumOfSpecificVehicle(1) << endl;
	cout << "The number of cars that passed through the intersection is: "
			<< result->NumOfSpecificVehicle(2) << endl;
	cout << "The number of trucks that passed through the intersection is: "
			<< result->NumOfSpecificVehicle(3) << endl;
	cout << "The average wait time for this intersection is: " <<
			result->AverageWaitTime() << endl;

}

// DoOneRun
// Same as DoRun except iterates just one time
void TrafficSim::DoOneRun(){

	// Adds 2 cars on all directions
	AddVehicle(0 , 2);
	m_traffic[0].back()->setTimeEntered(0);
	AddVehicle(0 , 2);
	m_traffic[0].back()->setTimeEntered(0);

	AddVehicle(1 , 2);
	m_traffic[1].back()->setTimeEntered(0);
	AddVehicle(1 , 2);
	m_traffic[1].back()->setTimeEntered(0);

	AddVehicle(2 , 2);
	m_traffic[2].back()->setTimeEntered(0);
	AddVehicle(2 , 2);
	m_traffic[2].back()->setTimeEntered(0);

	AddVehicle(3 , 2);
	m_traffic[3].back()->setTimeEntered(0);
	AddVehicle(3 , 2);
	m_traffic[3].back()->setTimeEntered(0);

	// True will be green
	// False will be red
	bool northSouthLight = true; // For north/south bound cars
	bool eastWestLight = false; // For east/west bound cars

	// Variables for determining the 30 sec and 10 sec
	// rules (ns and ew are NorthSouth and EastWest)
	bool ns_greenForThirtySec = false;
	bool ew_greenForThirtySec = false;
	bool ew_greenForTenSec = false;

	// Used to determine if light just turned green
	bool ns_justTurnedGreen = false;
	bool ew_justTurnedGreen = false;


	// Wait time for front elements of queues
	// (1 for North, 2 for South, 3 for East, 4 for West)
	int timeAtFront1 = 0;
	int timeAtFront2 = 0;
	int timeAtFront3 = 0;
	int timeAtFront4 = 0;

	// Used for timing how long light was green
	int lightCounter = 0;

	// FlowRates for vehicles
	// Northbound
	int nMotor = 60/((m_flowRate->getFlowRateMotorCycle())[0]);
	int nCar =  60/((m_flowRate->getFlowRateCar())[0]);
	int nTruck = 60/((m_flowRate->getFlowRateTruck())[0]);

	// Southbound
	int sMotor = 60/((m_flowRate->getFlowRateMotorCycle())[1]);
	int sCar = 60/((m_flowRate->getFlowRateCar())[1]);
	int sTruck = 60/((m_flowRate->getFlowRateTruck())[1]);

	// Eastbound
	int eMotor = 60/((m_flowRate->getFlowRateMotorCycle())[2]);
	int eCar = 60/((m_flowRate->getFlowRateCar())[2]);
	int eTruck = 60/((m_flowRate->getFlowRateTruck())[2]);

	// Westbound
	int wMotor = 60/((m_flowRate->getFlowRateMotorCycle())[3]);
	int wCar = 60/((m_flowRate->getFlowRateCar())[3]);
	int wTruck = 60/((m_flowRate->getFlowRateTruck())[3]);

	// For loop that iterates once
	for (m_clock = 0; m_clock < 1; m_clock++){

		// First, determines whether lights need to change

		// Counts how long the light was on (for any direction)
		// Must be past first iteration
		if (m_clock > 0){
			lightCounter++;
		}

		// If green for north and south lights
		if (northSouthLight){

			// Past first iteration
			if (m_clock > 0){

				// Checks if the north and south queues
				// have a vehicle waiting in the front
				// if so, increments waiting time
				if (!(m_traffic[0].empty())){
					timeAtFront1++;
				}
				if (!(m_traffic[1].empty())){
					timeAtFront2++;
				}

			}

			// If light has been green for thirty seconds
			if (lightCounter > 30){
				ns_greenForThirtySec = true;
			}

			// If light has been thirty second either east or west queues aren't empty
			if (ns_greenForThirtySec && ((!(m_traffic[2].empty())) || (!(m_traffic[3].empty())))){

				// Sets the east and west light to green and
				// sets the north and south light to red
				northSouthLight = false;
				eastWestLight = true;

				// Resets justturnedGreen and greenForThirtySec
				ew_justTurnedGreen = true;
				ns_greenForThirtySec = false;

			}

			// If the light just switched
			if(ew_justTurnedGreen){

				// Automatically resets justTurnedGreen, greenForThirtySec
				// and greenForTensec
				ew_justTurnedGreen = false;
				ew_greenForThirtySec = false;
				ew_greenForTenSec = false;

				// Resets queue waiting times
				timeAtFront1 = 0;
				timeAtFront2 = 0;
				timeAtFront3 = 0;
				timeAtFront4 = 0;

				// Automatically increments wait time
				// right after light changes (if there is traffic)
				if (!(m_traffic[2].empty())){
					timeAtFront3++;
				}

				if (!(m_traffic[3].empty())){
					timeAtFront4++;
				}


				// Resets the light time
				lightCounter = 0;




			}

		}

		// If eastWest light is green
		else if (eastWestLight){

			if (m_clock > 0){

				// Checks if east and west queues have a vehicle waiting
				// increments time if so
				if (!(m_traffic[2].empty())){
					timeAtFront3++;
				}
				if (!(m_traffic[3].empty())){
					timeAtFront4++;
				}

			}

			// Checks if light was green for ten seconds
			if (lightCounter > 10){
				ew_greenForTenSec = true;
			}

			// If light was green for 10 seconds and both
			// east and west have no cars
			if (ew_greenForTenSec && ((m_traffic[2].empty()) && ((m_traffic[3].empty())))){

				// EastWest turns red
				// NorthSouth turns green
				eastWestLight = false;
				northSouthLight = true;

				// North south light just turned green
				ns_justTurnedGreen = true;

				// Resets eastWest values
				ew_greenForTenSec = false;
				ew_greenForThirtySec = false;


			}

			// Checks if eastWest light has been green for 30 sec
			if (lightCounter > 30){

				ew_greenForThirtySec = true;

			}

			// If eastWest light has been green for 30 sec
			if (ew_greenForThirtySec){

				// NorthSouth turns green
				// EastWest turns red
				eastWestLight = false;
				northSouthLight = true;

				// NorthSouth just turned green
				ns_justTurnedGreen = true;

				// EastWest values reset
				ew_greenForTenSec = false;
				ew_greenForThirtySec = false;


			}

			// If northSouth just turned green
			if (ns_justTurnedGreen){

				// Automatically resets northSouth values
				ns_justTurnedGreen = false;
				ns_greenForThirtySec = false;

				// Resets queue waiting times
				timeAtFront1 = 0;
				timeAtFront2 = 0;
				timeAtFront3 = 0;
				timeAtFront4 = 0;

				// Automatically increments wait time
				// right after light changes (if there is traffic)
				if (!(m_traffic[0].empty())){
					timeAtFront1++;
				}

				if (!(m_traffic[1].empty())){
					timeAtFront2++;
				}


				// Light time is set to 0
				lightCounter = 0;



			}

		}

		// Second, checks wait times to remove vehicles from queues of directions

		// For northSouth queues (when green)
		if (northSouthLight){

			// Determines whether to remove the north bound cars
			if (!(m_traffic[0].empty())){

				// Checks if the time waited match clear times
				// adds the vehicle to result and then removes from queue
				// resets waiting time
				if ( timeAtFront1 == (m_traffic[0].front()->getClearTime()) ){

					result->add((m_traffic[0].front()->getType()),
							(m_traffic[0].front()->getTimeEntered()),
							m_clock,(m_traffic[0].front()->getClearTime()));

					m_traffic[0].pop();
					timeAtFront1 =  0;

				}

			}

			// Determines whether to remove the south bound cars
			if (!(m_traffic[1].empty())){

				// Checks if the time waited match clear times
				// adds the vehicle to result and then removes from queue
				// resets waiting time
				if (timeAtFront2 == (m_traffic[1].front()->getClearTime()) ){

					result->add((m_traffic[1].front()->getType()),
						(m_traffic[1].front()->getTimeEntered()),
						m_clock,(m_traffic[1].front()->getClearTime()));

					m_traffic[1].pop();
					timeAtFront2 = 0;

				}

			}
		}

		// For eastWest queues (when green)
		if (eastWestLight){

			// Determines whether to remove the east bound cars
			if (!(m_traffic[2].empty())){

				// Checks if the time waited match clear times
				// adds the vehicle to result and then removes from queue
				// resets waiting time
				if ( timeAtFront3 == (m_traffic[2].front()->getClearTime())){

					result->add((m_traffic[2].front()->getType()),
							(m_traffic[2].front()->getTimeEntered()),
							m_clock,(m_traffic[2].front()->getClearTime()));

					m_traffic[2].pop();
					timeAtFront3 = 0;

				}


			}


			// Determines whether to remove the westbound cars
			if (!(m_traffic[3].empty())){

				// Checks if the time waited match clear times
				// adds the vehicle to result and then removes from queue
				// resets waiting time
				if (timeAtFront4 == (m_traffic[3].front()->getClearTime())){

					result->add((m_traffic[3].front()->getType()),
					(m_traffic[3].front()->getTimeEntered()),
					m_clock,(m_traffic[3].front()->getClearTime()));

					m_traffic[3].pop();
					timeAtFront4 = 0;

				}

			}
		}

		// Lastly, adds vehicles based on flow rate values
		// Checks if the current time is divisible by
		// the flowRate value (which is 60 divided by actual rate from
		// textfile) will add if sufficient time has passed


		// for Motorcycles
		if((m_clock != 0) && (((m_clock) % nMotor) == 0)){
			AddVehicle(0, 1);
			m_traffic[0].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % sMotor) == 0)){
			AddVehicle(1, 1);
			m_traffic[1].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % eMotor) == 0)){
			AddVehicle(2, 1);
			m_traffic[2].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % wMotor) == 0)){
			AddVehicle(3, 1);
			m_traffic[3].back()->setTimeEntered(m_clock);
		}


		// For cars
		if((m_clock != 0) && (((m_clock) % nCar) == 0)){
			AddVehicle(0, 2);
			m_traffic[0].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % sCar) == 0)){
			AddVehicle(1, 2);
			m_traffic[1].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % eCar) == 0)){
			AddVehicle(2, 2);
			m_traffic[2].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % wCar) == 0)){
			AddVehicle(3, 2);
			m_traffic[3].back()->setTimeEntered(m_clock);
		}


		// For trucks
		if((m_clock != 0) && (((m_clock) % nTruck) == 0)){
			AddVehicle(0, 3);
			m_traffic[0].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % sTruck) == 0)){
			AddVehicle(1, 3);
			m_traffic[1].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % eTruck) == 0)){
			AddVehicle(2, 3);
			m_traffic[2].back()->setTimeEntered(m_clock);
		}

		if((m_clock != 0) && (((m_clock) % wTruck) == 0)){
			AddVehicle(3, 3);
			m_traffic[3].back()->setTimeEntered(m_clock);
		}


		// Prints current state
		PrintBoard();


}

	// At the end of the loop
	// Displays number of vehicles, motorcycles, cars, and
	// trucks that passed through intersection
	// Also displays average wait time
	cout << "The final results are: " << endl;
	cout << "The number of vehicles that passed "
			"through the intersection is: " << result->NumOfVehicles() << endl;
	cout << "The number of motorcycles that passed through the intersection "
			"is: " << result->NumOfSpecificVehicle(1) << endl;
	cout << "The number of cars that passed through the intersection is: "
			<< result->NumOfSpecificVehicle(2) << endl;
	cout << "The number of trucks that passed through the intersection is: "
			<< result->NumOfSpecificVehicle(3) << endl;
	cout << "The average wait time for this intersection is: " <<
			result->AverageWaitTime() << endl;

}
