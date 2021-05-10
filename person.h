#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
public:
    Person(){};
    Person(string firstName, string lastName,
           string email, string topic, int id, int group_id);
    ~Person();



private:
    string firstName, lastName, email, topic;
    int id, group_id;
};

#endif // PERSON_H
