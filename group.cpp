#include "group.h"
#include "ui_group.h"

Group::Group(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Group)
{
    ui->setupUi(this);
}

Group::~Group()
{
    delete ui;
}

void Group::on_groupBack_button_clicked()
{
    this->close();
}

void Group::on_groupBack_button_pressed()
{
    emit groupBack_buttonPressed();
}


//void home::on_load_groupTables_clicked()
//{
//    //***********************************************
//    //     Load the group page tables with data     *
//    //        (can be edited in the tables)         *
//    //***********************************************

//    // Connect to database
//    connectDatabase();

//    // declare and set table of mentors
//    mentorTable = new QSqlTableModel();
//    mentorTable->setTable("mentors");
//    mentorTable->select();

//    // Specify the columns to be shown
//    ui->mentorTable_group->setModel(mentorTable);
//    ui->mentorTable_group->setColumnHidden(0, true);
//    ui->mentorTable_group->setColumnHidden(3, true);
//    ui->mentorTable_group->setColumnHidden(4, true);

//    // Change the column headers
//    mentorTable->setHeaderData(1, Qt::Horizontal, tr("Name"));
//    mentorTable->setHeaderData(2, Qt::Horizontal, tr("Surname"));
//    mentorTable->setHeaderData(5, Qt::Horizontal, tr("Topic"));
//    mentorTable->setHeaderData(6, Qt::Horizontal, tr("Group"));

//    // declare and set table of mentees
//    menteeTable = new QSqlTableModel();
//    menteeTable->setTable("mentees");
//    menteeTable->select();

//    // Specify the columns to be shown
//    ui->menteeTable_group->setModel(menteeTable);
//    ui->menteeTable_group->setColumnHidden(0, true);
//    ui->menteeTable_group->setColumnHidden(3, true);
//    ui->menteeTable_group->setColumnHidden(4, true);

//    // Change the column headers
//    menteeTable->setHeaderData(1, Qt::Horizontal, tr("Name"));
//    menteeTable->setHeaderData(2, Qt::Horizontal, tr("Surname"));
//    menteeTable->setHeaderData(5, Qt::Horizontal, tr("Topic"));
//    menteeTable->setHeaderData(6, Qt::Horizontal, tr("Group"));
//}

