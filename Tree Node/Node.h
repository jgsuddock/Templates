/*
 * =====================================================================================
 *
 *    Project Name:  
 *
 * Project Descrip:  
 *
 *        Filename:  Node.h
 *
 *         Created:  
 * 
 *          Author:  Jake Suddock, Student KUID #: 2610736
 *          School:  University of Kansas, School of Engineering
 *          Course:  
 *         
 * =====================================================================================
 */

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
public:
	/*
	*	Constructor
	*/
	Node(T value);
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
	void setLeft(Node<T>* left);
	/*
	*	Returns the pointer to the left child Node
	*/
	Node<T>* getLeft();
	/*
	*	Sets the pointer to the right child Node
	*/
	void setRight(Node<T>* right);
	/*
	*	Returns the pointer to the right child Node
	*/
	Node<T>* getRight();
private:
	/*
	*	Holds pointer to the child Nodes
	*/
	Node<T>* m_left;
	Node<T>* m_right;
	/*
	*	Holds value of Node
	*/
	T m_value;
};

#include "Node.hpp"

#endif