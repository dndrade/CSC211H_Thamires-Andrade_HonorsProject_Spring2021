/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <home.h>
//**************************************************
//  This class acepts a username and password and  *
//   compares with data stored inside a database   *
//**************************************************
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase loginDB;
};

#endif // LOGIN_H
