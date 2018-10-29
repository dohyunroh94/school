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
**	Header file for Proj3Aux
**
**
*******************************************/


#include "BinarySearchTree.h"
#include "AugmentedBinarySearchTree.h"
#ifndef PROJ3AUX_H_
#define PROJ3AUX_H_

class Proj3Aux{

	public:

		// Destructor
		~Proj3Aux();

		// Commands
		void DoPrintCommand(int depth);
		int DoRemoveCommand(int element);
		int GetMedianCommand();
		int GetNthElementCommand(int nthElement);
		int GetRankCommand(int element);
		int GetResidualsCommand();
		bool IsComplete();
		bool IsPerfect();

		// Reads in from inpute files
		int ReadFromCommandFile(char *commandFile);
		int ReadFromInputFile(char* inputFile);



	private:

		AugmentedBinarySearchTree<int> m_tree;
};
#endif /* PROJ3AUX_H_ */
