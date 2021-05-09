#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);
}

home::~home()
{
    delete ui;
}

void home::connectDatabase()
{
    // connecting to MYsql Database
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("honors_app");
    database.setPort(3306);
    database.exec();

    if(!database.open())
    {
        QMessageBox::critical(this, tr("error::"), database.lastError().text());
    }
}

// When buttoon is clicked, program returns to home page
void home::on_home_buttom_clicked()
{
    ui->pagesWidget->setCurrentIndex(0);
}

// When buttoon is clicked, program gois to add mentee page
void home::on_add_mentee_clicked()
{
    ui->pagesWidget->setCurrentIndex(1);
}

// When buttoon is clicked, program gois to add mentor page
void home::on_add_mentor_clicked()
{
    ui->pagesWidget->setCurrentIndex(2);
}

// When buttoon is clicked, program gois to group page
void home::on_groups_buttom_clicked()
{
    ui->pagesWidget->setCurrentIndex(3);
}

// When buttoon is clicked, a mentee is added to database
void home::on_insert_mentee_clicked()
{
    // Connect to database
    connectDatabase();

    // Get placeholder variables
    QString firstName = ui->first_name->text();
    QString lastName = ui->last_name->text();
    QString email = ui->email->text();
    QString topic = ui->topic->currentText();
    QString major = ui->choose_major->currentText();
    QString group_id = ui->group_id->text();

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

// When buttoon is clicked, a mentor is added to database
void home::on_insert_mentor_clicked()
{
    // Connect to database
    connectDatabase();

    // Get placeholder variables
    QString firstname = ui->first_name_3->text();
    QString lastname = ui->last_name_3->text();
    QString email = ui->email_3->text();
    QString topic = ui->topic_2->currentText();
    QString company = ui->company->text();
    QString group_id = ui->group_id_3->text();

    // Run insert Query
    QSqlQuery insert;

    insert.prepare("INSERT INTO mentors(firstname, lastname, email, company, topic, group_id)"
                    "VALUES (:firstName, :lastName, :email, :company, :topic, group_id)");
    insert.bindValue(":firstName", firstname);
    insert.bindValue(":lastName", lastname);
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
// When buttoon is clicked, the current mentees are listed
void home::on_load_menteeList_clicked()
{

    QSqlQueryModel * modal = new QSqlQueryModel();
    // Connect to database
    connectDatabase();
    QSqlQuery* menteeList = new QSqlQuery(database);
    menteeList->prepare("SELECT firstName,lastName AS Name FROM mentees");

    // Execute Query
    menteeList->exec();
    modal->setQuery(*menteeList);
    ui->listView_mentees->setModel(modal);

    database.close();

}

// When buttoon is clicked, the current mentors are listed
void home::on_load_mentorList_clicked()
{
    QSqlQueryModel * modal2 = new QSqlQueryModel();
    // Connect to database
    connectDatabase();
    QSqlQuery* mentorList = new QSqlQuery(database);
    mentorList->prepare("SELECT firstName,lastName AS Name FROM mentors");

    // Execute Query
    mentorList->exec();
    modal2->setQuery(*mentorList);
    ui->listView_mentors->setModel(modal2);

    database.close();
}


void home::on_listView_mentees_doubleClicked(const QModelIndex &index)
{
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


void home::on_update_mentee_data_clicked()
{
    // Get placeholder variables
    QString firstName = ui->first_name->text();
    QString lastName = ui->last_name->text();
    QString email = ui->email->text();
    QString topic = ui->topic->currentText();
    QString major = ui->choose_major->currentText();
    QString group_id = ui->group_id->text();

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



void home::on_insert_participant_clicked()
{
    on_mentee_role_clicked();
    if (isMentee == true)
    {
        // Connect to database
        connectDatabase();

        // Get placeholder variables
        QString firstName = ui->first_name->text();
        QString lastName = ui->last_name->text();
        QString email = ui->email->text();
        QString topic = ui->topic->currentText();
        QString major = ui->choose_major->currentText();
        QString group_id = ui->group_id->text();

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

    if (isMentor==true)
    {
        // Connect to database
        connectDatabase();

        // Get placeholder variables
        QString firstname = ui->first_name_3->text();
        QString lastname = ui->last_name_3->text();
        QString email = ui->email_3->text();
        QString topic = ui->topic_2->currentText();
        QString company = ui->company->text();
        QString group_id = ui->group_id_3->text();

        // Run insert Query
        QSqlQuery insert;

        insert.prepare("INSERT INTO mentors(firstname, lastname, email, company, topic, group_id)"
                        "VALUES (:firstName, :lastName, :email, :company, :topic, group_id)");
        insert.bindValue(":firstName", firstname);
        insert.bindValue(":lastName", lastname);
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
    else
    {
        QMessageBox::information(this, "Fail", "No role was selected.");
    }
}

void home::on_mentee_role_clicked()
{
        this->isMentee = true;
}


void home::on_mentor_role_clicked()
{
    this->isMentor = true;
}

