#ifndef HOME_H
#define HOME_H

#include <person.h>
#include <mentee.h>
#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
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
    void connectDatabase();
    bool isMentee, isMentor;

private slots:
    void on_add_mentee_clicked();

    void on_add_mentor_clicked();

    void on_groups_buttom_clicked();

    void on_home_buttom_clicked();

    void on_insert_mentee_clicked();

    void on_insert_mentor_clicked();

    void on_load_menteeList_clicked();

    void on_load_mentorList_clicked();

    void on_listView_mentees_doubleClicked(const QModelIndex &index);

    void on_update_mentee_data_clicked();

    void on_insert_participant_clicked();

    void on_mentee_role_clicked();

    void on_mentor_role_clicked();

private:
    Ui::home *ui;
    QSqlDatabase database;
    QSqlQueryModel *querymodel;
};
#endif // HOME_H
