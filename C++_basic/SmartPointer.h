#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <iostream>
#include <memory>

class Test2;

class Test {
public:
	std::weak_ptr<Test2> pointer;
	Test() {
		std::cout << "Constructor of Test class\n";
	}
	~Test() {
		std::cout << "Destructor of Test class \n";
	}
};

class Test2 {
public:
	Test2() {
		std::cout << "Constructor of Test2 class\n";
	}
	~Test2() {
		std::cout << "Destructor of Test2 class \n";
	}
	std::weak_ptr<Test> pointer;
};

#endif // !SMART_POINTER_H

