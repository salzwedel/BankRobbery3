#ifndef BADGUY_H
#define BADGUY_H

#include <QObject>
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class Game;
/**
 * @class badguy
 * @brief The badguy class creates an object for each badguy on the screen
 */
class badguy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    badguy(Game* g);
    ~badguy();


private:
    Game* game;
    QPixmap* badguy_img;
    int badguy_w=32;
    int badguy_h=66;

    int spawn_x, spawn_y, x_min, x_max;
    size_t zone;
    int last_move;

signals:

public slots:
    void move();
};

#endif // BADGUY_H
