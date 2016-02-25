/*
 * =====================================================================================
 *
 *    Project Name:  Lab2
 *
 * Project Descrip:  Reads in a list of numbers into a optimal binary search tree.
 *						A level-order traversal will then be output to the screen.
 *
 *        Filename:  BinarySearchTree.h
 *
 *         Created:  02/01/2016
 * 
 *          Author:  Jake Suddock, Student KUID #: 2610736
 *          School:  University of Kansas, School of Engineering
 *          Course:  EECS 560, Professor: Nancy Kinnersley, Lab TA: Mehrdad Hajiarbabi
 *         
 * =====================================================================================
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TNode.h"
#include "Queue.h"
#include "stdio.h" // printf()

enum Order { PREORDER, INORDER, POSTORDER, LEVELORDER }; //Order Enumeration for Print Options

template<typename T>
class BinarySearchTree {

public:
	/*
	*  Constructor
	*/
	BinarySearchTree();
	/*
	*  Destructor
	*/
	~BinarySearchTree();
	/*
	*  Addes a value to the BST
	*/
	void push(T value);
	/*
	*  Prints the Binary Search Tree in level-order traversal
	*/
	void print();

private:
	/*
	*  Recursive function used for deleting the tree
	*/
	void deleteTree(TNode<T>* subnode);
	/*
	*  Recursive function used for pushing value to
	*      tree
	*/
	void push(T value, TNode<T>* subnode);
	/*
	*  Recursive Function to Print Tree in
	*        In-Order Traversal
	*/
	void printPreOrder(TNode<T>* subnode);
	/*
	*  Recursive Function to Print Tree in
	*        In-Order Traversal
	*/
	void printInOrder(TNode<T>* subnode);
	/*
	*  Recursive Function to Print Tree in
	*        In-Order Traversal
	*/
	void printPostOrder(TNode<T>* subnode);
	/*
	*  Function to Print Tree in Level-Order
	*        Traversal
	*/
	void printLevelOrder();

	TNode<T>* m_root;

	/*
	*  Passed into queue to hold pointer
	*      and level of that pointer
	*/
	struct nodeLevel {
		TNode<T>* nodePtr;
		int level;
	} popInfo, pushInfo;
};

#include "BinarySearchTree.hpp"

#endif