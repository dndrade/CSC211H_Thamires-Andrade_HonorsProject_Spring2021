/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->username->setPlaceholderText("Username");
    ui->password->setPlaceholderText("Password");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    // connecting to MYsql Database
    loginDB = QSqlDatabase::addDatabase("QMYSQL", "Login");
    loginDB.setHostName("127.0.0.1");
    loginDB.setUserName("root");
    loginDB.setPassword("");
    loginDB.setDatabaseName("honors_app");
    loginDB.setPort(3306);
    loginDB.exec();

    // Get input from line edits
    QString username = ui->username->text();
    QString password = ui->password->text();

    // If database is not open, display the error.
    if(!loginDB.open())
    {
        QMessageBox::critical(this, tr("error::"), loginDB.lastError().text());
    }
    else
    {
        // Declare and prepare a new query
        QSqlQuery newLogin(QSqlDatabase::database("Login"));
        newLogin.prepare("SELECT * FROM adm");

//        newLogin.bindValue(":username", username);
//        newLogin.bindValue(":password", password);

        // Check connection
        if (!newLogin.exec())
        {
            QMessageBox::critical(this, tr("error::"), newLogin.lastError().text());
        }
        else
        {
            // While loope to find a user that matches the input
            while(newLogin.next())
            {
                QString getUsername = newLogin.value(1).toString();
                QString getPassword = newLogin.value(2).toString();


                // Check input STARTING HERE
                if ((getUsername != username) || (getPassword != password))
                {
                    QMessageBox::information(this, "Fail", "Invalid name and/or password.");
                } // UNTIL HERE -->> It's malfunctioning. The error message executes evef with the
                //                   correct login info.

                // Compare input from user and stored data in database
                else /*(getUsername == username && getPassword == password)*/
                {
                    hide();                             // hide login window
                    home *homeWindow = new home;        // declare a new home window object
                    homeWindow->show();                 // display window
                    homeWindow->activateWindow();       // Sets the home window as the active window.
                    loginDB.close();                    // closes connection to database
                }

            }
        }
    }
}
// End of login.cpp
