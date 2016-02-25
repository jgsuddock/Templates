/*
 * =====================================================================================
 *
 *    Project Name:  
 *
 * Project Descrip:  
 *
 *        Filename:  Queue.hpp
 *
 *         Created:  
 * 
 *          Author:  Jake Suddock, Student KUID #: 2610736
 *          School:  University of Kansas, School of Engineering
 *          Course:  
 *         
 * =====================================================================================
 */

template<typename T>
Queue<T>::Queue() {
	m_size = 0;
}

template<typename T>
Queue<T>::~Queue() {
	while(m_size != 0) {
		Node<T>* tempPtr = m_front;
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
	return m_front->getValue();
}

template<typename T>
void Queue<T>::push(T value) {
	if(m_size == 0) {
		m_front = new Node<T>(value);
		m_back = m_front;
		m_size++;
	}
	else if(m_size == 1) {
		Node<T>* tempPtr = new Node<T>(value);
		m_front->setNext(tempPtr);
		m_back = tempPtr;
		m_size++;
	}
	else {
		Node<T>* tempPtr = new Node<T>(value);
		m_back->setNext(tempPtr);
		m_back = tempPtr;
		m_size++;
	}
}

template<typename T>
T Queue<T>::pop() {
	T value = m_front->getValue();
	Node<T>* tempPtr = m_front;
	m_front = m_front->getNext();
	delete tempPtr;
	m_size--;
	return value;
}
