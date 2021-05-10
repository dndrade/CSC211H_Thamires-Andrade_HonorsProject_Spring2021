#ifndef MENTEE_H
#define MENTEE_H

#include "person.h"

class Mentee : public Person
{
public:
    Mentee() : Person(){};
    Mentee(string major);
    ~Mentee();

private:
    string major;
};

#endif // MENTEE_H
