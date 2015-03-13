#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "game.h"
#include <QWidget>

class Game;

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

     public slots:

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow(){};
        void setGame(Game* g);

    private:

        Game* game;
        QPushButton* begin;
        QLabel* instructions;

        QVBoxLayout* layout;

        QWidget* central;

};


#endif // MAINWINDOW_H
