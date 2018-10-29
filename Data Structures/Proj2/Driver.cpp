/**************************************************************
 * File:    Driver.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Driver file that creates a manager instance
 * stocks a store, fill orders, and write the results to text file
 *************************************************************/

#include "Manager.h";


// printGreeting
// Writes my name and section to file
void printGreeting(ofstream* file){

	(*file) << "Dohyun Roh, Section 1\n";

}

int main(int argc, char *argv[]){

	// Creates manager and file writer
	Manager * mgr = new Manager();
	ofstream file;

	// Checks if file name was inputted
	// (command line variables)
	if (argc > 1){

		file.open("result.txt");

		printGreeting(&file);
		mgr->createStore(argv[1]);
		mgr->createOrders(argv[2]);


		mgr->printStatus(&file);
		mgr->fillOrders(&file);
		mgr->printStatus(&file);

		delete mgr;

	// For the case the no
	// input files were specified
	} else {

		file.open("result.txt");
		printGreeting(&file);

	}

	file.close();
	return 0;
}


