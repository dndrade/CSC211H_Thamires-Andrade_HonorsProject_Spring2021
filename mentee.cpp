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