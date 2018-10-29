/**************************************************************
 * File:    Clear.h
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Dohyun Roh
 * Date   : 9/30/2015
 * Section: 1
 * E-mail: roh1@umbc.edu
 *
 * Stores the clear time sets for Vehicle objects
 *
 *************************************************************/

// If Clear1 is typed as arg
// this set is used
#ifdef Clear1
#define Motor 1
#define Car 1
#define Truck 2

// If Clear2 is typed as arg
// this set is used
#elif Clear2
#define Motor 1
#define Car 2
#define Truck 4

// If Clear3 is typed as arg
// this set is used
#elif Clear3
#define Motor 2
#define Car 4
#define Truck 6
#endif

#ifndef CLEAR_H_
#define CLEAR_H_
#endif /* CLEAR_H_ */
