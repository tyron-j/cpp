#include <iostream>

#include "Sandbox.h"

void main() {
	std::cout << "Hello world!" << std::endl;

	LinkedList * Pointer = new LinkedList(1); // point to new linked list
	LinkedList& MyLinkedList = *Pointer; // get value by reference

	MyLinkedList.Add(2);
	MyLinkedList.Add(3);
	MyLinkedList.Add(4);
	MyLinkedList.Add(5);
	MyLinkedList.Iterate();

	std::cout << "The length of the linked list is: " << MyLinkedList.Length << std::endl;

	delete Pointer;

	system("pause");
}