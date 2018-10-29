/**************************************************************
 * File:    Order.h
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for Order class
 * Represents an order with customer name, queue of food types,
 * and whether he/she accepts partial orders
 *************************************************************/


#include <queue>
#include "Food.h"



#ifndef ORDER_H_
#define ORDER_H_

using namespace std;

class Order{

	public:

		// Constructor
		Order(string CustomerName, bool AcceptsPartialOrder, bool OrderCompleted);

		// Destructor
		~Order();

		// Getters
		int getSizeOfRequests();
		int getSizeOfFilledRequests();
		bool isAcceptPartial();
		Food::FOOD_TYPE& getNextRequest();

		// Setters
		void setCustomerName(string);
		void setAcceptPartial(bool);
		void setOrderComplete(bool);


		// popFoodTypeFromOrder()
		// precondition: m_requests must be not empty
		// postcondition: pops a food type from
		// from m_requests
		void popFoodTypeFromOrder();

		// popFoodFromOrder()
		// precondition: m_filledRequests must not be empty
		// postcondition: pops food object from
		// m_filledRequests
		Food * popFoodFromOrder();

		// addRequestToOrder()
		// precondition: none
		// postcondition: adds a food type
		// to m_requests
		void addRequestToOrder(Food::FOOD_TYPE);

		// addFoodToOrder
		// precondition: none
		// postcondition: adds a food object
		// to m_filledRequests
		void addFoodToOrder(Food*);

		// printOrder
		// precondition: none
		// postcondition: prints the order to a file
		void printOrder(ofstream*);

	private:

		// data members
		string m_sCustomerName;
		queue<Food::FOOD_TYPE> m_requests;
		queue<Food*> m_filledRequests;
		bool m_bAcceptsPartialOrder;
		bool m_bOrderCompleted;

};
#endif /* ORDER_H_ */
