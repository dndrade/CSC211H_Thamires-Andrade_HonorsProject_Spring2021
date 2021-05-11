#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
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

    QString username = ui->username->text();
    QString password = ui->password->text();

    if(loginDB.open())
    {
        QSqlQuery newLogin(QSqlDatabase::database("Login"));
        newLogin.prepare("SELECT * FROM adm");

//        newLogin.bindValue(":username", username);
//        newLogin.bindValue(":password", password);

        if (!newLogin.exec())
        {
            QMessageBox::critical(this, tr("error::"), newLogin.lastError().text());
        }
        else
        {
            while(newLogin.next())
            {
                QString getUsername = newLogin.value(1).toString();
                QString getPassword = newLogin.value(2).toString();

                if (getUsername == username && getPassword == password)
                {
                    loginDB.close();
                    hide();
                    home *homeWindow = new home;
                    homeWindow->show();
                    homeWindow->activateWindow();
                }
                else
                {
                    QMessageBox::information(this, "Fail", "Invalid name and/or password.");
                }
            }
        }
    }


    if(!loginDB.open())
    {
        QMessageBox::critical(this, tr("error::"), loginDB.lastError().text());
    }
}

