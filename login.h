#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include "home.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_signIn_clicked();

private:
    Ui::Login *ui;
    home *homeWindow;
    QSqlDatabase loginDB;
};

#endif // LOGIN_H
