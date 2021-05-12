#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;


class Person
{
protected:
    string firstName, lastName, email, topic;
    int id, group_id;
public:
    Person(int id, string firstName, string lastName, string email, string topic, int group_id);
    ~Person();
    virtual void print();



};

#endif // PERSON_H
