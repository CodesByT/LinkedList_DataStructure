#pragma once

#include<iostream>
using namespace std;

template<class Type>
class Node {
	Type data;
	Node* next;
public:
	Node();
	void setData(Type d);
	void setNext(Node* n);
	Type getData();
	Node* getNext();
	~Node();
};

