#include "endings.h"
#include "game.h"

/**
 * @brief Endings::Endings
 * @param type is 0 if win, 1 if lose from hostage killed, 2 if lose from player killed
 */
Endings::Endings(int type)
{
    message = new QLabel;

    endWidget = new QWidget;
    endWidget->setStyleSheet("background-color:#ffffff");
    if (type==0)
        message->setText("<font size='20'><b>You saved the hostages!\nYou're a hero!</b></font>");
    if (type==1)
        message->setText("<font size='20'><b>You killed a hostage!\nHow can you live with yourself?</b></font>");
    if (type==2)
        message->setText("<font size='20'><b>You died.\nR.I.P.</b></font>");

    quit = new QPushButton("QUIT");



    layout = new QVBoxLayout;
    layout->addWidget(message);
    //layout->addWidget(quit);

    endWidget->setLayout(layout);

    endWidget->show();


    //QObject::connect(quit,SIGNAL(clicked()), this,SLOT(close()));

}

Endings::~Endings()
{

}

