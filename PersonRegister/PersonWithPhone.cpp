#include "stdafx.h"
#include "PersonWithPhone.h"

using namespace std;

PersonWithPhone::PersonWithPhone() : PersonWithPhone("N/A","N/A","N/A"){}

PersonWithPhone::PersonWithPhone(string name, string phoneNumber, string address):PersonWithPhone(name, phoneNumber, 0, address){}

PersonWithPhone::PersonWithPhone(string name, string phoneNumber, int32_t age, string address) : Person(name, age, address)
{
	this->phoneNumber = phoneNumber;
}

string PersonWithPhone::getPhoneNumber()
{
	return phoneNumber;
}

void PersonWithPhone::setPhoneNumber(string number)
{
	this->phoneNumber = number;
}

void PersonWithPhone::print()
{
	cout << "Name: " << getName() << ", ";
	cout << "Age: " << getAge() << ", ";
	cout << "Phone Number: " << getPhoneNumber() << ", ";
	cout << "Address: " << getAddress() << ", ";
}
