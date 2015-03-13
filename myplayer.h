#ifndef MYPLAYER_H
#define MYPLAYER_H


#include <QGraphicsRectItem>
#include <unordered_set>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
//#include "game.h"
#include <QKeyEvent>
#include <QWidget>
//#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "badguy.h"
#include <bitset>
#include <QPixmap>
#include <QGraphicsPixmapItem>

extern const int roadlevel;
class Game;

class MyPlayer : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    friend class Bullet;
public:
    MyPlayer(Game* g);
    ~MyPlayer();

    void keyPressEvent   (QKeyEvent*);
    void keyReleaseEvent (QKeyEvent*);


private:
    Game* game;

    QPixmap* player_img;

    std::unordered_set<int> keys;

    //movement speed
    int h_shift = 3;
    int v_shift = 0;
    int move_ms = 10;

    //shooting parameters
    int shoot_ms = 100; //firing speed
    int max_bullets=6;
    int bullet_count;

    //player size and initial coordinates
    const int
            player_w = 32,
            player_h = 66,
            player_x = 500,
            player_y = roadlevel+10-player_h;


    //void shot_timer();

public slots:
    void move();
    void shoot();
};

#endif // MYPLAYER_H
