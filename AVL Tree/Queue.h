/*
 * =====================================================================================
 *
 *    Project Name:  Lab2
 *
 * Project Descrip:  Reads in a list of numbers into a optimal binary search tree.
 *						A level-order traversal will then be output to the screen.
 *
 *        Filename:  Queue.h
 *
 *         Created:  02/01/2016
 * 
 *          Author:  Jake Suddock, Student KUID #: 2610736
 *          School:  University of Kansas, School of Engineering
 *          Course:  EECS 560, Professor: Nancy Kinnersley, Lab TA: Mehrdad Hajiarbabi
 *         
 * =====================================================================================
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "QNode.h"

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
	QNode<T>* m_front;
	QNode<T>* m_back;
	int m_size;
};

#include "Queue.hpp"

#endif