#ifndef MENTEE_H
#define MENTEE_H

#include "person.h"

class Mentee : public Person
{
public:
    Mentee();
    ~Mentee();

    string getMajor();
    void setMajor(string major);

private:
    string major;
};

#endif // MENTEE_H
