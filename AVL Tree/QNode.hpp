/*
 * =====================================================================================
 *
 *    Project Name:  Lab2
 *
 * Project Descrip:  Reads in a list of numbers into a optimal binary search tree.
 *						A level-order traversal will then be output to the screen.
 *
 *        Filename:  QNode.hpp
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

template<typename T>
QNode<T>::QNode(T value) {
	//Initialize Variables
	m_value = value;
	m_next = 0;
}

template<typename T>
void QNode<T>::setValue(T value) {
	m_value = value;
}

template<typename T>
T QNode<T>::getValue()  {
	return(m_value);
}

template<typename T>
void QNode<T>::setNext(QNode<T>* next) {
	m_next = next;
}

template<typename T>
QNode<T>* QNode<T>::getNext() {
	return(m_next);
}