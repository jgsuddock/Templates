//
// =====================================================================================
//
//    Project Name:  
//
// Project Descrip:  
//
//        Filename:  AvlTree.hpp
//
//         Created:  
// 
//          Author:  Jake Suddock, Student KUID #: 2610736
//          School:  University of Kansas, School of Engineering
//          Course:  
//         
// =====================================================================================
//

template<typename T>
AvlTree<T>::AvlTree() {
	m_root = 0;
}

template<typename T>
AvlTree<T>::~AvlTree() {
	if(m_root != 0) {
		deleteTree(m_root);
	}
}

template<typename T>
void AvlTree<T>::push(T value) {
	if(m_root == 0) {
		m_root = new AvlNode<T>(value);
	}
	else {
		push(value, m_root);
	}
}

template<typename T>
void AvlTree<T>::pop(T value) {
	if(m_root == 0) {
		printf("Cannot Pop From Empty Tree\n");
	}
	else {
		pop(value, m_root, 0);
	}
}

/*
*  Prints in level-order traversal
*     due to printf(), AvlTree template type must be
*     integer.
*/
template<typename T>
void AvlTree<T>::print() {

	printf("\n");

	if(m_root == 0) {
		printf("Tree is Empty");
	}
	else { //Uses breadth-first search to print all nodes
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
				printf(", %d",popInfo.nodePtr->getValue());
			}
			else { //Start New Level
				printf("\nLevel %d: %d",popInfo.level,popInfo.nodePtr->getValue());
				currentLevel = popInfo.level;
			}
		}
	}
	printf("\n\n");
}

