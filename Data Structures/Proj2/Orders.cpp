/**************************************************************
 * File:    Orders.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for Orders class
 * Represents orders with unfilled and completed orders
 *************************************************************/

#include "Orders.h"
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// Destructor
Orders::~Orders(){

	Order * deletedOrder;

	// Removes all order objects from m_ordersCompleted
	// and deletes them
	for (int index = 0; index < m_ordersCompleted.size(); index++){

		deletedOrder = m_ordersCompleted.front();
		m_ordersCompleted.pop();
		delete deletedOrder;


	}

	deletedOrder = NULL;

}

// addOrder
// adds an order to to unfilled orders
void Orders::addOrder(Order* order){

	m_ordersUnfilled.push(order);

}

// removeOrder
// removes an order from unfilled orders
void Orders::removeOrder(){

	m_ordersUnfilled.pop();
}

// completeOrder
// sets the current unfilled order to completed
// and adds it onto completed
// (does not remove from unfilled queue)
void Orders::completeOrder(){

	m_ordersUnfilled.front()->setOrderComplete(true);
	m_ordersCompleted.push(m_ordersUnfilled.front());

}

// getCurrentOrder
// returns the current order in
// orders unfilled
Order* Orders::getCurrentOrder(){

	m_pCurrentOrder = m_ordersUnfilled.front();
	return m_pCurrentOrder;

}

// getter
int Orders::getSizeOfOrdersUnfilled(){

	return m_ordersUnfilled.size();

}

// getter
int Orders::getSizeOfOrdersCompleted(){

	return m_ordersCompleted.size();

}

// loadOrders
// loads the orders from a text file
void Orders::loadOrders(string filename){

	// Used for string extraction
	string currentLine;
	ifstream file;
	istringstream stream;

	// Converts filename to const char
	const char* word = filename.c_str();

	// Opens file
	file.open(word);

	// Variables to store data extracted
	Order* newOrder;
	string name;
	bool partialAccept;

	// Strings that represent the
	// food data
	string acceptPartial;
	string foodType;
	string minOrMax;

	string delim1 = "\"";
	string restOfLine;
	string lineNoQuote;

	// Checks every line and ends with the carriage return and newline
	while(getline(file, currentLine)){

		// Gets rid of first quotation mark in line
		lineNoQuote = currentLine.substr(1);

		// Finds second quotation mark and extracts name
		name  = lineNoQuote.substr(0, (lineNoQuote.find(delim1)));

		// Separates rest of line from name and quotation mark
		restOfLine = lineNoQuote.substr((lineNoQuote.find(delim1)+2));

		// Uses istringstream to extract remaining data
		stream.str(restOfLine);

		// Retrieves "yes" or "no"
		stream >> acceptPartial;


		// Sets acceptPartial based on
		// yes or no
		if (acceptPartial == "yes"){
			partialAccept = true;
		} else {
			partialAccept = false;
		}


		// New order to be filled and added
		newOrder->setCustomerName(name);
		newOrder->setAcceptPartial(partialAccept);
		newOrder->setOrderComplete(false);


		// Adds the food types to order until there are no more words left
		while(stream >> foodType){


			if (foodType == "sweet"){

				newOrder->addRequestToOrder(Food::SWEET);

			}

			if (foodType == "starch"){

				newOrder->addRequestToOrder(Food::STARCH);

			}

			if (foodType == "meat"){

				newOrder->addRequestToOrder(Food::MEAT);

			}

			if (foodType == "vegetable"){

				newOrder->addRequestToOrder(Food::VEGETABLE);

			}

			if (foodType == "fruit"){

				newOrder->addRequestToOrder(Food::FRUIT);

			}

		}

		// adds the order to unfilled orders
		m_ordersUnfilled.push(newOrder);

		// clears string stream for
		// more uses
		stream.clear();
	}

	file.close();

}

// printOrders
// writes orders to a text file
void Orders::printOrders(ofstream* file){

	// Keeps track of previous referenced order
	Order * previous;

	(*file) << "---------- Orders -----------" << "\n";
	// Will print every single unfilled order
	for (int index = 0; index < m_ordersUnfilled.size(); index++){

		// Pops the order, prints it,  and
		// pushes it back onto the queue
		// to prevent loss of orders

		previous = m_ordersUnfilled.front();
		m_ordersUnfilled.pop();
		previous->printOrder(file);
		m_ordersUnfilled.push(previous);

	}



}

