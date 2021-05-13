/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#include "person.h"


Person::Person(int id, string firstName, string lastName, string email, string topic, int group_id)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->topic = topic;
    this->id = id;
    this->group_id = group_id;
}

Person::~Person()
{

}

void Person::print()
{
  cout << "\nFirst Name: " << firstName;
  cout << "\nSurname: " << lastName;
  cout << "\nEmail: " << email;
  cout << "\nTopic: " << topic;
  cout << "\nID: " << id;
  cout << "\nGroup: " << group_id;
}
