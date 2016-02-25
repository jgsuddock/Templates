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
	*	Sets the pointer to the next Node
	*/
	void setNext(Node<T>* next);
	/*
	*	Returns the pointer to the next Node
	*/
	Node<T>* getNext();
private:
	/*
	*	Holds pointer to the next Node
	*/
	Node<T>* m_next;
	/*
	*	Holds value of Node
	*/
	T m_value;
};

#include "Node.hpp"

#endif