#include "Node.h"

//  . . . . . . . . . . Node Class Methods Decleration . . . . . . . . . . 

template<class Type>
Node<Type>::Node() {
	Node<Type>::data = NULL;
	Node<Type>::next = nullptr;
	cout << "Node Constructed\n";
}
template<class Type>
void Node<Type>::setData(Type d) {
	Node<Type>::data = d;
}
template<class Type>
void Node<Type>::setNext(Node<Type>* n) {
	Node<Type>::next = n;
}
template<class Type>
Type Node<Type>::getData() {
	return Node<Type>::data;
}
template<class Type>
Node<Type>* Node<Type>::getNext() {
	return Node<Type>::next;
}
template<class Type>
Node<Type>::~Node() {
	cout << "Node Destructed\n";
}