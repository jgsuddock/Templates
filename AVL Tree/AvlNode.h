/*
 * =====================================================================================
 *
 *    Project Name:  
 *
 * Project Descrip:  
 *
 *        Filename:  AvlNode.h
 *
 *         Created:  
 * 
 *          Author:  Jake Suddock, Student KUID #: 2610736
 *          School:  University of Kansas, School of Engineering
 *          Course:  
 *         
 * =====================================================================================
 */

#ifndef AVLNODE_H
#define AVLNODE_H

template<typename T>
class AvlNode {
public:
	/*
	*	Constructor
	*/
	AvlNode(T value);
	/*
	*	Sets the value of the Node
	*/
	void setValue(T value);
	/*
	*	Returns the value of the Node
	*/
	T getValue();
	/*
	*	Sets the pointer to the left child Node
	*/
	void setLeft(AvlNode<T>* left);
	/*
	*	Returns the pointer to the left child Node
	*/
	AvlNode<T>* getLeft();
	/*
	*	Sets the pointer to the right child Node
	*/
	void setRight(AvlNode<T>* right);
	/*
	*	Returns the pointer to the right child Node
	*/
	AvlNode<T>* getRight();
	/*
	*	Returns the pointer to the right child Node
	*/
	void setHeight(int height);
	/*
	*	Returns the pointer to the right child Node
	*/
	int getHeight();
private:
	/*
	*	Holds pointer to the child Nodes
	*/
	AvlNode<T>* m_left;
	AvlNode<T>* m_right;
	/*
	*	Holds value of Node
	*/
	T m_value;
	/*
	*   Holds the height of the Node
	*/
	int m_height;
};

#include "AvlNode.hpp"

#endif