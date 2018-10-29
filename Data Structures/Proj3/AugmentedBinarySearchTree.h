/*****************************************
** File:    AugmentedBinarySearchTree.h
** Project: CMSC 341 Project 3, Fall 2015
** Author:  Dohyun Roh
** Date:    10/4/2015
** Section: 1
** E-mail:  roh1@umbc.edu
**
**  C++ file:
**	Brief Description of the file
**	Header file for Augmented Binary Search Tree
**
**
*******************************************/

using namespace std;

#ifndef AUGMENTED_BINARY_SEARCH_TREE_H
#define AUGMENTED_BINARY_SEARCH_TREE_H


/*---------------Imported Libraries---------------*/
#include <fstream>
#include <sstream>
#include <iostream>       // For NULL
#include <queue>


/*----------------Includes---------------------*/

#include "Exceptions.h"
//#include "BinarySearchTree.h"
//#include "Proj3Aux.h"

// Binary node and forward declaration because g++ does
// not understand nested classes.
template <class Comparable>
class AugmentedBinarySearchTree;
template <class Comparable>
class BinarySearchTree;

#ifndef BINARY_NODE
#define BINARY_NODE
template <class Comparable>
class BinaryNode
{
	Comparable element;
	BinaryNode *left;
	BinaryNode *right;
	int m_size;

	BinaryNode(const Comparable & theElement = -1, BinaryNode *lt = NULL, BinaryNode *rt = NULL, int size = -1)
		: element(theElement), left(lt), right(rt), m_size(size)  { }
	friend class AugmentedBinarySearchTree<Comparable>;
	friend class BinarySearchTree<Comparable>;

};
#endif // BINARY_NODE

template <class Comparable>
class AugmentedBinarySearchTree
{
public:
	/*------------Constructors/Destructors-------------*/

	explicit AugmentedBinarySearchTree();
	AugmentedBinarySearchTree(const AugmentedBinarySearchTree<Comparable> & rhs);
	~AugmentedBinarySearchTree();


	/*--------------Facilitators------------------------*/

	int remove(const Comparable & x);
	bool IsPerfect();
	bool IsComplete();
	void PrintLevels(int numlevels);
	void makeEmpty();

	/*---------------Getters---------------------------*/

	int RemoveResidue(); /* Assume RemoveResidue will always be called after Print */
	const Comparable & NthElement(int n);
	int Rank(const Comparable & x);
	const Comparable & Median();
	BinaryNode<Comparable> * findMin(BinaryNode<Comparable> *t) const;


	/*---------------Setters---------------------------*/

	int insert(const Comparable & x);

private:

	int insert(const Comparable & x, BinaryNode<Comparable> * & t) const;
	int remove(const Comparable & x, BinaryNode<Comparable> * & t) const;
	void PrintLevels(queue <BinaryNode<Comparable> *> q, int levels) const;
	void RemoveResidue(BinaryNode<Comparable> * & t, int *deletions) const;
	BinaryNode<Comparable> * NthElement(BinaryNode<Comparable> *t, int *nodesVisited, int n) const;
	void Rank(const Comparable & x, BinaryNode<Comparable> *t, int *nodesVisited) const;
	bool IsPerfect(queue <BinaryNode<Comparable> *> q, int height);
	void makeEmpty(BinaryNode<Comparable> * & t) const;
	//IsComplete  <-- Extra Credit!

	/*------------------Members-----------------------------*/
	BinarySearchTree<Comparable> m_tree;
	BinaryNode<Comparable> *root;
};

#include "AugmentedBinarySearchTree.cpp"
#endif // AUGMENTED_BINARY_SEARCH_TREE_H
