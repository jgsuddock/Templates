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
	/*
	*	Sets the pointer to the previous Node
	*/
	void setPrevious(Node<T>* previous);
	/*
	*	Returns the pointer to the previous Node
	*/
	Node<T>* getPrevious();
private:
	/*
	*	Holds pointer to the next Node
	*/
	Node<T>* m_next;
	/*
	*	Holds pointer to the previous Node
	*/
	Node<T>* m_previous;
	/*
	*	Holds value of Node
	*/
	T m_value;
};

#include "Node.hpp"

#endif