/*
*  Recursive delete function
*/
template<typename T>
void AvlTree<T>::deleteTree(AvlNode<T>* subnode) {
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
void AvlTree<T>::push(T value, AvlNode<T>* subnode) {
	// Value is equal to current node
	if(value == subnode->getValue()) {
		printf("The value %d has already been pushed\nto the tree and cannot be pushed again.",value);
	}
	// Value is right of the current node, move to that subtree.
	if(value > subnode->getValue()) {
		if(subnode->getRight() == 0) {
			AvlNode<T>* tempPtr = new AvlNode<T>(value);
			subnode->setRight(tempPtr);
		}
		else {
			push(value, subnode->getRight());
		}
	}
	// Value is left of the current node, move to that subtree.
	if(value < subnode->getValue()) {
		if(subnode->getLeft() == 0) {
			AvlNode<T>* tempPtr = new AvlNode<T>(value);
			subnode->setLeft(tempPtr);
		}
		else {
			push(value, subnode->getLeft());
		}
	}

	balance(subnode);
}

/*
*  Recursive pop function
*/
template<typename T>
void AvlTree<T>::pop(T value, AvlNode<T>* subnode, AvlNode<T>* parentnode) {
	// Value is right of the current node, move to that subtree.
	if(value > subnode->getValue()) {
		if(subnode->getRight() == 0) {
			printf("The value cannot be removed from the tree. It does not exist.");
		}
		else {
			pop(value, subnode->getRight(), subnode);
		}
	}
	// Value is left of the current node, move to that subtree.
	if(value < subnode->getValue()) {
		if(subnode->getLeft() == 0) {
			printf("The value cannot be removed from the tree. It does not exist.");
		}
		else {
			pop(value, subnode->getLeft(), subnode);
		}
	}
	if(value == subnode->getValue()) {
		// Subnode has both children
		if(subnode->getLeft() != 0 && subnode->getRight() != 0) {
			subnode->setValue(rightMin(subnode->getRight())->getValue());
			pop(subnode->getValue(), subnode->getRight(), subnode);
		}
		else {
			if(subnode->getLeft() != 0) {
				AvlNode<T>* tempPtr = subnode;
				subnode = tempPtr->getLeft();
				if(parentnode != 0) {
					if(parentnode->getLeft() == tempPtr) {
						parentnode->setLeft(subnode);
					}
					else {
						parentnode->setRight(subnode);
					}
				}
				delete tempPtr;
			}
			else if(subnode->getRight() != 0) {
				AvlNode<T>* tempPtr = subnode;
				subnode->setValue(tempPtr->getValue());
				subnode->setRight(0);
				if(parentnode != 0) {
					if(parentnode->getLeft() == tempPtr) {
						parentnode->setLeft(subnode);
					}
					else {
						parentnode->setRight(subnode);
					}
				}
				delete tempPtr;
			}
			else {
				AvlNode<T>* tempPtr = subnode;
				subnode = 0;
				if(parentnode != 0) {
					if(parentnode->getLeft() == tempPtr) {
						parentnode->setLeft(0);
					}
					else {
						parentnode->setRight(0);
					}
				}
				delete tempPtr;
			}
		}
	}

	balance(subnode);
}

template<typename T>
AvlNode<T>* AvlTree<T>::rightMin(AvlNode<T>* subnode) {
	if(subnode->getLeft() == 0) {
		return subnode;
	}
	else {
		return rightMin(subnode->getLeft());
	}
}

/*
*  Rebalance Subtree
*/
template<typename T>
void AvlTree<T>::balance(AvlNode<T>* subnode) {
	if(subnode == 0) {
		return;
	}
	if(height(subnode->getLeft()) - height(subnode->getRight()) > 1) { // Left > Right
		if(subnode->getLeft()->getRight() == 0) {
			singleRotationClock(subnode);
		}
		else {
			if(height(subnode->getLeft()->getLeft()) >= height(subnode->getLeft()->getRight())) {
				singleRotationClock(subnode);
			}
			else {
				doubleRotationClock(subnode);
			}
		}
	}
	else if(height(subnode->getRight()) - height(subnode->getLeft()) > 1) { // Right > Left
		if(subnode->getRight()->getLeft() == 0) {
			singleRotationCounter(subnode);
		}
		else {
			if(height(subnode->getRight()->getRight()) >= height(subnode->getRight()->getLeft())) {
				singleRotationCounter(subnode);
			}
			else {
				doubleRotationCounter(subnode);
			}
		}
	}
	subnode->setHeight(max(height(subnode->getRight()), height(subnode->getLeft())) + 1);
}

template<typename T>
int AvlTree<T>::height(AvlNode<T>* subnode) {
	if(subnode == 0) {
		return -1;
	}
	else {
		return subnode->getHeight();
	}
}

template<typename T>
int AvlTree<T>::max(int a, int b) {
	if(a > b) {
		return a;
	}
	else {
		return b;
	}
}

template<typename T>
void AvlTree<T>::singleRotationCounter(AvlNode<T>* root) {
	// Rearranges subtree
	AvlNode<T>* subnode = root->getRight();
	root->setRight(subnode->getRight());
	subnode->setRight(subnode->getLeft());
	subnode->setLeft(root->getLeft());
	root->setLeft(subnode);

	// Resets heights
	root->setHeight(max(height(root->getLeft()), height(root->getRight())) + 1);
	subnode->setHeight(max(height(subnode->getLeft()), height(subnode->getRight())) + 1);

	// Swaps values of root and subtree
	T temp = subnode->getValue();
	subnode->setValue(root->getValue());
	root->setValue(temp);
}

template<typename T>
void AvlTree<T>::singleRotationClock(AvlNode<T>* root) {
	// Rearranges subtree
	AvlNode<T>* subnode = root->getLeft();
	root->setLeft(subnode->getLeft());
	subnode->setLeft(subnode->getRight());
	subnode->setRight(root->getRight());
	root->setRight(subnode);

	// Resets heights
	root->setHeight(max(height(root->getLeft()), height(root->getRight())) + 1);
	subnode->setHeight(max(height(subnode->getLeft()), height(subnode->getRight())) + 1);

	// Swaps values of root and subtree
	T temp = subnode->getValue();
	subnode->setValue(root->getValue());
	root->setValue(temp);
}

template<typename T>
void AvlTree<T>::doubleRotationCounter(AvlNode<T>* root) {
	// Rearranges subtree
	AvlNode<T>* greater = root->getRight();
	AvlNode<T>* lesser = greater->getLeft();
	greater->setLeft(lesser->getRight());
	lesser->setRight(greater);
	root->setRight(lesser);

	// Resets heights
	greater->setHeight(max(height(greater->getLeft()), height(greater->getRight())) + 1);

	// Perform second rotation
	singleRotationCounter(root);
}

template<typename T>
void AvlTree<T>::doubleRotationClock(AvlNode<T>* root) {
	// Rearranges subtree
	AvlNode<T>* lesser = root->getLeft();
	AvlNode<T>* greater = lesser->getRight();
	lesser->setRight(greater->getLeft());
	greater->setLeft(lesser);
	root->setLeft(greater);

	// Resets heights
	lesser->setHeight(max(height(lesser->getLeft()), height(lesser->getRight())) + 1);

	// Perform second rotation
	singleRotationClock(root);
}