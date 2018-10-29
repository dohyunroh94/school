/*****************************************
** File:    Proj3.h
** Project: CMSC 341 Project 3, Fall 2015
** Author:  Adams, Doug
** Date:    10/4/2015
** Section: 42
** E-mail:  ???@umbc.edu
**
**  C++ file:
**	Do NOT modify this file!
**
**	This is the Proj 3 driver that handles CL args
**      and gets the show on the road.
**
**     DON'T PANIC! Just let Vogons be Vogons...
**
*******************************************/

#include "Proj3Aux.h"


int main(int argc, char *argv[])
{

	//if it has the right number of arguments
	if (argc != 3)
	{
		cout << "Usage:  ./Proj3.out input.txt commands.txt\n\n";
		cout << "input.txt - The file that contains a list of integers";
		cout << " to be inserted into a BST.\n";
		cout << "commands.txt - The file that contains the commands";
		cout << " that will be run over the BST that was created.\n\n";
	}
	Proj3Aux sim;

	/* Create Augmented BST */
	//AugmentedBinarySearchTree ABSTree = AugmentedBinarySearchTree();
	/* Read from input file to BinarySearchTree  */
	if (!sim.ReadFromInputFile(argv[1]))
	{
		cerr << "File Not Found Error: Filename '"
			<< argv[1]
			<< "' not found\n";
		return 1; // Exit with an error
	}

	/* Read from Command file */
	if (!sim.ReadFromCommandFile(argv[2]))
	{
		cerr << "File Not Found Error: Filename '"
			<< argv[2]
			<< "' not found\n";
		return 1; // Exit with an error
	}
	return 0;
}
