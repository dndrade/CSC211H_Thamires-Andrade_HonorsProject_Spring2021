#ifndef PERSON_H
#define PERSON_H

#include <QSharedDataPointer>
#include <iostream>
using namespace std;

class PersonData;

class Person
{
public:
    Person();
    ~Person();

    string getFname();
    string getLname();
    string getEmail();
    string getTopic();
    int getID();
    int getGroupID();

    void setFname(string firstName);
    void setLname(string lastName);
    void setEmail(string email);
    void setTopic(string topic);
    void setID(int ID);
    void setGroupID(int groupID);


private:
    string first_name, last_name, email, topic;
    int id, group_id;
};

#endif // PERSON_H
