/*
 * =====================================================================================
 *
 *    Project Name:  
 *
 * Project Descrip:  
 *
 *        Filename:  Node.hpp
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
Node<T>::Node(T value) {
	//Initialize Variables
	m_value = value;
	m_next = 0;
}

template<typename T>
void Node<T>::setValue(T value) {
	m_value = value;
}

template<typename T>
T Node<T>::getValue()  {
	return(m_value);
}

template<typename T>
void Node<T>::setNext(Node<T>* next) {
	m_next = next;
}

template<typename T>
Node<T>* Node<T>::getNext() {
	return(m_next);
}

template<typename T>
void Node<T>::setPrevious(Node<T>* previous) {
	m_previous = previous;
}

template<typename T>
Node<T>* Node<T>::getPrevious() {
	return(m_previous);
}
