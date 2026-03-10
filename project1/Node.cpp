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
Implements the Node class used by the doubly linked list,
including the constructor that initializes the node's value
and its previous and next pointers.
*********************************************************************/

#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"
Node::Node()
{
	prev = NULL;
	value = 0;
	next = NULL;
}

Node::Node(int v)
{
	prev = NULL;
	value = v;
	next = NULL;
}

Node::~Node()
{
	
}

#endif
