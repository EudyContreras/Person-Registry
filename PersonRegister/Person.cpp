#include "stdafx.h"
#include "Person.h"

#pragma once

	Person::Person():Person("N/A", "N/A") {}

	Person::Person(string name, string address) :Person(name, 0, address){}

	Person::Person(string name, int32_t age, string address)
	{
		Person::setName(name);
		Person::setAddress(address);
		Person::setAge(age);
	}

	string Person::getName() 
	{
		return name;
	}

	string Person::getAddress() 
	{
		return address;
	}

	int32_t Person::getAge()
	{
		return age;
	}

	void Person::setName(string name)
	{
		this->name = name;
	}

	void Person::setAddress(string address)
	{
		this->address = address;
	}

	void Person::setAge(int32_t age)
	{
		this->age = age;
	}

	void Person::print() const
	{
		cout << "Name: " << name << ", ";
		cout << "Age: " << age << ", ";
		cout << "Address: " << address << ", ";
	}

	Person::~Person()
	{
	
	}

