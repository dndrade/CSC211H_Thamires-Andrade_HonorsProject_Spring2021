#include "mentor.h"

Mentor::Mentor(int id, string firstName, string lastName, string email, string company, string topic, int group_id) : Person(id, firstName, lastName, email, topic, group_id)
{
    this->company = company;
}

Mentor::~Mentor()
{
  
}

void Mentor::print()
{
  cout << "\nFirst Name: " << firstName;
  cout << "\nSurname: " << lastName;
  cout << "\nEmail: " << email;
  cout << "\nConpany: " << company;
  cout << "\nTopic: " << topic;
  cout << "\nID: " << id;
  cout << "\nGroup: " << group_id;
}
