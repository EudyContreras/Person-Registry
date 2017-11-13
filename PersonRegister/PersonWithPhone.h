#pragma once
#include "Person.h"
class PersonWithPhone : public Person{

private:
	string phoneNumber;
public:
	PersonWithPhone();
	PersonWithPhone(string name, string phoneNumber,string address);
	PersonWithPhone(string name, string phoneNumber, int32_t age, string address);

	string getPhoneNumber();

	void setPhoneNumber(string number);
	virtual void print();

};
