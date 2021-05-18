/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#ifndef HOME_H
#define HOME_H

#include <group.h>
#include <participant.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class home; }
QT_END_NAMESPACE

class home : public QMainWindow
{
    Q_OBJECT

public:
    home(QWidget *parent = nullptr);
    ~home();


private slots:
    void on_homePage_buttom_clicked();

    void on_participantPage_buttom_clicked();

    void on_groupPage_buttom_clicked();

    void on_aboutPage_buttom_clicked();

    void backFromGroup_ViewWindow();

    void backFromParticipant_ViewWindow();

    void on_quit_button_clicked();

private:
    Ui::home *ui;

    QSqlTableModel *findMentorTable;

    Group* groupWindow;

    Participant* participantWindow;

};
#endif // HOME_H
