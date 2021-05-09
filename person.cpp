#include "person.h"

Person::Person()
{

}

Person::~Person()
{

}

string Person::getFname()
{
    return first_name;
}

string Person::getLname()
{
    return last_name;
}

string Person::getEmail()
{
    return email;
}

string Person::getTopic()
{
    return topic;
}

int Person::getID()
{
    return id;
}

int Person::getGroupID()
{
    return group_id;
}

void Person::setFname(string firstName)
{
    first_name = firstName;
}

void Person::setLname(string lastName)
{
    last_name = lastName;
}

void Person::setEmail(string email)
{
    this->email = email;
}

void Person::setTopic(string topic)
{
    this->topic = topic;
}

void Person::setID(int ID)
{
    id = ID;
}

void Person::setGroupID(int groupID)
{
    group_id = groupID;
}
