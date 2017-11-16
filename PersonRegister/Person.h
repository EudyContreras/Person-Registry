#include "stdafx.h"
#include <iostream>
#include <string>

#pragma once
using namespace std;

class Person {

public:
	Person();
	Person(string name, string address);
	Person(string name, int32_t age, string address);
	
	virtual ~Person();

	string getAddress();
	string getName();

	int32_t getAge();

	void setName(string name);
	void setAddress(string address);
	void setAge(int32_t age);

	virtual void print();

private:
	int32_t age;
	string name;
	string address;

};