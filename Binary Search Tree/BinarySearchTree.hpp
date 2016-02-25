/*
 * =====================================================================================
 *
 *    Project Name:  Lab2
 *
 * Project Descrip:  Reads in a list of numbers into a optimal binary search tree.
 *						A level-order traversal will then be output to the screen.
 *
 *        Filename:  BinarySearchTree.hpp
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
BinarySearchTree<T>::BinarySearchTree() {
	m_root = 0;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	if(m_root != 0) {
		deleteTree(m_root);
	}
}

template<typename T>
void BinarySearchTree<T>::push(T value) {
	if(m_root == 0) {
		m_root = new TNode<T>(value);
	}
	else {
		push(value, m_root);
	}
}

/*
*  Prints BST in Pre-Order, In-Order, Post-Order
*      or Level-Order
*/
template<typename T>
void BinarySearchTree<T>::print(Order order) {

	printf("\n");

	if(m_root == 0) {
		printf("Tree is Empty");
	}
	else {
		switch(order) {
		case PREORDER:
			printPreOrder(m_root);
			break;
		case INORDER:
			printInOrder(m_root);
			break;
		case POSTORDER:
			printPostOrder(m_root);
			break;
		default:
			printLevelOrder();
			break;
		}
	}
	printf("\n\n");
}

/*
*  Recursive delete function
*/
template<typename T>
void BinarySearchTree<T>::deleteTree(TNode<T>* subnode) {
	// Deletes tree from leaves up to the root
	if(subnode->getLeft() != 0) {
		deleteTree(subnode->getLeft());
	}
	if(subnode->getRight() != 0) {
		deleteTree(subnode->getRight());
	}
	delete subnode;
}

/*
*  Recursive push function
*/
template<typename T>
void BinarySearchTree<T>::push(T value, TNode<T>* subnode) {
	// Value is equal to current node
	if(value == subnode->getValue()) {
		std::cout << "The value " << value << " has already been pushed\nto the tree and cannot be pushed again.";
	}
	// Value is right of the current node, move to that subtree.
	if(value > subnode->getValue()) {
		if(subnode->getRight() == 0) {
			TNode<T>* tempPtr = new TNode<T>(value);
			subnode->setRight(tempPtr);
		}
		else {
			push(value, subnode->getRight());
		}
	}
	// Value is left of the current node, move to that subtree.
	if(value < subnode->getValue()) {
		if(subnode->getLeft() == 0) {
			TNode<T>* tempPtr = new TNode<T>(value);
			subnode->setLeft(tempPtr);
		}
		else {
			push(value, subnode->getLeft());
		}
	}
}

template<typename T>
void BinarySearchTree<T>::printPreOrder(TNode<T>* subnode) {
	std::cout << subnode->getValue() << " "; //Prints every node in tree
	if(subnode->getLeft() != nullptr) {
		PreOrderPrint(subnode->getLeft()); //Recurses with every left node
	}
	if(subnode->getRight() != nullptr) {
		PreOrderPrint(subnode->getRight()); //Recurses with every right node
	}
}

template<typename T>
void BinarySearchTree<T>::printInOrder(TNode<T>* subnode) {
	if(subnode->getLeft() != nullptr) { //Recurses with every left node
		InOrderPrint(subnode->getLeft());
	}
	std::cout << subnode->getValue() << " "; //Prints each node value
	if(subnode->getRight() != nullptr) { //Recurses with every right node
		InOrderPrint(subnode->getRight());
	}
}

template<typename T>
void BinarySearchTree<T>::printPostOrder(TNode<T>* subnode) {
	if(subnode->getLeft() != nullptr) { //Recurses with every left node
		PostOrderPrint(subnode->getLeft());
	}
	if(subnode->getRight() != nullptr) { //Recurses with every right node
		PostOrderPrint(subnode->getRight());
	}
	std::cout << subnode->getValue() << " "; //Prints each node value
}

template<typename T>
void BinarySearchTree<T>::printLevelOrder() {
	Queue<nodeLevel>* queue = new Queue<nodeLevel>();
		
	int currentLevel = -1;

	//Load Root at Level 0 into Queue
	pushInfo.nodePtr = m_root;
	pushInfo.level = 0;
	queue->push(pushInfo);

	// In FIFO order, pulls a node at a time, prints it, and adds it's
	//     descendents to the queue.
	while(!queue->empty()) {
		popInfo = queue->pop();

		if(popInfo.nodePtr->getLeft() != 0) {
			pushInfo.nodePtr = popInfo.nodePtr->getLeft();
			pushInfo.level = popInfo.level + 1;

			queue->push(pushInfo);
		}
		if(popInfo.nodePtr->getRight() != 0) {
			pushInfo.nodePtr = popInfo.nodePtr->getRight();
			pushInfo.level = popInfo.level + 1;

			queue->push(pushInfo);
		}

		//Prints nodes in same line if they are on the same level in tree
		if(popInfo.level == currentLevel) { //Continue on current level
			std::cout << ", " << popInfo.nodePtr->getValue();
		}
		else { //Start New Level
			std::cout << "\nLevel " << popInfo.level << ": " << popInfo.nodePtr->getValue();
			currentLevel = popInfo.level;
		}
	}
}