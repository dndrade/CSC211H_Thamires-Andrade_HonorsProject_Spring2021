#ifndef MENTOR_H
#define MENTOR_H

#include "person.h"

class Mentor : public Person
{
public:
    Mentor(int id, string firstName, string lastName, string email, string company, string topic, int group_id);
    ~Mentor();
    void print();
    


private:
    string company;

};

#endif // MENTOR_H
