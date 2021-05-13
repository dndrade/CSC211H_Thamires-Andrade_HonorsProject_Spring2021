/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#ifndef GROUP_H
#define GROUP_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class Group;
}

class Group : public QDialog
{
    Q_OBJECT

public:
    explicit Group(QWidget *parent = nullptr);
    ~Group();

private slots:
    void connectToDatabase_Group();

    void on_groupBack_button_clicked();

    void on_groupBack_button_pressed();

    void on_load_groupList_clicked();

signals:
    void groupBack_buttonPressed();

private:
    Ui::Group *ui;
    QSqlDatabase database;

};

#endif // GROUP_H
