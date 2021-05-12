#ifndef MENTEE_H
#define MENTEE_H

#include "person.h"

class Mentee : public Person
{
private:
    string major;
    
public:
    Mentee(int id, string firstName, string lastName, string email, string major, string topic, int group_id);
    ~Mentee();
    void print();


};
#endif // MENTEE_H
