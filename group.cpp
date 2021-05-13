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

//DR.AZHAR/NATHAN --> Currently, it only loads the contents of ONE table from the
//                database. This is due to the FROM statement not being set
//                properly by me. Why? I still need to learn how to get and join
//                the contents of two different tables in SQL. In this case, the
//                mentee and mentor table.


void Group::on_load_groupList_clicked()
{

    //*********************************************
    //         Loads Group 1 Members              *
    //*********************************************
    // declare a query for group 1
    QSqlQueryModel * group = new QSqlQueryModel();

    // Connect to database
    connectToDatabase_Group();

    QSqlQuery* groupList = new QSqlQuery(database);
    groupList->prepare("SELECT firstName FROM mentees WHERE group_id = 1 ");

    // Execute Query
    groupList->exec();
    group->setQuery(*groupList);
    ui->listView_Group1->setModel(group);


    //*********************************************
    //         Loads Group 2 Members              *
    //*********************************************
    // declare a second query for group 2
    QSqlQueryModel * group2 = new QSqlQueryModel();

    QSqlQuery* groupList_2 = new QSqlQuery(database);
    groupList_2->prepare("SELECT firstName FROM mentors WHERE group_id = 2 ");

    // Execute Query
    groupList_2->exec();
    group2->setQuery(*groupList_2);
    ui->listView_Group2->setModel(group2);

    //*********************************************
    //         Loads Group 3 Members              *
    //*********************************************
    // declare a second query for group 3
    QSqlQueryModel * group3 = new QSqlQueryModel();

    QSqlQuery* groupList_3 = new QSqlQuery(database);
    groupList_3->prepare("SELECT firstName FROM mentees WHERE group_id = 3 ");

    // Execute Query
    groupList_3->exec();
    group3->setQuery(*groupList_3);
    ui->listView_Group3->setModel(group3);

    //*********************************************
    //         Loads Group 4 Members              *
    //*********************************************
    // declare a second query for group 4
    QSqlQueryModel * group4 = new QSqlQueryModel();

    QSqlQuery* groupList_4 = new QSqlQuery(database);
    groupList_4->prepare("SELECT firstName FROM mentees WHERE group_id = 4 ");

    // Execute Query
    groupList_4->exec();
    group4->setQuery(*groupList_4);
    ui->listView_Group4->setModel(group4);

    database.close(); // close database
}
// End of group.cpp
