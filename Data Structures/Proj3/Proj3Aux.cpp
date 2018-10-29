/*****************************************
** File:    Proj3Aux.cpp
** Project: CMSC 341 Project 3, Fall 2015
** Author:  Dohyun Roh
** Date:    10/29/2015
** Section: 1
** E-mail:  roh1@umbc.edu
**
**  C++ file:
**
**	Implementation file for Proj3Aux
**
**
*******************************************/


#include "Proj3Aux.h"

using namespace std;

// Destructor
// Deletes all nodes in tree
Proj3Aux::~Proj3Aux(){

	m_tree.makeEmpty();

}

// DoPrintCommand
// prints levels of tree
void Proj3Aux::DoPrintCommand(int depth){

	m_tree.PrintLevels(depth);

}

// DoRemoveCommand
// Removes element from tree and
// returns 0 or 1 based on failure or success
int Proj3Aux::DoRemoveCommand(int element){

	return m_tree.remove(element);

}

// GetMedianCommand
// Retrieves median
int Proj3Aux::GetMedianCommand(){


	return m_tree.Median();

}

// GetNthElementCommand
// Returns Nth element
int Proj3Aux::GetNthElementCommand(int nthElement){

	// Tries nth element and catches exception if element was not found
	try{
		return m_tree.NthElement(nthElement);

	} catch (ItemNotFound & e){

		freopen("error.txt","a",stderr);
		cerr << "Item Not Found Exception: Nth element does not exist" << endl;
		fclose (stderr);
		return -1;
	}
}

// GetRankCommand
// Returns Rank of given element based on in order traversal
int Proj3Aux::GetRankCommand(int element){

	int rank = m_tree.Rank(element);

	// If rank returned was 0, node was not found
	if (rank == 0){

		// Writes error and returns -1 as rank
		freopen("error.txt","a",stderr);
		cerr << "Node Not Found Exception: BST does not contain element" << endl;
		fclose (stderr);
		return -1;

	}

	return rank;

}

// GetResidualsCommands
// returns the number of empty nodes
// removed
int Proj3Aux::GetResidualsCommand(){

	return m_tree.RemoveResidue();

}

// IsPerfect
// Returns true or false
// based on whether the tree is balanced or not
bool Proj3Aux::IsPerfect(){

	return m_tree.IsPerfect();

}
// ReadFromCommandFile
// Reads in commands from command text file
int Proj3Aux::ReadFromCommandFile(char *commandFile){

	// Used for reading in command strings
	// and values
	string currentLine;
	string command;
	istringstream stream;
	int number;

	// Converts to const char * (just in case)
	const char * commands = commandFile;

	// Opens ifstream
	ifstream file(commands);

	// Checks for file presence
	if (file){

		// Checks every line of the file
		while(getline(file, currentLine)){

			// Ignores comments and blank lines

			if (((currentLine[0]) != '#') && ((currentLine) != "")){

				stream.str(currentLine);

				// Extracts the command
				stream >> command;

				// For NTh command
				if (command == "NTH"){

					stream >> number;

					cout << "NTH " << number << ": "
							<< GetNthElementCommand(number) << endl;
					cout << endl;

				// For median
				} else if (command == "MEDIAN"){

					cout << "MEDIAN: " << GetMedianCommand() << endl;
					cout << endl;

				// For rank
				} else if (command == "RANK"){

					stream >> number;

					cout << "RANK " << number << ": " <<
							GetRankCommand(number) << endl;
					cout << endl;

				// For residuals
				} else if (command == "RESIDUALS"){

					cout << "RESIDUALS: " << GetResidualsCommand() << endl;

					cout << endl;

				// For remove
				} else if (command == "REMOVE"){

					stream >> number;

					// If remove was successful
					if (DoRemoveCommand(number)){

						cout << "REMOVE " << number << ": SUCCESS" << endl;
						cout << endl;

					// If failed
					} else {

						cout << "REMOVE " << number << ": FAILED" << endl;
						cout << endl;

					}

				// For perfect
				} else if (command == "PERFECT"){

					// If perfect
					if (IsPerfect()){
						cout << "PERFECT: YES" << endl;
						cout << endl;

					// If not
					} else {
						cout << "PERFECT: NO" << endl;
						cout << endl;
					}

				// For print levels
				} else if (command == "PRINT"){

					stream >> number;

					cout << "PRINT " << number << endl;
					cout << endl;


					DoPrintCommand(number);



				// Did not attempt complete()
				} else if (command == "COMPLETE"){

					freopen("error.txt","a",stderr);
					cerr << "COMPLETE command has not been implemented." << endl;
					fclose (stderr);

				// If command does not match
				} else {

					freopen("error.txt","a",stderr);
					cerr << "Invalid Command Exception: " << command
							<< " is not a valid command" << endl;

					fclose (stderr);
				}


				// Clears stream for further use
				stream.clear();

			}


		}

		file.close();

		return 1;

	// Returns 0 on failure to take in commands
	} else {

		return 0;
	}

}

// ReadFromInputFile
// Reads in the numbers from text file
// and inserts into tree
int Proj3Aux::ReadFromInputFile(char* inputFile){

	const char * input = inputFile;

	ifstream file(input);

	int number;

	// If file exists
	if (file){

		// While there are numbers
		while(file >> number ){

			// Inserts the numbers
			m_tree.insert(number);

		}

		file.close();
		return 1;

	// If no file
	// returns failure
	} else {

		return 0;

	}

}
