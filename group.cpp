/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#include "group.h"
#include "ui_group.h"

Group::Group(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Group)
{
    ui->setupUi(this);
}

Group::~Group()
{
    delete ui;
}

void Group::on_groupBack_button_clicked()
{
    this->close();
}
// Emits a signal to homeWindow
void Group::on_groupBack_button_pressed()
{
    emit groupBack_buttonPressed();
}

void Group::connectToDatabase_Group()
{
    // connecting to MYsql Database
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("honors_app");
    database.setPort(3306);
    database.exec();

    // Check for any errors if it doesn't open
    if(!database.open())
    {
        QMessageBox::critical(this, tr("error::"), database.lastError().text());
    }
}
//******************************************************************************
//    This function will load the tables with its respective group members     *
//******************************************************************************

void Group::on_load_groupList_clicked()
{
    // declare a query for group 1
    QSqlQueryModel * group = new QSqlQueryModel();
    QSqlQueryModel * mentors1 = new QSqlQueryModel();
    // declare a second query for group 2
    QSqlQueryModel * group2 = new QSqlQueryModel();
    QSqlQueryModel * mentors2 = new QSqlQueryModel();

    // declare a second query for group 3
    QSqlQueryModel * group3 = new QSqlQueryModel();
    QSqlQueryModel * mentors3 = new QSqlQueryModel();

    // declare a second query for group 4
    QSqlQueryModel * group4 = new QSqlQueryModel();
    QSqlQueryModel * mentors4 = new QSqlQueryModel();

    // Connect to database
    connectToDatabase_Group();

    QSqlQuery* groupList = new QSqlQuery(database);
    QSqlQuery* group_mentors1 = new QSqlQuery(database);

    QSqlQuery* groupList_2 = new QSqlQuery(database);
    QSqlQuery* group_mentors2 = new QSqlQuery(database);

    QSqlQuery* groupList_3 = new QSqlQuery(database);
    QSqlQuery* group_mentors3 = new QSqlQuery(database);

    QSqlQuery* groupList_4 = new QSqlQuery(database);
    QSqlQuery* group_mentors4 = new QSqlQuery(database);

    // Prepare the data to be shown in the tables
    groupList->prepare("SELECT firstName FROM mentees WHERE group_id = 1");
    group_mentors1->prepare("SELECT firstName FROM mentors WHERE group_id = 1");

    groupList_2->prepare("SELECT firstName FROM mentees WHERE group_id = 2");
    group_mentors2->prepare("SELECT firstName FROM mentors WHERE group_id = 2");

    groupList_3->prepare("SELECT firstName FROM mentees WHERE group_id = 3");
    group_mentors3->prepare("SELECT firstName FROM mentors WHERE group_id = 3");

    groupList_4->prepare("SELECT firstName FROM mentees WHERE group_id = 4");
    group_mentors4->prepare("SELECT firstName FROM mentors WHERE group_id = 4");

    // Execute and display queries for each group
    groupList->exec();
    group_mentors1->exec();

    groupList_2->exec();
    group_mentors2->exec();

    groupList_3->exec();
    group_mentors3->exec();

    groupList_4->exec();
    group_mentors4->exec();

    group->setQuery(*groupList);
    mentors1->setQuery(*group_mentors1);

    group2->setQuery(*groupList_2);
    mentors2->setQuery(*group_mentors2);

    group3->setQuery(*groupList_3);
    mentors3->setQuery(*group_mentors3);

    group4->setQuery(*groupList_4);
    mentors4->setQuery(*group_mentors4);

    ui->listView_Group1->setModel(group);
    ui->mentor_Group1->setModel(mentors1);

    ui->listView_Group2->setModel(group2);
    ui->mentor_Group2->setModel(mentors2);

    ui->listView_Group3->setModel(group3);
    ui->mentor_Group3->setModel(mentors3);

    ui->listView_Group4->setModel(group4);
    ui->mentor_Group4->setModel(mentors4);

    database.close(); // close database
}
// End of group.cpp
