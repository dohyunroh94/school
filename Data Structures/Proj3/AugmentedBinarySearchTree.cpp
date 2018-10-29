/*****************************************
** File:    AugmentedBinarySearchTree.cpp
** Project: CMSC 341 Project 3, Fall 2015
** Author:  Dohyun Roh
** Date:    10/29/2015
** Section: 1
** E-mail:  roh1@umbc.edu
**
**  C++ file:
**	Brief Description of the file
**	Implementation file for Augmented Binary Search
**
**
*******************************************/
#ifndef AugmentedBinarySearchTree_C
#define AugmentedBinarySearchTree_C

#include "AugmentedBinarySearchTree.h"

using namespace std;

// Constructor
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::AugmentedBinarySearchTree(){

	root = NULL;

}

// Copy constructor
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::AugmentedBinarySearchTree(const AugmentedBinarySearchTree<Comparable> & rhs){

	root = NULL;
	*this = rhs;

}

// Destructor
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::~AugmentedBinarySearchTree(){

	makeEmpty();

}

// FindMin
// Finds the minimum value in the tree
// (identical code with binary node class)
template <class Comparable>
BinaryNode<Comparable> *
AugmentedBinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> *t) const
{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);
}

// Bootstrap for insert
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::insert(const Comparable & x){

	return insert(x, root);

}

// Insert
// Inserts the element into tree
// returns 1 on success o.w. returns 0
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
insert(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	// Keeps track of current size of current node
	int * size;
	size = &(t->m_size);

	int success;

	// If a space has been found
	if (t == NULL){
		t = new BinaryNode<Comparable>(x, NULL, NULL, 1);
		return 1;

	// goes left
	}else if (x < t->element){

		// increments size and depending
		// on the success (0 or 1) will decrement back
		// one
		(*size)++;
		success = insert(x, t->left);
		if (!success){
			(*size)--;
		}
		return success;

	// goes right
	}else if (t->element < x){

		// increments size and depending
		// on the success (0 or 1) will decrement back
		// one
		(*size)++;
		success = insert(x, t->right);
		if (!success){
			(*size)--;
		}
		return success;

	// If it is duplicate
	// fails
	}else{

		return 0;

	}
}

// Bootstrap for remove
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::remove(const Comparable & x){

	return remove(x, root);

}

// Remove
// Removes element from the tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
remove(const Comparable & x, BinaryNode < Comparable > * & t) const
{

	// Keeps track of size of current node
	int * size;
	size = &(t->m_size);
	int success;

	// If Item was not found
	if (t == NULL)
		return 0;

	// goes left
	if (x < t->element){

		// decrements size and depending
		// on the success (0 or 1) will increment
		// one
		(*size)--;
		success = remove(x, t->left);
		if (!success){
			(*size)++;
		}
		return success;

	// goes right
	}else if (t->element < x){


		// decrements size and depending
		// on the success (0 or 1) will increment
		// one
		(*size)--;
		success = remove(x, t->right);

		if (!success){
			(*size)++;
		}

		return success;

	// If the element has been found and it has two children
	// decrements size and depending
	// on the success (0 or 1) will increment
	// one
	}else if (t->left != NULL && t->right != NULL){

		t->element = findMin(t->right)->element;

		(*size)--;
		success = remove(t->element, t->right);

		if (!success){
			(*size)++;
		}

		return success;

	// If the element has been found and it has 1 or less children
	}else{

		// Chooses which node to switch the chosen node with
		// depending on which side is null
		BinaryNode <Comparable> *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		(*size)--;
		delete oldNode;
		oldNode = NULL;
		return 1;
	}

}

// Bootstrap for makeEmpty
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
makeEmpty(){

	makeEmpty(root);

}

// makeEmpty
// deletes all nodes in tree (identical code to BinarySearchTree class method)
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
makeEmpty(BinaryNode<Comparable> * & t) const
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

