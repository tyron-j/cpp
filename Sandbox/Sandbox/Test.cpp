#include <iostream>
#include <string>

#include "Sandbox.h"
#include "IOStack.h"

void main() {
	IOStack& MyIOStack = *(new IOStack("Input.txt"));

	system("pause");
}