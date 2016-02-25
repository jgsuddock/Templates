//
// =====================================================================================
//
//    Project Name:  
//
// Project Descrip:  
//
//        Filename:  AvlTree.h
//
//         Created:  
// 
//          Author:  Jake Suddock, Student KUID #: 2610736
//          School:  University of Kansas, School of Engineering
//          Course:  
//         
// =====================================================================================
//

#ifndef AVLTREE_H
#define AVLTREE_H

#include "AvlNode.h"
#include "Queue.h"
#include "stdio.h" // printf()

template<typename T>
class AvlTree {

public:
	/*
	*  Constructor
	*/
	AvlTree();
	/*
	*  Destructor
	*/
	~AvlTree();
	/*
	*  Addes a value to the AVL
	*/
	void push(T value);
	/*
	*  Removes a value from the AVL
	*/
	void pop(T value);
	/*
	*  Prints the AVL in level-order traversal
	*/
	void print();

private:
	/*
	*  Recursive function used for deleting the tree
	*/
	void deleteTree(AvlNode<T>* subnode);
	/*
	*  Recursive function used for pushing value to
	*      tree
	*/
	void push(T value, AvlNode<T>* subnode);
	/*
	*  Recursive function used for removing value from
	*      tree
	*/
	void pop(T value, AvlNode<T>* subnode, AvlNode<T>* parentnode);
	/*
	*  Recursive function to find the minimum value in
	 *     the right subtree.
	*/
	AvlNode<T>* rightMin(AvlNode<T>* subnode);
	/*
	*  Determines need for rebalance
	*/
	void balance( AvlNode<T>* subnode);
	/*
	*  Returns height of Node or -1 if Node == nullptr
	*/
	int height(AvlNode<T>* subnode);
	/*
	*  Returns the max of two integers
	*/
	int max(int a, int b);

	void singleRotationCounter(AvlNode<T>* root);

	void singleRotationClock(AvlNode<T>* root);

	void doubleRotationCounter(AvlNode<T>* root);

	void doubleRotationClock(AvlNode<T>* root);

	AvlNode<T>* m_root;

	/*
	*  Passed into queue to hold pointer
	*      and level of that pointer
	*/
	struct nodeLevel {
		AvlNode<T>* nodePtr;
		int level;
	} popInfo, pushInfo;
};

#include "AvlTree.hpp"

#endif