// Bootstrap for NthElement
template <class Comparable>
const Comparable & AugmentedBinarySearchTree<Comparable>::
NthElement(int n){

	int nodes = 0;
	BinaryNode<Comparable> * returnedNode;

	// If rank does not exist (greater than size of tree)
	// throws error
	if ( n > (root->m_size)){

		throw ItemNotFound();

	}


	returnedNode = NthElement(root, &nodes, n);

	return returnedNode->element;

}

// Nth Element
// Returns the element based on given rank
// Note: nodesVisted is used as variable for rank
template <class Comparable>
BinaryNode<Comparable> * AugmentedBinarySearchTree<Comparable>::
NthElement(BinaryNode<Comparable> *t, int *nodesVisited, int n) const{

	// For base case (first time)
	if ((*nodesVisited) == 0){

		// If there is left node, increments nodesVisited
		// by its size + 1 (pretty much the rank of root)
		if (t->left!=NULL){

			(*nodesVisited) = (t->left->m_size) + 1;

		// For an empty left node (means rank is 1)
		} else {

			(*nodesVisited) = 1;

		}
	}

	// Found element with matching rank
	if ((*nodesVisited) == n){

		return t;

	}

	// If the rank of target element is greater than
	// current node rank, and there exists right child
	// goes right
	if (((*nodesVisited) < n) && ((t->right) != NULL)){

		// If the right child has left child (this would mean rank of current
		// node has to increase by more than one if going right)
		if (((t->right)->left)!= NULL){
			(*nodesVisited) += (1 + (((t->right)->left)->m_size));
			return NthElement((t->right), nodesVisited, n);

		// If right child does not have left
		// Increments the rank by one and precedes to the right
		} else {
			(*nodesVisited) += 1;
			return NthElement((t->right), nodesVisited, n);
		}

	}

	// If the rank of target element is less than
	// current node rank, and there exists left child
	// goes left
	if (((*nodesVisited) > n) && ((t->left) != NULL)){

		// If the left child has right child (this would mean rank of current
		// node has to decrease by more than one if going left)
		if (((t->left)->right)!= NULL){
			(*nodesVisited) -= (1 + (((t->left)->right)->m_size));
			return NthElement((t->left), nodesVisited, n);

		// If left child does not have right
		// Decrements the rank by one and precedes to the ;eft
		} else {
			(*nodesVisited) -= 1;
			return NthElement((t->left), nodesVisited, n);
		}

	}

}

// Bootstrap for rank
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
Rank(const Comparable & x){

	int nodes= 0;

	Rank(x, root, &nodes);

	return nodes;

}

// Rank
// Returns the rank of a given element
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
Rank(const Comparable & x, BinaryNode<Comparable> *t, int *nodesVisited) const{

	// First time
	if (((*nodesVisited) == 0)){

		// Adds one to rank
		(*nodesVisited)++;

		// Adds to rank if there are left items
		if ((t->left) != NULL){
			(*nodesVisited) += ((t->left)->m_size);
		}
	}

	// If target element is greater than current element
	// and right child is not empty
	if ((x > (t->element)) && ((t->right) != NULL)){

		// Increments rank
		// and depending on whether the right child has a left child
		// increments rank more and goes right
		(*nodesVisited)++;

		if (((t->right)->left) != NULL){
			(*nodesVisited) += (((t->right)->left)->m_size);
		}

		Rank(x, (t->right), nodesVisited);

	}

	// If target element is less than current element
	// and left child is not empty
	if ((x < (t->element)) && ((t->left) != NULL)){

		// Decrements rank
		// and depending on whether the left has a right child
		// decrements rank more and goes left
		(*nodesVisited)--;

		if (((t->left)->right) != NULL){
			(*nodesVisited) -= (((t->left)->right)->m_size);
		}

		Rank(x, (t->left), nodesVisited);

	}

	// If rank was not found, rank is set to 0
	if (x != (t->element)){
		(*nodesVisited) = 0;
	}

}

