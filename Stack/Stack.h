/*
 * =====================================================================================
 *
 *    Project Name:  
 *
 * Project Descrip:  
 *
 *        Filename:  Stack.h
 *
 *         Created:  
 * 
 *          Author:  Jake Suddock, Student KUID #: 2610736
 *          School:  University of Kansas, School of Engineering
 *          Course:  
 *         
 * =====================================================================================
 */

#ifndef STACK_H
#define STACK_H

#include "Node.h"

template<typename T>
class Stack {
public:
	/*
	*	Constructor
	*/
	Stack();
	/*
	*	Destructor
	*/
	~Stack();
	/*
	*	Returns True if queue size is 0
	*   Otherwise returns False
	*/
	bool empty();
	/*
	*	Returns size of stack
	*/
	int size();
	/*
	*	Returns value to next item in stack
	*/
	T peek();
	/*
	*	Adds a new item to stack
	*/
	void push(T value);
	/*
	*	Returns the value of top
	*   Removes top from stack
	*/
	T pop();
private:
	Node<T>* m_top;
	int m_size;
};

#include "Stack.hpp"

#endif