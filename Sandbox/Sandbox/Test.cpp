#include <iostream>
#include <string>

#include "Sandbox.h"

void main() {
	std::string intStr = "100 144";
	int a = std::stoi(intStr.substr(0, intStr.find(' ')));
	int b = std::stoi(intStr.substr(intStr.find(' '), intStr.length()));

	std::cout << a << " " << b;

	system("pause");
}