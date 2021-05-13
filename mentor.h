/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
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