// Median
// Returns the median of a tree based on inorder traversal order
template <class Comparable>
const Comparable & AugmentedBinarySearchTree<Comparable>::
Median(){

	// If the tree completely empty
	if (root == NULL){

		// Produces error
		freopen("error.txt","a",stderr);
		cerr << "NULL Argument Exception: No median value for a tree of zero size." << endl;
		fclose (stderr);
		return (-1);
	}

	// For even number of nodes

	int total = (root->m_size);
	if ((total % 2) == 0){

		int first = (total/2);
		int second = (first + 1);
		Comparable firstElement = NthElement(first);
		Comparable secondElement = NthElement(second);

		// Will return the lesser of 2 elements
		if (firstElement > secondElement){

			return secondElement;

		} else {

			return firstElement;

		}

	// For odd number of nodes
	} else {

		// Finds the nth element of odd middle number
		total = (total/2) + 1;
		Comparable median = NthElement(total);

		return median;

	}



}

// Bootstrap for print levels
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
PrintLevels(int numLevels){

	// Starts out with queue with root
	queue <BinaryNode<Comparable> *> startingQueue;
	startingQueue.push(root);

	// For each level, prints just once
	for (int index = 0; index < numLevels; index++){

		cout << "Level " << index << ":" << endl;
		PrintLevels(startingQueue, index);
		cout << endl;
		cout << endl;
	}





}

// Print levels
// Prints the tree and each element
// (in the format : (element, size, parent))
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
PrintLevels(queue <BinaryNode<Comparable> *> q, int levels) const{

	// When levels is zero, prints out the elements in the queue
	// (when levels is decremented to zero)
	if (levels == 0){

		// When only the root is in the queue
		if (q.size() == 1){

			cout << "(" << ((q.front())->element) << ", " << ((q.front())->m_size) << ", " << "NULL)";

		// For queues with more than root
		} else {

			BinaryNode <Comparable>* parent;
			int queueSize = q.size();

			// For every single node in the queue
			for (int index1 = 0; index1 < queueSize; index1++){

				// Parent node is always every third element (starting from the first)
				if ((index1 % 3) == 0){

					parent = (q.front());

				// Prints the elements in the queue depending on
				// whether they are NULL or not
				} else {

					cout << "(";

					// Prints in the format (element, size, parent element)
					if (((q.front())->element) == NULL){
						cout << "NULL, ";
					} else {
						cout << ((q.front())->element) << ", ";
					}

					if (((q.front())->m_size) == NULL){
						cout << "NULL, ";
					} else {
						cout << ((q.front())->m_size) << ", ";
					}

					if ((parent->element) == NULL){
						cout << "NULL)";
					} else {
						cout << (parent->element) << ")";
					}


				}


				q.pop();

			}



		}



	// When levels is greater than 0 (means there are more levels to enter)
	// will recurse until levels is 0 (and add more elements to queue in the process)
	} else {

		queue<BinaryNode <Comparable> *> copy;
		BinaryNode<Comparable> * empty;

		// When only the root is in the queue
		if (q.size() == 1){

			copy.push(q.front());

			// If children of current node are null
			// adds in the empty nodes
			if (((q.front())->left) == NULL){
				empty = new BinaryNode<Comparable>(NULL, NULL, NULL, NULL);
				((q.front())->left) = empty;
				copy.push(empty);
			} else {
				copy.push((q.front()->left));
			}

			// If children of current node are null
			// adds in the empty nodes
			if ((q.front()->right) == NULL){
				empty = new BinaryNode<Comparable>(NULL, NULL, NULL, NULL);
				((q.front())->right) = empty;
				copy.push(empty);
			} else {
				copy.push((q.front()->right));
			}

			PrintLevels(copy, (levels-1));

		// When more than just the root is in queue
		} else {

			int size = q.size();
			BinaryNode <Comparable> * previous;

			for (int index2 = 0; index2 < size; index2++){


				previous = q.front();

				// For every node besides third one
				// pushes it and its children in the copy
				// (Checks if children are NULL, and creates empty
				// node)
				if ((index2 % 3) != 0){

					copy.push(previous);

					if ((previous->left) == NULL){
						empty = new BinaryNode<Comparable>(NULL, NULL, NULL, NULL);
						(previous->left) = empty;
						copy.push(empty);

					} else {
						copy.push((previous->left));
					}

					if ((previous->right) == NULL){
						empty = new BinaryNode<Comparable>(NULL, NULL, NULL, NULL);
						(previous->right) = empty;
						copy.push(empty);

					} else {
						copy.push((previous->right));
					}

				}

				q.pop();
			}

			PrintLevels(copy, (levels - 1));

		}


	}


}

