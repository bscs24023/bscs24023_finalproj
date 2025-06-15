#include "Person.h"
#include "MyVector.h"
#include <iostream>

Person::Person() : username("") {}

Person::Person(const string& uname) : username(uname) {}

Person::Person(const Person& other) : username(other.username) {}

Person::~Person() {}

void Person::displayUser() const 
{
    cout << endl;
    cout << "Username: " << username << endl;
}