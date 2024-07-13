#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <iostream>

class Person {
private:
	int m_age;
	std::string m_name;
public:
	static int count;
	Person(int age, std::string name);
	int getAge() const;
	void setAge(int age);
	std::string getName() const;
	void setName(std::string name);
	void insCount();
	virtual void display() const;
	virtual ~Person() = default;
};

class Student : public Person {
private:
	int m_grade;
public:
	Student(int age, std::string name, int grade);
	void display() const override;
	~Student() {
		std::cout << "Destructor of Student class\n";
	}
};

class AbstractClass {
public:
	virtual void typeClass() = 0;
};

class DerviedClass : public AbstractClass{
public:
	void typeClass() {
		std::cout << "Derived Class\n";
	}
};

#endif // !CLASS_H

