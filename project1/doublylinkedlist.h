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
Header file containing the class definition and functions
prototypes for the DoublyLinkedList data structure.
*********************************************************************/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "Node.h"

class DoublyLinkedList{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void addNewNodeToFront(Node* newNode);
	void addNewNodeToBack(Node* newnNde);
	Node* removeNodeFromFront();
	void removeNodeFromBack();
	void displayDoublyLinkedList();
	bool isPalindrome();
	void split(int n);
    void drawDoublyLinkedList();
	void addNewNodeBeforeTargetNode(Node* newNode, int val);

private:
	Node* head;
	Node* tail;

};
#endif
