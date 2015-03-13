#include "bullet.h"
#include "myplayer.h"
#include "badguy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "hostage.h"

/**
 * @brief Bullet::Bullet
 * @param p points to the player creating the bullet
 */
Bullet::Bullet(MyPlayer* p)
{
    game = p->game;
    player = p;
    setRect(0,0,2,5);
    setPos(player->x()+20,player->y());

    QTimer* timer = new QTimer();
    connect (timer,SIGNAL(timeout()),this,SLOT(move()));

    //speed of bullet
    timer->start(10);
    ++(player->bullet_count);
}

/**
 * @brief Bullet::~Bullet
 * decrements the bullet count
 */
Bullet::~Bullet()
{
    --(player->bullet_count);
}

/**
 * @brief Bullet::is_in_zone
 * @return true if the bullet is in a zone where bad guys or hostages might be present
 */
bool Bullet::is_in_zone()
{
    int x = pos().x(), y = pos().y();
    if ( x>231 && x<428 )
            if( ( y>130 && y<167 ) || ( y>220 && y<257 ) || ( y>310 && y<347 ) )
            return true;
    if ( x>821 && x<1018 )
            if( ( y>130 && y<167 ) || ( y>220 && y<257 ) || ( y>310 && y<347 ) )
            return true;
    if ( x>491 && x<758 )
            if( y>130 && y<167 )
            return true;
    if ( x>197 && x<448 || x>801 && x<1052 )
            if( y<97 )
            return true;



    return false;

}

/**
 * @brief Bullet::move
 * moves the bullet and checks to see if anything was hit
 */
void Bullet::move()
{
    //move bullet
    setPos(x(),y()-10);

    //check if bullet hits a badguy
    if (is_in_zone()){
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for( int i=0, n = colliding_items.size(); i<n; ++i){
            if (typeid(*(colliding_items[i]))==typeid(badguy)){

                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                delete colliding_items[i];
                delete this;

                return;
            }
            if (typeid(*(colliding_items[i]))==typeid(hostage)){
                game->hostage_killed();
            }
        }
        //delete if offscreen
        if(x() < -0 || x() > 1280 || y() < -0 || y() > 720){
            scene()->removeItem(this);
            delete this;
        }
    }


}

