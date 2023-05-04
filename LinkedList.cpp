#include "LinkedList.h"

//  . . . . . . . . . . Linked List Class Methods Decleration . . . . . . . . . . 

template<class Type>
LinkedList<Type>::LinkedList() {
	LinkedList<Type>::head = new Node<Type>;
	LinkedList<Type>::tail = new Node<Type>;
	LinkedList<Type>::size = 0;
}
template<class Type>
Node<Type>* LinkedList<Type>::getHead() {
	return LinkedList<Type>::head;
}
template<class Type>
Node<Type>* LinkedList<Type>::getTail() {
	return LinkedList<Type>::tail;
}
template<class Type>
bool LinkedList<Type>::isEmpty() {
	return (LinkedList<Type>::head->getNext == nullptr ? true : false);
}
template<class Type>
int LinkedList<Type>::getSize() {
	return LinkedList<Type>::size;
}
template<class Type>
void LinkedList<Type>::setHead(Node<Type>* n) {
	LinkedList<Type>::head = n;
}
template<class Type>
void LinkedList<Type>::setTail(Node<Type>* n) {
	LinkedList<Type>::tail = n;
}
template<class Type>
void LinkedList<Type>::setSize() {
	return LinkedList<Type>::size;
}
template<class Type>
void LinkedList<Type>::InsertNodeAtHead(Type data) {
	Node<Type>* newNode = new Node<Type>;
	newNode->setData(data);
	newNode->setNext(head->getNext());
	LinkedList<Type>::head->setNext(newNode);
	LinkedList<Type>::tail = newNode;
	LinkedList<Type>::size++;
	// Head -> node -> node -> node -> node<-tail
	// Head -> newNode -> node -> node -> node -> node<-tail
}
template<class Type>
void LinkedList<Type>::InsertNodeAtTail(Type data) {
	if (size == 0) {
		// If there is no Node yet
		InsertNodeAtHead(data);
		// Head -> newNode<-tail
	}
	else {
		Node<Type>* newNode = new Node<Type>;
		newNode->setData(data);
		newNode->setNext(nullptr);
		LinkedList<Type>::tail->setNext(newNode);
		LinkedList<Type>::tail = newNode;
		LinkedList<Type>::size++;
		// Head -> node -> node -> newNode<-tail
	}
}
template<class Type>
void LinkedList<Type>::InsertANode(Type nodeData, Type data) {
	bool res = false;
	Node<Type>* newNode = new Node<Type>;
	newNode->setData(nodeData);

	Node<Type>* temp = LinkedList<Type>::head->getNext();

	if (temp->getData() == data) {
		// if data is in the first node
		newNode->setNext(temp);
		LinkedList<Type>::head->setNext(newNode);
		res = true;
		size++;
	}
	else {
		if (LinkedList<Type>::tail->getData() == data) {
			// if data is in the last node
			LinkedList<Type>::tail->setNext(newNode);
			LinkedList<Type>::tail = newNode;
			res = true;
		}
		else {
			while (temp != nullptr) {
				if (temp->getData() == data) {
					newNode->setNext(temp->getNext());
					temp->setNext(newNode);
					LinkedList<Type>::size++;
					res = true;
					break;
				}
				temp = temp->getNext();
			}
		}
	}
	res == false
		? cout << "No data Found to put node in between :(\n"
		: cout << "Node is Added :)\n";
}
template<class Type>
void LinkedList<Type>::displayList() {
	Node<Type>* temp = LinkedList<Type>::head->getNext();
	cout << "Linked List :  Head -> ";
	while (temp != nullptr) {
		cout << temp->getData();
		temp = temp->getNext();
		if (temp != nullptr)
			cout << " -> ";
	}
	cout << "<-Tail\n\n";
	delete temp;
}
template<class Type>
void LinkedList<Type>::FindANode(Type data) {
	int count = 1; bool res = false;
	Node<Type>* temp = LinkedList<Type>::head->getNext();
	while (temp != nullptr) {
		if (temp->getData() == data) {
			res = true;
			break;
		}
		count++;
		temp = temp->getNext();
	}
	res == false
		? cout << "No data Found to put node in between :(\n"
		: cout << "Data ' " << data << "' is found on Node no: " << count << endl;
}
template<class Type>
void LinkedList<Type>::UpdateANode(Type nodeData, Type data) {
	bool res = false;
	Node<Type>* temp = LinkedList<Type>::head->getNext();
	while (temp != nullptr) {
		if (temp->getData() == data) {
			temp->setData(nodeData);
			res = true;
			break;
		}
		temp = temp->getNext();
	}
	res == false
		? cout << "No data Found to update a node :(\n"
		: cout << "Node is Updated :)\n";
}
template<class Type>
void LinkedList<Type>::DeletionOfHeadnode() {
	Node<Type>* temp = LinkedList<Type>::head->getNext();
	LinkedList<Type>::head->setNext(LinkedList<Type>::head->getNext()->getNext());
	delete temp;	//	This is how a node will be erased from the memory
	LinkedList<Type>::size--;
}
template<class Type>
void LinkedList<Type>::DeletionOfTailnode() {

	Node<Type>* temp = LinkedList<Type>::head->getNext();

	while (temp->getNext()->getNext() != nullptr)
		temp = temp->getNext();
	//Traversing till 2nd last node to delete the last one

	Node<Type>* pointer = temp->getNext();
	delete pointer;
	temp->setNext(nullptr);
	LinkedList<Type>::tail = temp;
	LinkedList<Type>::size--;
}
template<class Type>
void LinkedList<Type>::DeleteANode(Type nodeData) {
	bool res = false;
	if (LinkedList<Type>::head->getNext()->getData() == nodeData) {
		DeletionOfHeadnode();
		res = true;
	}
	else {
		Node<Type>* Pointer;
		Node<Type>* temp = LinkedList<Type>::head->getNext();
		Node<Type>* prev = nullptr; // Store previous node
		while (temp != nullptr) {
			if (temp->getData() == nodeData) { // Check if current node matches
				Pointer = temp;
				prev->setNext(temp->getNext());
				delete Pointer;
				res = true;
				LinkedList<Type>::size--;
				break;
			}
			prev = temp; // Update previous node
			temp = temp->getNext();
		}
	}
	if (tail->getData() == nodeData) {
		DeletionOfTailnode();
		res = true;
	}
	res == false
		? cout << "No node is found with this data ' " << nodeData << " ' :(\n\n"
		: cout << "";
}
template<class Type>
void LinkedList<Type>::ReverseTheList() {
	Node<Type>* current = LinkedList<Type>::head->getNext();
	Node<Type>* previous = nullptr;
	Node<Type>* next = nullptr;

	while (current != nullptr) {
		next = current->getNext();
		current->setNext(previous);
		previous = current;
		current = next;
	}
	LinkedList<Type>::tail = LinkedList<Type>::head->getNext();
	LinkedList<Type>::head->setNext(previous);
}
template<class Type>
LinkedList<Type>::~LinkedList() {
	Node<Type>* temp = LinkedList<Type>::head->getNext();
	// Delete all the nodes from the memory
	while (temp != nullptr) {
		Node<Type>* pointer = temp;
		temp = temp->getNext();
		delete pointer;
	}
	delete temp;
}