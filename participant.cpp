/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#include "participant.h"
#include "ui_participant.h"

Participant::Participant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Participant)
{
    ui->setupUi(this);
}

Participant::~Participant()
{
    delete ui;
}

void Participant::on_participantBack_buttom_clicked()
{
    this->close();
}
// Emits a signal to homeWindow
void Participant::on_participantBack_button_pressed()
{
    emit participantBack_buttomPressed();
}

//******************************************************
//          Open the connection to the database        *
//******************************************************
void Participant::connectDatabase()
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

// Assigns the mentee role to the participant
void Participant::on_mentee_role_clicked()
{
     this->isMentee = true;
     this->isMentor = false;
}
// Assigns the mentor role to the participant
void Participant::on_mentor_role_clicked()
{
    this->isMentor = true;
    this->isMentee = false;
}

//******************************************************************
// When button is clicked, a mentee or mentor will be added to the *
//                       database                                  *
//******************************************************************
void Participant::on_insert_participant_clicked()
{
//    on_mentee_role_clicked();
//    on_mentor_role_clicked();

    // Get placeholder variables
    QString firstName = ui->first_name->text();
    QString lastName = ui->last_name->text();
    QString email = ui->email->text();
    QString topic = ui->topic->currentText();
    QString major = ui->choose_major->currentText();
    QString company = ui->company->text();
    QString group_id = ui->group_id->text();

    // If participant is a mentee, insert them to the mentee table
    if (isMentee == true)
    {
        // Connect to database
        connectDatabase();

        // Run insert Query
        QSqlQuery insert;

        insert.prepare("INSERT INTO mentees(firstName, lastName, email, major, topic, group_id)"
                        "VALUES (:firstName, :lastName, :email, :major, :topic, group_id)");
        insert.bindValue(":firstName", firstName);
        insert.bindValue(":lastName", lastName);
        insert.bindValue(":email", email);
        insert.bindValue(":major", major);
        insert.bindValue(":topic", topic);
        insert.bindValue(":group_id", group_id);

        if(insert.exec())
        {
            QMessageBox::information(this, "Inserted", "Mentee was added successfully.");
        }
        else
        {
            QMessageBox::information(this, "Fail", "Unable to add entry.");
        }

        database.close();
    }
    // If participant is a mentor, insert them to the mentor table
    if (isMentor==true)
    {
        // Connect to database
        connectDatabase();

        // Run insert Query
        QSqlQuery insert;

        insert.prepare("INSERT INTO mentors(firstname, lastname, email, company, topic, group_id)"
                        "VALUES (:firstName, :lastName, :email, :company, :topic, group_id)");
        insert.bindValue(":firstName", firstName);
        insert.bindValue(":lastName", lastName);
        insert.bindValue(":email", email);
        insert.bindValue(":company", company);
        insert.bindValue(":topic", topic);
        insert.bindValue(":group_id", group_id);

        if(insert.exec())
        {
            QMessageBox::information(this, "Inserted", "Mentor was added successfully.");
        }
        else
        {
            QMessageBox::information(this, "Fail", "Unable to add entry.");
        }

        database.close();
    }
}

// This function will display a list of current participants
void Participant::on_load_participantList_clicked()
{
    //*********************************************
    //         Loads a list of mentees             *
    //*********************************************
    // declare a query for mentees
    QSqlQueryModel * modal = new QSqlQueryModel();

    // Connect to database
    connectDatabase();

    QSqlQuery* menteeList = new QSqlQuery(database);
    menteeList->prepare("SELECT firstName,lastName AS Name FROM mentees");

    // Execute Query
    menteeList->exec();
    modal->setQuery(*menteeList);
    ui->listView_mentees->setModel(modal);


    //*********************************************
    //         Loads a list of mentors             *
    //*********************************************
    // declare a second query for mentors
    QSqlQueryModel * modal2 = new QSqlQueryModel();

    QSqlQuery* mentorList = new QSqlQuery(database);
    mentorList->prepare("SELECT firstName,lastName AS Name FROM mentors");

    // Execute Query
    mentorList->exec();
    modal2->setQuery(*mentorList);
    ui->listView_mentors->setModel(modal2);

    database.close(); // close database
}

//************************************************************************
// When a participant name is double clicked, MENTEE DATA is displayed   *
//************************************************************************
void Participant::on_listView_mentees_doubleClicked(const QModelIndex &index)
{
    // Get user data from list, assign to a variable
    QString menteeDataDisplay = ui->listView_mentees->model()->data(index).toString();
    // Connect to database
    connectDatabase();
    // Create and execute query
    QSqlQuery menteeDisplayQuery;
    menteeDisplayQuery.prepare("SELECT * FROM mentees WHERE firstName='"+menteeDataDisplay+"' or "
"                               lastName='"+menteeDataDisplay+"' or email='"+menteeDataDisplay+"' or "
"                               major='"+menteeDataDisplay+"' or topic='"+menteeDataDisplay+"' or"
"                               group_id='"+menteeDataDisplay+"'");

    if(menteeDisplayQuery.exec())
    {
        while(menteeDisplayQuery.next())
        {
            ui->first_name->setText(menteeDisplayQuery.value(1).toString());
            ui->last_name->setText(menteeDisplayQuery.value(2).toString());
            ui->email->setText(menteeDisplayQuery.value(3).toString());
            ui->choose_major->setCurrentText(menteeDisplayQuery.value(4).toString());
            ui->topic->setCurrentText(menteeDisplayQuery.value(5).toString());
            ui->group_id->setText(menteeDisplayQuery.value(6).toString());
        }
        database.close();
    }
    else
    {
        QMessageBox::critical(this, tr("error::"), menteeDisplayQuery.lastError().text());
    }
}

