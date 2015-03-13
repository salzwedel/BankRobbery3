#include "mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent is the parent widget
 * constructs the intro message window
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    begin = new QPushButton("Play!");

    instructions = new QLabel("Use the arrow keys to move.\nPress Z to shoot.\nEliminate all bad guys to win.\nBe careful not to hit the hostages.");

    layout = new QVBoxLayout;
    layout->addWidget(instructions);
    layout->addWidget(begin);

    central = new QWidget;
    central->setLayout(layout);
    this->setCentralWidget(central);

}

/**
 * @brief MainWindow::setGame
 * @param g points to a Game object
 * opens the game when the start button is clicked
 */
void MainWindow::setGame(Game* g) {
    game = g;

    QObject::connect(begin, SIGNAL(clicked()), game, SLOT(show()));

}





