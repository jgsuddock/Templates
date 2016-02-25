/*
 * =====================================================================================
 *
 *    Project Name:  Lab2
 *
 * Project Descrip:  Reads in a list of numbers into a optimal binary search tree.
 *						A level-order traversal will then be output to the screen.
 *
 *        Filename:  Queue.hpp
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
Queue<T>::Queue() {
	// Initialize variables
	m_size = 0;
}

template<typename T>
Queue<T>::~Queue() {
	// Deletes each node in queue by traversing all nodes
	while(m_size != 0) {
		QNode<T>* tempPtr = m_front;
		m_front = m_front->getNext();
		delete tempPtr;
		m_size--;
	}
}

template<typename T>
bool Queue<T>::empty() {
	if(m_size == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
int Queue<T>::size() {
	return m_size;
}

template<typename T>
T Queue<T>::peek() {
	// Returns value of next in line
	return m_front->getValue();
}

template<typename T>
void Queue<T>::push(T value) {
	if(m_size == 0) { // Empty queue
		m_front = new QNode<T>(value);
		m_back = m_front;
		m_size++;
	}
	else if(m_size == 1) { // Queue contains only one element
		QNode<T>* tempPtr = new QNode<T>(value);
		m_front->setNext(tempPtr);
		m_back = tempPtr;
		m_size++;
	}
	else { // Queue contains two or greater elements
		QNode<T>* tempPtr = new QNode<T>(value);
		m_back->setNext(tempPtr);
		m_back = tempPtr;
		m_size++;
	}
}

template<typename T>
T Queue<T>::pop() {
	// Pulls out element and fixes m_front pointer
	//      to next element in list
	T value = m_front->getValue();
	QNode<T>* tempPtr = m_front;
	m_front = m_front->getNext();

	delete tempPtr;
	m_size--;
	
	return value;
}
