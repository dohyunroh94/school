/**************************************************************
 * File:    Node.h
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Header file for nodes of
 * LinkedList.
 *
 *
 *************************************************************/
#ifndef NODE_H_
#define NODE_H_

class Node{

	public:

		Node();
		int n_type; // Data members similar to vehicle class
		int n_timeEntered;
		int n_timeLeft;
		int n_clearTime;
		Node * link;

};
#endif /* NODE_H_ */
