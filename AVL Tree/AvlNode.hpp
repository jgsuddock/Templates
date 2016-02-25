/*
 * =====================================================================================
 *
 *    Project Name:  
 *
 * Project Descrip:  
 *
 *        Filename:  AvlNode.hpp
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
AvlNode<T>::AvlNode(T value) {
	//Initialize Variables
	m_value = value;
	m_left = 0;
	m_right = 0;
	m_height = 0;
}

template<typename T>
void AvlNode<T>::setValue(T value) {
	m_value = value;
}

template<typename T>
T AvlNode<T>::getValue()  {
	return(m_value);
}

template<typename T>
void AvlNode<T>::setLeft(AvlNode<T>* left) {
	m_left = left;
}

template<typename T>
AvlNode<T>* AvlNode<T>::getLeft() {
	return(m_left);
}

template<typename T>
void AvlNode<T>::setRight(AvlNode<T>* right) {
	m_right = right;
}

template<typename T>
AvlNode<T>* AvlNode<T>::getRight() {
	return(m_right);
}

template<typename T>
void AvlNode<T>::setHeight(int height) {
	m_height = height;
}

template<typename T>
int AvlNode<T>::getHeight() {
	return(m_height);
}