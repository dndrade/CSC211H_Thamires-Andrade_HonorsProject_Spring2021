#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);
}

home::~home()
{
    delete ui;
}

// When buttoon is clicked, program returns to home page
void home::on_homePage_buttom_clicked()
{
    ui->pagesWidget->setCurrentIndex(0);
}

// When buttoon is clicked, program goes to add participant page
void home::on_participantPage_buttom_clicked()
{
    hide();                                     // hide home window
    participantWindow = new Participant();     // declare a new participantWindow object
    participantWindow->show();                 // display window
    participantWindow->activateWindow();       // Sets the participant window as the active window.

    // Connect both instances by having participantWindow sending a signal
    // when "back" buttom is pressed, participantWindow calls viewWindow function
    connect(participantWindow, SIGNAL(participantBack_buttomPressed()), this, SLOT(backFromParticipant_ViewWindow()));
}

// When buttoon is clicked, program gois to group page
void home::on_groupPage_buttom_clicked()
{
    hide();                             // hide home window
    groupWindow = new Group();        // declare a new groupWindow object
    groupWindow->show();                 // display window
    groupWindow->activateWindow();       // Sets the group window as the active window.

    // Connect both instances by having groupWindow sending a signal
    // when "back" buttom is pressed, homeWindow calls viewWindow function
    connect(groupWindow, SIGNAL(groupBack_buttonPressed()), this, SLOT(backFromGroup_ViewWindow()));

}

// Shows and sets homeWindow as the active Window
void home::backFromGroup_ViewWindow()
{
    groupWindow->close();
    this->show();
    this->activateWindow();
}

void home::backFromParticipant_ViewWindow()
{
    participantWindow->close();
    this->show();
    this->activateWindow();
}

// When buttoon is clicked, program gois to about page
void home::on_aboutPage_buttom_clicked()
{
    ui->pagesWidget->setCurrentIndex(2);
}



////doesnt work
//void home::on_searchMentor_Button_clicked()
//{
//    QString mentorKeyword = ui->mentor_searchTerm->text();
//    //mentorTable->setTable("mentors");
//    findMentorTable->setFilter("SELECT FROM mentors firstName, lastName, topic, group WHERE firstName='"+mentorKeyword+"' or "
//"                               lastName='"+mentorKeyword+"' or topic='"+mentorKeyword+"'");

//    //findMentorTable->setTable("mentors");
//    //findMentorTable->select();
//    //ui->mentorTable_group->show();
//}

////*****************************************************
////         Filters a list of mentees by group_id      *
////*****************************************************

//void home::on_comboBox_activated(int index)
//{
//    QString currentIndex = QVariant(index).toString();
//    // declare a query for mentees
//    QSqlQueryModel * groupMembers = new QSqlQueryModel();

//    // Connect to database
//    connectDatabase();

//    QSqlQuery* groupList = new QSqlQuery(database);
//    groupList->prepare("SELECT firstName FROM mentees WHERE group_id='"+currentIndex+"'");
////    groupList->prepare("SELECT firstName FROM mentors WHERE group_id='"+currentIndex+"'");
////    groupList->prepare("SELECT mentors.firstName mentees.firstName "
////                    "FROM mentees,mentors WHERE group_id='"+currentIndex+"' "
////                     "AND mentors.group_id = mentees.group_id");

//    // Execute Query
//    groupList->exec();
//    groupMembers->setQuery(* groupList);
//    ui->groupMembersList->setModel(groupMembers);
//}




