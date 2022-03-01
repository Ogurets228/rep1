#pragma once
#include "Animal.h"
#include <iostream>;
#include <string>

using namespace std;

class Cat : public Animal
{
public:
	const string ala = "ala";

	Cat(string name, int age) :Animal(name)
	{
		this->name = name;
		this->age = age;
	}

	~Cat()
	{
		cout << "Destructed cat" << this->ala << endl;
	}

	void run()
	{
		cout << "Cat is running\n";
	}

	void setName(string new_name)
	{
		this->name = "Cat " + new_name;
	}

	void setAge(int new_age)
	{
		this->age = new_age;
	}

	int getAge()
	{
		return this->age;
	}
	
private:
	int age;
};