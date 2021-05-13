/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#include "mentee.h"

Mentee::Mentee(int id, string firstName, string lastName, string email, string major, string topic, int group_id) : Person (id, firstName, lastName, email, topic, group_id)
{
    this->major = major;
}

Mentee::~Mentee()
{
  
}

void Mentee::print()
{
   cout << "\nFirst Name: " << firstName;
  cout << "\nSurname: " << lastName;
  cout << "\nEmail: " << email;
  cout << "\nMajor: " << major;
  cout << "\nTopic: " << topic;
  cout << "\nID: " << id;
  cout << "\nGroup: " << group_id;
}
