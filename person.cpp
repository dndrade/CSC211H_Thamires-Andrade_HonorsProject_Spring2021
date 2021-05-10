#include "person.h"


Person::Person(string firstName, string lastName, string email, string topic, int id, int group_id)
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
