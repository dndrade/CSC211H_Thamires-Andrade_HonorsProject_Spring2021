#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class Participant;
}

class Participant : public QDialog
{
    Q_OBJECT

public:
    explicit Participant(QWidget *parent = nullptr);
    ~Participant();
    void connectDatabase();
    bool isMentee = false, isMentor = false;

private slots:
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

    void on_participantBack_buttom_clicked();

    void on_participantBack_button_pressed();

signals:
    void participantBack_buttomPressed();


private:
    Ui::Participant *ui;
    QSqlDatabase database;

    QSqlQueryModel *querymodel;

    QSqlTableModel *mentorTable;
    QSqlTableModel *menteeTable;
};

#endif // PARTICIPANT_H
