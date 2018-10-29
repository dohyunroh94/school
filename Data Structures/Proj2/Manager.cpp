/**************************************************************
 * File:    Manager.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for Manager class
 * Represents a manager with a store and orders
 *************************************************************/


#include "Manager.h"
#include <stack>

// Constructor
Manager::Manager(){

	m_store = new Store();
	m_orders = new Orders();
}

// Destructor
Manager::~Manager(){

	delete m_store;
	delete m_orders;

	m_store = NULL;
	m_orders = NULL;


}

// createStore
// fills the store with
// values from text file
void Manager::createStore(string filename){

	m_store->stockStore(filename);

}

// createOrders
// fills orders with
// values from text file
void Manager::createOrders(string filename){

	m_orders->loadOrders(filename);

}

// fillOrders
// Fills out orders
// by comparing with what food
// the store has and adding/removing
// foods from appropriate places
void Manager::fillOrders(ofstream* file){

	// Keeps track of current order and food type
	Order * currentOrder;
	Food::FOOD_TYPE foodTypeAdded;

	// Uses stack to maintain food order
	stack<Food*> stackIterator;
	int SizeOfRequests;

	// For every single unfilled order in m_orders
	int SizeOfOrdersUnfilled = m_orders->getSizeOfOrdersUnfilled();
	for (int index1 = 0; index1 < SizeOfOrdersUnfilled; index1++){

		currentOrder = m_orders->getCurrentOrder();

		// For every single request of a single order
		SizeOfRequests = currentOrder->getSizeOfRequests();
		for (int index2 = 0; index2 < SizeOfRequests; index2++){

			// The food type that was requested by an order
			foodTypeAdded = currentOrder->getNextRequest();

			// If the store is not empty
			// adds food object to current order
			// and removes it from store
			if(!(m_store->isEmpty(foodTypeAdded))){
				currentOrder->addFoodToOrder(m_store->getFoodByType(foodTypeAdded));
			}

			// Does this to iterate through the request queue without
			// losing requests
			currentOrder->popFoodTypeFromOrder();
			currentOrder->addRequestToOrder(foodTypeAdded);

		}

		// If customer doesn't accept partial orders
		if (!currentOrder->isAcceptPartial()){

			// Adds all of the food from the order onto stackIterator (stack)
			while(currentOrder->getSizeOfFilledRequests() != 0){
				stackIterator.push(currentOrder->popFoodFromOrder());
			}

			// Adds the food back to the store from stackIterator (stack)
			// in reverse order
			while(stackIterator.size() !=0 ){
				m_store->addFood(stackIterator.top());
				stackIterator.pop();
			}


		}

		// Iterates through orders without losing
		// any order
		m_orders->removeOrder();
		m_orders->addOrder(currentOrder);
		m_orders->completeOrder();

	}

}

// printStatus
// prints store and orders to file
void Manager::printStatus(ofstream* file){

	m_store->printStore(file);
	m_orders->printOrders(file);

}
