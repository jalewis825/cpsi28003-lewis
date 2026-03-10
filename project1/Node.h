/*********************************************************************
University of Arkansas at Little Rock
Department of Computer Science
CPSI 28003 - 9S1: Algorithms
Spring 2026
Project 1: Doubly Linked List
Due Date: March 10, 2026, Tuesday
Name: Jessi Lewis
ID (Last 4 Digits):39929
Description of the Program:
Defines the Node class used in the doubly linked list.
Each node stores a value and maintain pointers to the
previous and next nodes in the list.
*********************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
	friend class DoublyLinkedList;
	public:
		Node();
		Node(int v);
		~Node();
		

	private:
		Node *prev;
		int  value;
		Node *next;

};

#endif
