/*
Thamires Lopes de Andrade
EMPLID: 23949613
CSC 221H-1700 [Spring 2021]
Submitted: May 13th, 2021
Time Stamp: 5:30pm
Prof: Dr. Azhar
*/
#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);

    // Set up the hyperlink from home page
    ui->MakeaThon_Website->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->MakeaThon_Website->setOpenExternalLinks(true);
    ui->MakeaThon_Website->setTextFormat(Qt::RichText);
    ui->MakeaThon_Website->setText("<a href=\"https://tinyurl.com/make-a-thonBMCC\"> Visit Our Website </a>");
    ui->MakeaThon_Website->setStyleSheet("color: white;"
                        "background-color: none;"
                        "selection-color: orange;"
                        "selection-background-color: none;");
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
    ui->pagesWidget->setCurrentIndex(1);
}

void home::on_quit_button_clicked()
{
    QCoreApplication::quit();
}

// End of home.cpp

