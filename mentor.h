#ifndef MENTOR_H
#define MENTOR_H

#include "person.h"

class Mentor : public Person
{
public:
    Mentor() : Person(){};
    Mentor(string company);


private:
    string company;

};

#endif // MENTOR_H
