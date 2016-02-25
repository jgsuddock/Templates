/*
 * =====================================================================================
 *
 *    Project Name:  
 *
 * Project Descrip:  
 *
 *        Filename:  Stack.hpp
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
Stack<T>::Stack() {
	//Initialize Variables
	m_top = 0;
	m_size = 0;
}

template<typename T>
Stack<T>::~Stack() {
	while(this->m_top != 0) {
		pop();
	}
}

template<typename T>
bool Stack<T>::empty() {
	if(m_size == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
int Stack<T>::size() {
	return m_size;
}

template<typename T>
T Stack<T>::peek() {
	if(m_top == 0) {
		return 0;
	}
	else {
		return m_top->getValue();
	}
}

template<typename T>
void Stack<T>::push(T value) {
	Node<T>* temp = m_top;
	m_top = new Node<T>(value);
	m_top->setNext(temp);

	m_size++;
}

template<typename T>
T Stack<T>::pop() {
	if(m_top == 0) {
		
	}
	else {
		T tempVal = m_top->getValue();
		Node<T>* tempPtr = m_top->getNext();
		delete m_top;
		m_top = tempPtr;

		m_size--;

		return(tempVal);
	}
}