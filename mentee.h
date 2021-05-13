/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
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
