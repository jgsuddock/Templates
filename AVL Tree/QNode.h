/*
 * =====================================================================================
 *
 *    Project Name:  Lab2
 *
 * Project Descrip:  Reads in a list of numbers into a optimal binary search tree.
 *						A level-order traversal will then be output to the screen.
 *
 *        Filename:  QNode.h
 *    File Descrip:  Queue Node:
 *                         - Value of node
 *                         - One pointer to next node
 *
 *         Created:  02/01/2016
 * 
 *          Author:  Jake Suddock, Student KUID #: 2610736
 *          School:  University of Kansas, School of Engineering
 *          Course:  EECS 560, Professor: Nancy Kinnersley, Lab TA: Mehrdad Hajiarbabi
 *         
 * =====================================================================================
 */

#ifndef QNODE_H
#define QNODE_H

template<typename T>
class QNode {
public:
	/*
	*	Constructor
	*/
	QNode(T value);
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
	void setNext(QNode<T>* next);
	/*
	*	Returns the pointer to the next Node
	*/
	QNode<T>* getNext();
private:
	/*
	*	Holds pointer to the next Node
	*/
	QNode<T>* m_next;
	/*
	*	Holds value of Node
	*/
	T m_value;
};

#include "QNode.hpp"

#endif