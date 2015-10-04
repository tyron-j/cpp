#include <iostream>
#include <fstream>
#include "IOStack.h"

IOStack::IOStack(std::string FileName) {
	std::cout << "File name: " << FileName << std::endl;

	MyFile = std::ifstream(FileName);

	Output();
}

void IOStack::Output() {
	if (MyFile.is_open()) {
		int i = 0;
		std::string Line;

		while (std::getline(MyFile, Line) && i < NumOperations) {
			Interpret(Line);

			i++;
		}

		MyFile.close();
	}

	// to-do: remove
	for (int j = 0; j < NumOperations; j++) {
		if (Operations[j] != "") {
			// std::cout << Operations[j] << std::endl;
		}
		else {
			break;
		}
	}
}

void IOStack::Peek() {
	// to-do: incomplete implementation (?)
	if (NumItems > 0) {
		std::cout << (*Last).Data << std::endl;
	}
	else {
		std::cout << "EMPTY" << std::endl;
	}
}

void IOStack::Pop() {
	// to-do: incomplete implementation
	if (NumItems > 0 && (*Last).Prev != nullptr) {
		IOStackNode * NewLast = (*Last).Prev;
		(*NewLast).Next = nullptr;

		delete Last;

		Last = NewLast;
	}
}

void IOStack::Push(int Number) {
	// to-do: incomplete implementation
	IOStackNode * NewNode = new IOStackNode(Number);
	(*Last).Next = NewNode;
	Last = NewNode;

	NumItems++;

	Peek();
}

void IOStack::Inc(int NumBotItems, int IncValue) {
	//
}

void IOStack::Interpret(std::string Operation) {
	// pointers
	int * A = new int;
	int * B = new int;
	int * OpLen = new int;
	std::string * OpName = new std::string;

	*OpLen = Operation.length();

	*OpName = Operation.substr(0, Operation.find(" "));

	if (*OpName == "pop") {
		Pop();
	}
	else if (*OpName == "push") {
		*A = std::stoi(Operation.substr(Operation.find(" "), *OpLen));

		Push(*A);
	}
	else if (*OpName == "inc") {
		// Delimiter indeces
		int * FirstIdx = new int;
		int * SecondIdx = new int;

		*FirstIdx = Operation.find(" ");
		*SecondIdx = Operation.find(" ", *FirstIdx + 1);

		*A = std::stoi(Operation.substr(*FirstIdx + 1, *OpLen - *SecondIdx));
		*B = std::stoi(Operation.substr(*SecondIdx + 1, *OpLen));

		// std::cout << *A << std::endl;
		// std::cout << *B << std::endl;

		Inc(*A, *B);

		delete FirstIdx;
		delete SecondIdx;
	}
	else { // unidentified operation
		//
	}

	delete A;
	delete B;
	delete OpLen;
	delete OpName;
}