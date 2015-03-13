#ifndef HOSTAGE_H
#define HOSTAGE_H


#include <QObject>
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class Game;
/**
 * @class hostage
 * @brief The hostage class creates an object for each hostage on the screen
 */
class hostage : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    hostage(Game* g);
    ~hostage();


private:
    Game* game;
    QPixmap* hostage_img;
    int hostage_w=32;
    int hostage_h=66;

    int spawn_x, spawn_y, x_min, x_max;
    size_t zone;
    int last_move;

signals:

public slots:
    void move();
};

#endif // HOSTAGE_H
