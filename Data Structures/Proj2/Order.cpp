/**************************************************************
 * File:    Order.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for Order class
 * Represents an order with customer name, queue of food types,
 * and whether he/she accepts partial orders
 *************************************************************/

#include "Order.h"
#include "Food.h"
#include <iostream>

using namespace std;

	// Constructor
	Order::Order(string sCustomerName, bool bAcceptsPartialOrder, bool bOrderCompleted){

		m_sCustomerName = sCustomerName;
		m_bAcceptsPartialOrder = bAcceptsPartialOrder;
		m_bOrderCompleted = bOrderCompleted;

	}

	// Destructor
	Order::~Order(){

		Food * deletedFood;

		// Pops all food objects from filledRequests and
		// deletes them
		for (int index=0; index < m_filledRequests.size(); index++){

			deletedFood = m_filledRequests.front();
			m_filledRequests.pop();
			delete deletedFood;

		}

		deletedFood = NULL;

	}

	// getters
	int Order::getSizeOfRequests(){

		return m_requests.size();

	}

	int Order::getSizeOfFilledRequests(){

		return m_filledRequests.size();

	}

	bool Order::isAcceptPartial(){

		return m_bAcceptsPartialOrder;

	}

	// setters
	void Order::setCustomerName(string name){

		m_sCustomerName = name;

	}

	void Order::setAcceptPartial(bool partial){

		m_bAcceptsPartialOrder = partial;

	}

	void Order::setOrderComplete(bool complete){

		m_bOrderCompleted = complete;

	}

	Food::FOOD_TYPE& Order::getNextRequest(){

		return m_requests.front();

	}


	// popFoodTypeFromOrder
	// pops foodtype from m_requests
	void Order::popFoodTypeFromOrder(){

		m_requests.pop();

	}

	// popFoodFromOrder
	// pops food from m_filledRequests
	// and returns the popped item
	Food * Order::popFoodFromOrder(){

		Food * popped;
		popped = m_filledRequests.front();
		m_filledRequests.pop();
		return popped;

	}

	// addRequestToOrder
	// adds the foodType to m_requests
	void Order::addRequestToOrder(Food::FOOD_TYPE add){

		m_requests.push(add);

	}

	// addFoodToOrder
	// adds a food object to m_filledRequests
	void Order::addFoodToOrder(Food* addition){

		m_filledRequests.push(addition);

	}

	// printOrder
	// prints the order to a file
	void Order::printOrder(ofstream* file){

		// Used to keep track of
		// current food type and food object
		Food::FOOD_TYPE lastFood;
		Food* foodItem;

		double total = 0;

		// Counters for foodTypes within
		// m_requests
		int sweetCount1 = 0;
		int starchCount1 = 0;
		int meatCount1 = 0;
		int vegeCount1 = 0;
		int fruitCount1 = 0;

		// Counters for foodTypes within
		// m_filledRequests
		int sweetCount2 = 0;
		int starchCount2 = 0;
		int meatCount2 = 0;
		int vegeCount2 = 0;
		int fruitCount2 = 0;

		// If order is not completed yet
		if (!(m_bOrderCompleted)){


			// Writes the name and requests
			(*file) << m_sCustomerName << "\n";
			(*file) << "Requests: ";
			for (int index1 = 0; index1 < m_requests.size(); index1++){

				// Checks current Food type in requests
				// and writes the appropriate food type
				if (m_requests.front() == Food::SWEET){

					(*file) << "Sweet ";

				} else if (m_requests.front() == Food::STARCH) {

					(*file) << "Starch ";

				} else if (m_requests.front() == Food::MEAT) {

					(*file) << "Meat ";

				} else if (m_requests.front() == Food::VEGETABLE) {

					(*file) << "Vegetable ";

				} else if (m_requests.front() == Food::FRUIT) {

					(*file) << "Fruit ";

				}

				// Takes current food type
				// and moves it to back
				// of m_requests queue
				// (this allows for proper iteration)
				lastFood = m_requests.front();
				m_requests.pop();
				m_requests.push(lastFood);


			}

			(*file) << "\n";
			(*file) << "-----" << "\n";


		} else {

			// If order is complete
			// (when order is complete, regardless
			// of partial or not, m_filledRequests will
			// the same size as m_requests)
			if(m_requests.size() == m_filledRequests.size()){

				// Writes name and food items purchased
				(*file) << m_sCustomerName << "\n";
				(*file) << "Items:" << "\n";

				for (int index2 = 0; index2 < m_filledRequests.size(); index2++){

					// Takes the current food object in filledRequests
					// and writes to the file the name and price
					m_filledRequests.front()->printFood(file);
					(*file) << " $" << m_filledRequests.front()->getPrice() << "\n";

					// Adds up the prices for a total
					total += m_filledRequests.front()->getPrice();

					// Puts current food object to the
					// back of filledRequests (for iteration)
					foodItem = m_filledRequests.front();
					m_filledRequests.pop();
					m_filledRequests.push(foodItem);

				}

				// Displays total
				(*file) << "***Total: $" << total << "\n";
				(*file) << "-----" << "\n";


			// If partial orders are accepted
			}else if (m_bAcceptsPartialOrder){

				// Prints name
				(*file) << m_sCustomerName << " (Partial)" << "\n";
				(*file) << "Unfilled Requests: ";

				// Uses for loop to count how many of each food type
				// is in the requests queue
				for (int index3 = 0; index3 < m_requests.size(); index3++){

					if (m_requests.front() == Food::SWEET){

						sweetCount1++;

					} else if (m_requests.front() == Food::STARCH) {

						starchCount1++;

					} else if (m_requests.front() == Food::MEAT) {

						meatCount1++;

					} else if (m_requests.front() == Food::VEGETABLE) {

						vegeCount1++;

					} else if (m_requests.front() == Food::FRUIT) {

						fruitCount1++;

					}

					lastFood = m_requests.front();
					m_requests.pop();
					m_requests.push(lastFood);


				}

				// Uses for loop to count how many of each food type
				// is in the filledRequests queue
				for(int index4 = 0; index4 < m_filledRequests.size();index4++){

					if ((m_filledRequests.front()->getType()) == Food::SWEET){

						sweetCount2++;


					} else if ((m_filledRequests.front()->getType()) == Food::STARCH){

						starchCount2++;


					} else if ((m_filledRequests.front()->getType()) == Food::MEAT){

						meatCount2++;


					} else if ((m_filledRequests.front()->getType()) == Food::VEGETABLE){

						vegeCount2++;


					} else if ((m_filledRequests.front()->getType()) == Food::FRUIT){

						fruitCount2++;

					}

					foodItem = m_filledRequests.front();
					m_filledRequests.pop();
					m_filledRequests.push(foodItem);

				}

				// Compares how many of each type is in the request queue versus the
				// filled request queue. If the number of each food type
				// in filled request is lower than the number of each food type
				// in request, then it will iterate the difference of the two numbers
				// and write to the file what food type was unfilled the appropriate
				// amount of times

				if (sweetCount2 < sweetCount1){

					for (int sIndex = 0; sIndex < (sweetCount1 - sweetCount2); sIndex++){
						(*file) << "Sweet ";
					}
				}

				if (starchCount2 < starchCount1){

					for (int stIndex = 0; stIndex < (starchCount1 - starchCount2); stIndex++){
						(*file) << "Starch ";
					}

				}

				if (meatCount2 < meatCount1){

					for (int meatIndex = 0; meatIndex < (meatCount1 - sweetCount2); meatIndex++){
						(*file) << "Meat ";
					}

				}

				if (vegeCount2 < vegeCount1){

					for (int vIndex = 0; vIndex < (vegeCount1 - vegeCount2); vIndex++){
						(*file) << "Vegetable ";
					}

				}

				if (fruitCount2 < fruitCount1){

					for (int fIndex = 0; fIndex < (fruitCount1 - fruitCount2); fIndex++){
						(*file) << "Fruit ";
					}
				}

			(*file) << "\n";

			// Prints out the food name and cost of each food
			// that was filled (identical code from completely filled case)
			total = 0;
			for (int index5 = 0; index5 < m_filledRequests.size(); index5++){

				m_filledRequests.front()->printFood(file);
				(*file) << " " << m_filledRequests.front()->getPrice() << "\n";

				// Calculated total
				total += m_filledRequests.front()->getPrice();

				// Moves on to next food in filledRequests
				foodItem = m_filledRequests.front();
				m_filledRequests.pop();
				m_filledRequests.push(foodItem);

			}

			// Displays total
			(*file) << "***Total: $" << total << "\n";
			(*file) << "-----" << "\n";


			// If partial orders are not accepted.
			// (Nearly identical code with incomplete order)
			} else {

				// Displays name and unfilled requests
				(*file) << m_sCustomerName << " - Unable to complete order" << "\n";
				(*file) << "Unfilled Requests: ";

				for (int index6 = 0; index6 < m_requests.size(); index6++){

					// Writes to file every order on m_requests
					if (m_requests.front() == Food::SWEET){

						(*file) << "Sweet ";

					} else if (m_requests.front() == Food::STARCH) {

						(*file) << "Starch ";

					} else if (m_requests.front() == Food::MEAT) {

						(*file) << "Meat ";

					} else if (m_requests.front() == Food::VEGETABLE) {

						(*file) << "Vegetable ";

					} else if (m_requests.front() == Food::FRUIT) {

						(*file) << "Fruit ";

					}

					// Iterates to next foodType on requests
					lastFood = m_requests.front();
					m_requests.pop();
					m_requests.push(lastFood);

				}

				(*file) << "\n" << "-----" << "\n";

			}

		}

		foodItem = NULL;

	}




