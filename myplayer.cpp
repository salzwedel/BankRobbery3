#include "myplayer.h"
#include "game.h"
#include "bullet.h"
#include <QPixmap>

/**
 * @brief MyPlayer::MyPlayer
 * @param g points to the parent Game
 */
MyPlayer::MyPlayer(Game* g)
{
    game=g;

    player_img = new QPixmap;
    player_img->load(":/img/player.gif");
    setPixmap(player_img->scaledToWidth(player_w));
    setPos(player_x,player_y);
    setZValue(1);

    bullet_count=0;

    //movement timer
    QTimer* m_timer = new QTimer();
    connect (m_timer,SIGNAL(timeout()),this,SLOT(move()));
    m_timer->start(move_ms);

    //shooting timer
    QTimer* s_timer = new QTimer();
    connect (s_timer,SIGNAL(timeout()),this,SLOT(shoot()));
    s_timer->start(shoot_ms);

}

MyPlayer::~MyPlayer()
{

}

/**
 * @brief MyPlayer::keyPressEvent
 * @param event is a key press event
 * adds pressed keys to the keys vecctor
 */
void MyPlayer::keyPressEvent(QKeyEvent* event)
{
    int k = event->key();

        keys.insert(k);
}

/**
 * @brief MyPlayer::keyReleaseEvent
 * @param event is a keyReleaseEvent
 * removes released keys from the keys vector
 */
void MyPlayer::keyReleaseEvent(QKeyEvent* event)
{
    keys.erase(event->key());
}
/**
 * @brief MyPlayer::move
 * moves the player
 */
void MyPlayer::move()
{
    setFocus();
    if (keys.count(Qt::Key_Up)==1 && keys.count(Qt::Key_Left)==1){
        setPos(x() - (h_shift/1.41) ,y() - (v_shift/1.41));
    }
    else if (keys.count(Qt::Key_Up)==1 && keys.count(Qt::Key_Right)==1){
        setPos(x() + (h_shift/1.41),y() - (v_shift/1.41));
    }
    else if (keys.count(Qt::Key_Down)==1 && keys.count(Qt::Key_Left)==1){
        setPos(x() - (h_shift/1.41), y() + (v_shift/1.41));
    }
    else if (keys.count(Qt::Key_Down)==1 && keys.count(Qt::Key_Right)==1){
        setPos(x() + (h_shift/1.41),y() + (v_shift/1.41));
    }
    else if (keys.count(Qt::Key_Right)==1){
        setPos(x() + (h_shift),y());
    }
    else if (keys.count(Qt::Key_Left)==1){
        setPos(x() - (h_shift),y());
    }
    else if (keys.count(Qt::Key_Up)==1){
        setPos(x() ,y() - (v_shift));
    }
    else if (keys.count(Qt::Key_Down)==1){
        setPos(x() ,y() + (v_shift));
    }

    //boundary checking
    if ( y() < 0 )
        setPos( x() , 0 );
    if ( y() > 720-player_h )
        setPos( x() , 720-player_h );
    if ( x() < 0 )
        setPos ( 0 , y() );
    if ( x() > 1280-player_w )
        setPos ( 1280-player_w , y() );
}

/**
 * @brief MyPlayer::shoot
 *  shoot bullets
 */
void MyPlayer::shoot(){
    if (keys.count(Qt::Key_Z)==1){
        //qDebug() << "pow";
        Bullet* pow = new Bullet(this);
        scene()->addItem(pow);
    }
}

