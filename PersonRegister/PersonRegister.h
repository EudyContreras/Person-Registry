#pragma once

#include "stdafx.h"
#include <stdint.h>
#include "Person.h"	

class PersonRegister {

public:

	PersonRegister(int32_t maxSize);
	
	~PersonRegister();

	Person* searchPerson(string name);
	Person* performFreeSearch(string name);

	int32_t getMaxSize();
	int32_t getSize();

	void addPerson(Person* person);
	void removePerson(Person* person);
	void print();

private:
	Person* persons;

	int32_t maxSize;
	int32_t size;
};