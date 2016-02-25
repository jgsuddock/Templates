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
	m_left = 0;
	m_right = 0;
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
void Node<T>::setLeft(Node<T>* left) {
	m_left = left;
}

template<typename T>
Node<T>* Node<T>::getLeft() {
	return(m_left);
}

template<typename T>
void Node<T>::setRight(Node<T>* right) {
	m_right = right;
}

template<typename T>
Node<T>* Node<T>::getRight() {
	return(m_right);
}