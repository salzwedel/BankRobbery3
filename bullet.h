#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include "myplayer.h"

class Game;


class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bullet(MyPlayer*);
    ~Bullet();

private:
    Game* game;
    bool is_in_zone();
    MyPlayer* player;

public slots:
    void move();
};

#endif // BULLET_H
