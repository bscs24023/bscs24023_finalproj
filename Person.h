#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "MyVector.h"
using namespace std;

class Person 
{
    public:
        string username;

        Person();
        Person(const string& uname);
        Person(const Person& other);
        virtual ~Person();
    
};

#endif
