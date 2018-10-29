/**************************************************************
 * File:    Store.cpp
 * Project: CMSC 341 - Project 2 - Store Manager and Order filler
 * Author : Dohyun Roh
 * Date   : 10/14/2105
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Implementation file for Store class
 * Represents a store with a vector of stacks that
 * represent each food type and holds foods of that type
 *************************************************************/

#include "Store.h"
#include "Food.h"
#include <fstream>
#include <istream>
#include <sstream>
#include <string>

using namespace std;

// Constructor
Store::Store(){

	stack<Food*> addedStack;

	// Adds stacks to the vector
	for (int index = 0; index < 5; index++){

		m_bins.push_back(addedStack);

	}

	// Note: For this program
	// each stack represents a food type
	// indexes 0, 1, 2, 3, 4
	// will represent
	// Meat, Fruit, Vegetable, Starch, Sweet
	// respectively



}

// Destructor
Store::~Store(){

	Food * deletedFood;

	// Iterates five times because
	// m_bins will always only have five stacks
	for (int index1 = 0; index1 < 5; index1++){

		// Iterates the size of each stack
		for (int index2 = 0; index2 < m_bins[index1].size(); index2 ++){

			// Pops the current stack and
			// deletes the current food
			deletedFood = m_bins[index1].top();
			m_bins[index1].pop();
			delete deletedFood;

		}

	}

	deletedFood = NULL;
}

// addFood
// adds a certain food to the store
void Store::addFood(Food* food){


	// Pushes the food onto
	// each respective food stack
	// (constructor comment states
	// which index represents which food
	// type)
	if (food->getType() == Food::MEAT){

		m_bins[0].push(food);

	}

	if (food->getType() == Food::FRUIT){

		m_bins[1].push(food);

	}

	if (food->getType() == Food::VEGETABLE){

		m_bins[2].push(food);

	}

	if (food->getType() == Food::STARCH){

		m_bins[3].push(food);

	}

	if (food->getType() == Food::SWEET){

		m_bins[4].push(food);

	}

}

// getFoodByType
// returns the next food on a stack
// by the type
Food* Store::getFoodByType(Food::FOOD_TYPE foodType){

	Food * foodOut;

	// Will choose a food
	// from a certain stack depending
	// on given foodType (pops it)
	if (foodType == Food::MEAT){

		foodOut = m_bins[0].top();
		m_bins[0].pop();

	}

	if (foodType == Food::FRUIT){

		foodOut = m_bins[1].top();
		m_bins[1].pop();

	}

	if (foodType == Food::VEGETABLE){

		foodOut = m_bins[2].top();
		m_bins[2].pop();

	}

	if (foodType == Food::STARCH){

		foodOut = m_bins[3].top();
		m_bins[3].pop();

	}

	if (foodType == Food::SWEET){

		foodOut = m_bins[4].top();
		m_bins[4].pop();

	}

	// Returns the popped food
	return foodOut;

}

// isEmpty
// returns whether the stack
// of the given food type
// is empty or not
bool Store::isEmpty(Food::FOOD_TYPE food){

	// Returns true if the stack
	// for the food type
	// is empty
	if (food == Food::MEAT){

		if (m_bins[0].empty()){

			return true;

		}

	}

	if (food == Food::FRUIT){

		if (m_bins[1].empty()){

			return true;

		}

	}

	if (food == Food::VEGETABLE){

		if (m_bins[2].empty()){

			return true;

		}

	}

	if (food == Food::STARCH){

		if (m_bins[3].empty()){

			return true;

		}

	}

	if (food== Food::SWEET){

		if (m_bins[4].empty()){

			return true;

		}

	}


	// Default (if stack is not empty)
	return false;

}

// stockStore
// Stocks m_bins with input from textfile
void Store::stockStore(string filename){

	// Necessary ifstream and stringstream
	string currentLine;
	ifstream file;
	istringstream stream;

	// Converts filename to const char
	const char* word;
	word = filename.c_str();

	// opens file
	file.open(word);

	// Used for keeping track of
	// current Food Food Types and names
	Food* addedFood;
	string foodName;
	Food::FOOD_TYPE type;

	// Used to extract info from each line
	string delim1 = "\"";
	string restOfLine;
	string lineNoQuote;
	string foodType;

	double price;

	// Checks every line and ends with the carriage return and newline
	while(getline(file, currentLine)){


		// Gets rid of first quotation mark in line
		lineNoQuote = currentLine.substr(1);

		// Finds second quotation mark and extracts food name
		foodName  = lineNoQuote.substr(0, (lineNoQuote.find(delim1)));

		// Separates rest of line from food name and quotation mark
		restOfLine = lineNoQuote.substr((lineNoQuote.find(delim1)+2));

		// Uses istringstream to extract remaining data
		stream.str(restOfLine);

		// Extracts data
		stream >> foodType >> price;

		// Checks which food type was indicated in text
		// and type is set to said food type as well as price
		if (foodType == "sweet"){

			type = Food::SWEET;
			addedFood = new Food(foodName, Food::SWEET, price);

		}

		if (foodType == "starch"){

			type = Food::STARCH;
			addedFood = new Food(foodName, Food::STARCH, price);

		}

		if (foodType == "meat"){

			type = Food::MEAT;
			addedFood = new Food(foodName, Food::MEAT, price);

		}

		if (foodType == "vegetable"){

			type = Food::VEGETABLE;
			addedFood = new Food(foodName, Food::VEGETABLE, price);

		}

		if (foodType == "fruit"){

			type = Food::FRUIT;
			addedFood = new Food(foodName, Food::FRUIT, price);

		}

		// Adds the food to the store
		addFood(addedFood);

		// Clears the string stream to be used again
		stream.clear();

	}

	// Closes file
	file.close();

}

