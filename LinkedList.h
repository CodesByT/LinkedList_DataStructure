#pragma once
#include "Node.h"

template<class Type>
class LinkedList {
	int size;
	Node<Type>* head;
	Node<Type>* tail;

public:
	LinkedList();
	Node<Type>* getHead();
	Node<Type>* getTail();
	bool isEmpty();
	int getSize();
	void setHead(Node<Type>* n);
	void setTail(Node<Type>* n);
	void setSize();
	void InsertNodeAtHead(Type data);
	void InsertNodeAtTail(Type data);
	void InsertANode(Type nodeData, Type data);
	void displayList();
	void FindANode(Type data);
	void UpdateANode(Type nodeData, Type data);
	void DeletionOfHeadnode();
	void DeletionOfTailnode();
	void DeleteANode(Type nodeData);
	void ReverseTheList();
	~LinkedList();
};

