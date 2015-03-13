#ifndef ENDINGS_H
#define ENDINGS_H

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>

class Game;

class Endings : public QObject
{
    Q_OBJECT
public:
    Endings(int type);
    ~Endings();

private:
    QLabel* message;
    QWidget* endWidget;
    QVBoxLayout* layout;
    QPushButton* quit;


};

#endif // ENDINGS_H
