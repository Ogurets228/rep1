#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal(string name) {
		this->name = name;
		cout << "Constructed animal\n";
	}
	~Animal() {
		cout << "Destructed animal\n";
	}
	void run() {
		cout << "Animal is running\n";
	}
	string getName() {
		return this->name;
	}
	void setName(string new_name) {
		this->name = new_name;
	}

protected:
	string name;
};