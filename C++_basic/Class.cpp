#include "Class.h"
#include <string>
#include <iostream>

Person::Person(int age, std::string name) : m_age{ age }, m_name{ name } {}

int Person::getAge() const {
	return m_age;
}

void Person::setAge(int age){
	this->m_age = age;
}

std::string Person::getName() const {
	return m_name;
}

void Person::setName(std::string name) {
	this->m_name = name;
}

void Person::display() const {
	std::cout << m_age << "---" << m_name << "\n";
}

void Person::insCount() {
	count++;
	std::cout << count << "\n";
}

int Person::count = 0;

Student::Student(int age, std::string name, int grade) : Person(age, name), m_grade(grade) {}

void Student::display() const {
	std::cout << getAge() << "---" << getName() <<"---"<<m_grade << "\n";
}