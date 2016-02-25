/*
 * =====================================================================================
 *
 *    Project Name:  
 *
 * Project Descrip:  
 *
 *        Filename:  Queue.h
 *
 *         Created:  
 * 
 *          Author:  Jake Suddock, Student KUID #: 2610736
 *          School:  University of Kansas, School of Engineering
 *          Course:  
 *         
 * =====================================================================================
 */

#ifndef QUEUE_H
#define QUEUE_H

 #include "Node.h"
 #include <stdio.h>

template<typename T>
class Queue {

public:
	/*
	*	Constructor
	*/
	Queue();
	/*
	*	Destructor
	*/
	~Queue();
	/*
	*	Returns True if queue size is 0
	*   Otherwise returns False
	*/
	bool empty();
	/*
	*	Returns size of queue
	*/
	int size();
	/*
	*	Returns value to next item in queue
	*/
	T peek();
	/*
	*	Adds a new item to queue
	*/
	void push(T value);
	/*
	*	Returns the value of front
	*   Removes front from queue
	*/
	T pop();

private:
	Node<T>* m_front;
	Node<T>* m_back;
	int m_size;
};

#include "Queue.hpp"

#endif