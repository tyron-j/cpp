#include <iostream>

#include "Sandbox.h"

using namespace std;

void main() {
	cout << "Hello world!" << endl;

	LinkedList * Pointer = new LinkedList(1); // point to new linked list
	LinkedList& MyLinkedList = *Pointer; // get value by reference

	MyLinkedList.Add(2);
	MyLinkedList.Add(3);
	MyLinkedList.Add(4);
	MyLinkedList.Add(5);
	MyLinkedList.Iterate();

	cout << "The length of the linked list is: " << MyLinkedList.Length << endl;

	delete Pointer;

	system("pause");
}