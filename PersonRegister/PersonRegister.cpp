#include "stdafx.h"
#include "PersonRegister.h"
#include <iostream>
#include <fstream>

#pragma once

	PersonRegister::PersonRegister(int32_t maxSize)
	{
		this->size = 0;
		this->maxSize = maxSize;
		this->persons = new Person[maxSize];
		for (Person* ptr = persons; ptr != persons + maxSize; ++ptr) {
			ptr = nullptr; //Check later
		}
	}

	void PersonRegister::addPerson(Person* person)
	{
		if (size < maxSize) {
			persons[size] = *person;
			size++;
		}
	}

	void PersonRegister::removePerson(Person* person)
	{
		int32_t counter = 0;

		for (Person* ptr = persons; ptr != persons + maxSize; ++ptr) {
			if (ptr == person) {
				delete ptr;
				ptr = nullptr;

				for (Person* ptrOff = ptr; ptrOff != ptr + size; ++ptrOff) {
					ptr = ptr + 1;
				}
				size--;
			}
			counter++;
		}
	}

	Person * PersonRegister::searchPerson(string name)
	{
		for (Person* ptr = persons; ptr != persons + maxSize; ++ptr) {
			if (ptr->getName().compare(name) == 0) {
				return ptr;
			}
		}
		return nullptr;
	}

	Person * PersonRegister::performFreeSearch(string subSequence)
	{
		Person* personArrTemp = new Person[maxSize];

		uint32_t counter = 0;

		for (Person* personPtr = persons; personPtr != persons + maxSize; ++personPtr) {

			auto subName = personPtr->getName().find(subSequence);

			auto subAddress = personPtr->getAddress().find(subSequence);

			if (subName != string::npos || subAddress != string::npos) {

				personArrTemp[counter] = *personPtr;

				counter++;
			}
		}

		Person* personArr = new Person[counter];

		uint32_t index = 0;

		for (Person* personPtr = personArrTemp; personPtr != personArrTemp + counter; ++personPtr) {

			personArr[index] = *personPtr;

			index++;
		}

		if (index > 0) {
			return personArr;
		}

		return nullptr;
	}

	int32_t PersonRegister::getSize()
	{
		return size;
	}

	int32_t PersonRegister::getMaxSize()
	{
		return maxSize;
	}

	void PersonRegister::print()
	{
		cout << "Register Max Size: " << maxSize << endl;
		cout << "Register actual Size: " << size << endl;

		for (Person* ptr = persons; ptr != persons + maxSize; ++ptr) {
			ptr->print();
		}
	}

	bool ReadReg(PersonRegister& registry, string fileName) 
	{ 
		string line;  

		ifstream myfile(fileName);  

		if (myfile.is_open()) { 
			while (getline(myfile, line)) 
			{ 
				while (line.length() == 0 && getline(myfile, line));    
				string name(line);    
				string adress;    
				getline(myfile, adress);    
				registry.addPerson(&Person(name, adress));
			}   
			myfile.close();   
			return true; 
		} else { 
			cout << "Unable to open file";   
			return false; 
		} 
	}

	PersonRegister::~PersonRegister()
	{
		delete[] persons;
	}