//************************************************************************
// When a participant name is double clicked, MENTOR DATA is displayed   *
//************************************************************************
void Participant::on_listView_mentors_doubleClicked(const QModelIndex &index)
{
    QString mentorDataDisplay = ui->listView_mentees->model()->data(index).toString();
    // Connect to database
    connectDatabase();
    // Create and execute query
    QSqlQuery mentorDisplayQuery;
    mentorDisplayQuery.prepare("SELECT * FROM mentors WHERE firstName='"+mentorDataDisplay+"' or "
"                               lastName='"+mentorDataDisplay+"' or email='"+mentorDataDisplay+"' or "
"                               company='"+mentorDataDisplay+"' or topic='"+mentorDataDisplay+"' or"
"                               group_id='"+mentorDataDisplay+"'");

    if(mentorDisplayQuery.exec())
    {
        while(mentorDisplayQuery.next())
        {
            ui->first_name->setText(mentorDisplayQuery.value(1).toString());
            ui->last_name->setText(mentorDisplayQuery.value(2).toString());
            ui->email->setText(mentorDisplayQuery.value(3).toString());
            ui->company->setText(mentorDisplayQuery.value(4).toString());
            ui->topic->setCurrentText(mentorDisplayQuery.value(5).toString());
            ui->group_id->setText(mentorDisplayQuery.value(6).toString());
        }
        //database.close();
    }
    else
    {
        QMessageBox::critical(this, tr("error::"), mentorDisplayQuery.lastError().text());
    }
}

void Participant::on_update_participant_data_clicked()
{
    on_mentee_role_clicked();

    // Set placeholder variables
    QString firstName = ui->first_name->text();
    QString lastName = ui->last_name->text();
    QString email = ui->email->text();
    QString topic = ui->topic->currentText();
    QString major = ui->choose_major->currentText();
    QString company = ui->company->text();
    QString group_id = ui->group_id->text();



    if (isMentee == true)
    {
        // Connect to database
        connectDatabase();
        // Run editMentee Query
        QSqlQuery editMentee;
        editMentee.prepare("UPDATE mentees SET firstName='"+firstName+"',"
    "                               lastName='"+lastName+"', email='"+email+"',"
    "                               major='"+major+"', topic='"+topic+"',"
    "                               group_id='"+group_id+"' WHERE firstName='"+firstName+"'");

        if(editMentee.exec())
        {
            QMessageBox::information(this, "Success", "Mentee data has been updated.");
            database.close();
        }
        else
        {
            QMessageBox::critical(this, tr("error::"), editMentee.lastError().text());
        }
    }
     if(isMentor == true)
     {
         // Connect to database
         connectDatabase();
         // Run editMentee Query
         QSqlQuery editMentor;
         editMentor.prepare("UPDATE mentors SET firstName='"+firstName+"',"
     "                               lastName='"+lastName+"', email='"+email+"',"
     "                               company='"+company+"', topic='"+topic+"',"
     "                               group_id='"+group_id+"' WHERE firstName='"+firstName+"'");

         if(editMentor.exec())
         {
             QMessageBox::information(this, "Success", "Mentor data has been updated.");
             database.close();
         }
         else
         {
             QMessageBox::critical(this, tr("error::"), editMentor.lastError().text());
         }
     }
}
// This function will clear the line edits
void Participant::on_clear_lines_clicked()
{
    ui->first_name->clear();
    ui->last_name->clear();
    ui->email->clear();
    ui->group_id->clear();
    ui->company->clear();
}

// Clear line edits without pressing a buttom
void Participant::clearLineEdits()
{
    ui->first_name->clear();
    ui->last_name->clear();
    ui->email->clear();
    ui->group_id->clear();
    ui->company->clear();
}

// Function to delete user needed
void Participant::on_delete_selected_clicked()
{
    on_mentee_role_clicked();

    // Set placeholder variables
    QString firstName = ui->first_name->text();

    if (isMentee == true)
    {
        // Connect to database
        connectDatabase();
        // Run editMentee Query
        QSqlQuery deleteMentee;
        deleteMentee.prepare("DELETE FROM mentees WHERE firstName='"+firstName+"'");

        if(deleteMentee.exec())
        {
            QMessageBox::information(this, "Success", "Mentee has been deleted.");
            database.close();
            clearLineEdits();
        }
        else
        {
            QMessageBox::critical(this, tr("error::"), deleteMentee.lastError().text());
        }
    }
     if(isMentor == true)
     {
         // Connect to database
         connectDatabase();
         // Run editMentee Query
         QSqlQuery deleteMentor;
         deleteMentor.prepare("DELETE FROM mentors WHERE firstName='"+firstName+"'");

         if(deleteMentor.exec())
         {
             QMessageBox::information(this, "Success", "Mentor has been deleted.");
             database.close();
             clearLineEdits();
         }
         else
         {
             QMessageBox::critical(this, tr("error::"), deleteMentor.lastError().text());
         }
     }
}
