/**************************************************************
 * File:    Manager.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for Manager class
 * Represents a manager with a store and orders
 *************************************************************/

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Store.h"
#include "Orders.h"

class Manager{


	public:

		// Constructor
		Manager();

		// Destructor
		~Manager();

		// createStore()
		// preconditions: none
		// postconditions: will store the
		// food names and types in m_store
		// from a text file
		void createStore(string filename);

		// createOrders()
		// preconditions: none
		// postconditions: will store
		// orders information from
		// text file to m_orders
		void createOrders(string filename);

		// fillOrders()
		// preconditions: m_store and m_orders
		// must not be empty
		// postcondition: will
		// fill the orders of customers
		// and remove items from store
		void fillOrders(ofstream*);

		// printStatus()
		// precondition: none
		// postcondition: prints store
		// and orders to text file
		void printStatus(ofstream*);

	private:

		Store * m_store;
		Orders * m_orders;

};
#endif /* MANAGER_H_ */