// printStore
// Writes the contents of the store
// to a text file
void Store::printStore(ofstream* file){

	// Keeps track of current food object
	Food * previous;

	// Used to maintain food order when
	// putting removed food back onto original stack
	stack<Food*> stackIterator;

	int stackSize;


	(*file) << ("---------- Store ----------") << ("\n");

	// Prints the meat size
	int meatSize = m_bins[0].size();
	(*file) << "Meat: ";
	(*file) << meatSize << " ";

	// Checks if meat stack is empty
	if (meatSize > 0){

		//For each meat item, prints the name
		// (uses another stack to iterate through elements
		// to not lose data when popping through m_bins)
		for (int index1 = 0; index1 < meatSize; index1++){

			previous = m_bins[0].top();
			m_bins[0].pop();
			previous->printFood(file);

			// Checks if it is not the last food item
			if (index1 != (meatSize-1)){
				(*file) << ", ";
			}

			// Pushes removed items onto different stack
			stackIterator.push(previous);
		}


		stackSize = stackIterator.size();

		// Takes items from stackIterator and
		// puts them back to the original stack
		for (int index2 = 0; index2 < stackSize; index2++){
			previous = stackIterator.top();
			stackIterator.pop();
			m_bins[0].push(previous);
		}

	}

	int fruitSize = m_bins[1].size();

	// Prints fruit size
	(*file) << "\nFruit: ";
	(*file) << fruitSize << " ";

	// Checks if fruit stack is empty
	if (fruitSize > 0){


		//For each fruit item, prints the name
		// (uses another stack to iterate through elements
		// to not lose data when popping through m_bins)
		for (int index3 = 0; index3 < fruitSize; index3++){

			previous = m_bins[1].top();
			m_bins[1].pop();
			previous->printFood(file);

			// Checks if it is not the last food item
			if (index3 != (fruitSize-1)){
				(*file) << ", ";
			}

			stackIterator.push(previous);
		}

		// Takes items from stackIterator and
		// puts them back to the original stack
		stackSize = stackIterator.size();
		for (int index4 = 0; index4 < stackSize; index4++){
			previous = stackIterator.top();
			stackIterator.pop();
			m_bins[1].push(previous);
		}

	}

	int vegetableSize = m_bins[2].size();

	// Prints vegetable size
	(*file) << "\nVegetable:  ";
	(*file) << vegetableSize << " ";

	// Checks if vegetable stack is empty
	if (vegetableSize > 0){


		//For each vegetable item, prints the name
		// (uses another stack to iterate through elements
		// to not lose data when popping through m_bins)
		for (int index5 = 0; index5 < vegetableSize; index5++){


			previous = m_bins[2].top();
			m_bins[2].pop();
			previous->printFood(file);

			// Checks if it is not the last food item
			if (index5 != (vegetableSize-1)){
				(*file) << ", ";
			}

			stackIterator.push(previous);
		}

		// Takes items from stackIterator and
		// puts them back to the original stack
		stackSize = stackIterator.size();
		for (int index6 = 0; index6 < stackSize; index6++){
			previous = stackIterator.top();
			stackIterator.pop();
			m_bins[2].push(previous);
		}

	}

	int starchSize = m_bins[3].size();

	// Prints starch size
	(*file) << "\nStarch: ";
	(*file) << starchSize << " ";

	//Checks if starch stack is empty
	if (starchSize > 0){


		//For each starch item, prints the name
		// (uses another stack to iterate through elements
		// to not lose data when popping through m_bins)
		for (int index7 = 0; index7 < starchSize; index7++){

			previous = m_bins[3].top();
			m_bins[3].pop();
			previous->printFood(file);

			// Checks if it is not the last food item
			if (index7 != (starchSize-1)){
				(*file) << ", ";
			}

			stackIterator.push(previous);
		}

		// Takes items from stackIterator and
		// puts them back to the original stack
		stackSize = stackIterator.size();
		for (int index8 = 0; index8 < stackSize; index8++){
			previous = stackIterator.top();
			stackIterator.pop();
			m_bins[3].push(previous);
		}

	}


	int sweetSize = m_bins[4].size();

	// Prints sweet size
	(*file) << "\nSweet: ";
	(*file) << sweetSize << " ";

	// Checks if sweet stack is empty
	if (sweetSize > 0){


		//For each sweet item, prints the name
		// (uses another stack to iterate through elements
		// to not lose data when popping through m_bins)
		for (int index9 = 0; index9 < sweetSize; index9++){

			previous = m_bins[4].top();
			m_bins[4].pop();
			previous->printFood(file);

			// Checks if it is not the last food item
			if (index9 != (sweetSize-1)){
				(*file) << ", ";
			}

			stackIterator.push(previous);
		}

		// Takes items from stackIterator and
		// puts them back to the original stack
		stackSize = stackIterator.size();
		for (int index10 = 0; index10 < stackSize; index10++){
			previous = stackIterator.top();
			stackIterator.pop();
			m_bins[4].push(previous);
		}

	}

	(*file) << "\n";

}




