/**************************************************************
 * File:    Orders.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for Orders class
 * Represents orders with unfilled and completed orders
 *************************************************************/

#include "Order.h";
#include "Food.h"
#include <string>
#include <fstream>

#ifndef ORDERS_H_
#define ORDERS_H_



class Orders{

	public:

		// Destructor
		~Orders();

		// Getters
		int getSizeOfOrdersUnfilled();
		int getSizeOfOrdersCompleted();

		// addOrder
		// precondition: none
		// postcondition: adds an order to
		// unfilled orders queue
		void addOrder(Order*);

		// removeOrder
		// precondition: none
		// postcondition: removes an order
		// from unfilled orders queue
		void removeOrder();

		// completeOrder
		// precondition: unfilled orders must not be empty
		// postcondition: sets current order
		// in unfilled orders as complete
		// and adds that order to completed orders
		void completeOrder();

		// getCurrentOrder
		// precondition: none
		// postcondition: returns the current order
		// in unfilled orders
		Order* getCurrentOrder();

		// loadOrders
		// precondition: none
		// postcondition: loads orders
		// from text file
		void loadOrders(string filename);

		// printOrders
		// precondition: unfilled orders must not be empty
		// postcondition: writes all unfilled orders
		// to a text file
		void printOrders(ofstream* file);

	private:

		queue<Order*> m_ordersUnfilled;
		queue<Order*> m_ordersCompleted;
		Order* m_pCurrentOrder;


};
#endif /* ORDERS_H_ */