// Bootstrap for RemoveResidue
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
RemoveResidue(){

	int * del;
	int number = 0;

	del = &number;

	RemoveResidue(root, del);

	return number;
}

// RemoveResidue (probably a typo..)
// Removes all empty nodes placed in by print levels
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
RemoveResidue(BinaryNode<Comparable> * & t, int *deletions) const{

	// Traverses through all nodes in tree
	// left and right

	if ((t->left != NULL)){
		RemoveResidue((t->left), deletions);
	}

	if ((t->right != NULL)){
		RemoveResidue((t->right), deletions);
	}


	// If empty nodes is detected (NULL size)
	// deletes it and increments deletions
	if ((t->m_size) == NULL){

		delete t;
		t = NULL;
		(*deletions)++;
	}

}

// Bootstrap for isPerfect
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::
IsPerfect(){

	queue <BinaryNode<Comparable> *> startingQueue;
	startingQueue.push(root);

	return IsPerfect(startingQueue, 0);

}

// IsPerfect
// Determines whether tree is perfect (balanced) or not
// (does not use height parameter)
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::
IsPerfect(queue <BinaryNode<Comparable> *> q, int height){

		// Empty tree
		if (root == NULL){

			return true;

		}

		// Used to keep track of all nodes
		queue<BinaryNode <Comparable> *> copy;

		// When only the root is in the queue
		// pushes the left and right nodes in the queue
		if (q.size() == 1){

			copy.push(q.front());

			// When both left and right nodes have nothing
			if ((((q.front())->left) == NULL) && ((q.front()->right) == NULL)){

				return true;

			}
			// If there are right and left nodes, goes deeper
			if ((((q.front())->left) != NULL) && ((q.front()->right) != NULL)){

				copy.push(((q.front())->left));
				copy.push(((q.front())->right));
				return IsPerfect(copy, height);

			// By default, nodes are uneven, therefore imperfect
			} else {

				return false;

			}

		// When more than just the root is in queue
		} else {

			int size = q.size();
			BinaryNode <Comparable> * previous;
			int numOfNull = 0;

			// For all nodes in queue (should be multiple of 3)
			// (parent, leftNode, rightNode)
			for (int index = 0; index < size; index++){

				// Current node
				previous = q.front();

				// For all non parent nodes (children nodes)
				if ((index % 3) != 0){

					copy.push(previous);

					// Pushes left of child node
					if ((previous->left) != NULL){

						copy.push((previous->left));

					// If left of child does not exist
					// increments counter
					} else {

						numOfNull++;

					}

					// Pushes right of child node
					if ((previous->right) != NULL){

						copy.push((previous->right));

					// If left of child does not exist
					// increments counter
					} else {

						numOfNull++;

					}

				}

				q.pop();
			}

			// If all children are NULL, then the
			// the number of null children is equal
			// to 4/3 of the size (because original
			// queue includes parent nodes)
			// (parent, left, right, parent, left, right...)

			// If no children are null, explore further
			// (potential for perfect tree)
			if (numOfNull == 0){

				return IsPerfect(copy, height);

			// If all children are null, it is perfect
			// (ratio between q.size and null nodes if perfect
			//	3:4)
			}else if (numOfNull == ((size * 4) / 3)){

				return true;

			// If some children are null, it is imperfect
			} else {

				return false;

			}


		}



}

#endif
