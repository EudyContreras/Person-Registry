#include "stdafx.h"
#include "PersonRegister.h"
#include <iostream>
#include <fstream>

#pragma once

using namespace std;

	PersonRegister::PersonRegister(int32_t maxSize)
	{
		this->size = 0;
		this->maxSize = maxSize;
		this->persons = new Person[maxSize];
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

	Person * PersonRegister::performFreeSearch(string name)
	{
		return PersonRegister::performFreeSearch(name, nullptr);
	}


	Person * PersonRegister::performFreeSearch(string subSequence, Person * last)
	{
		for (Person* personPtr = persons; personPtr != persons + maxSize; ++personPtr) {
			if (personPtr->getName().find(subSequence) != string::npos || personPtr->getAddress().find(subSequence) != string::npos) {
				if (last == nullptr) {
					return PersonRegister::performFreeSearch(subSequence, personPtr);
				}
				else {
					if (personPtr != last) {
						++last = personPtr;
						return PersonRegister::performFreeSearch(subSequence, personPtr);
					}
				}
			}
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

	void PersonRegister::addPerson(Person* person)
	{
		if (persons == nullptr) {
			persons = person;
			size++;
		}
		else {
			if (size < maxSize) {
				++persons = person;
				size++;
			}
		}
	}

	void PersonRegister::removePerson(Person* person)
	{
		for (Person* ptr = persons; ptr != persons + maxSize; ++ptr) { 
			if (ptr == person) {
				ptr = nullptr;
				delete ptr;
				size--;
			}
		}
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
		delete persons;
	}


