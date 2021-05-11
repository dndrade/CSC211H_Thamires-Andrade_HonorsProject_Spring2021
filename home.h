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
    bool isMentee = false, isMentor = false;

private slots:
    void on_home_buttom_clicked();

    void on_add_participant_butom_clicked();

    void on_groupPage_buttom_clicked();

    void on_aboutPage_buttom_clicked();

    void on_listView_mentees_doubleClicked(const QModelIndex &index);

    void on_update_participant_data_clicked();

    void on_insert_participant_clicked();

    void on_mentee_role_clicked();

    void on_mentor_role_clicked();

    void on_load_participantList_clicked();

    void on_listView_mentors_doubleClicked(const QModelIndex &index);

    void on_clear_lines_clicked();

    void clearLineEdits();

    void on_delete_selected_clicked();

    void on_listView_mentors_clicked(const QModelIndex &index);

    void on_searchMentor_Button_clicked();

    void on_mentor_searchTerm_textEdited(const QString &arg1);

private:
    Ui::home *ui;
    QSqlDatabase database;
    QSqlQueryModel *querymodel;
    QSqlTableModel *mentorTable;
    QSqlTableModel *menteeTable;
    QSqlTableModel *findMentorTable;
};
#endif // HOME_H
