
#include "stdafx.h"
#include "Person.h"
#include "PersonWithPhone.h"

using namespace std;

int main()
{
	locale::global(locale("swedish"));

	Person* person = new PersonWithPhone("Eddie", "0762127679", 29, "Kronetorpsgatan 220A Malmö");
	person->print();

	delete person;

	cin.get();

	return 0;
}
