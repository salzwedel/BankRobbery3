#include "mainwindow.h"

#include <QHboxLayout>
#include <QVBoxLayout>
#include <QObject>
#include <QPixmap>
#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

#include "myplayer.h"
#include "game.h"
#include <random>
#include <ctime>

std::default_random_engine generator;


Game* game;

int main(int argc, char *argv[])
{
    generator.seed(time(nullptr));
    QApplication a(argc, argv);

    MainWindow* welcome = new MainWindow;

    game = new Game;

    welcome->setGame(game);

    //show the intro window
    welcome->show();

    return a.exec();
}
