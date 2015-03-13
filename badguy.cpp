#include "badguy.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include "game.h"

#include <random>

extern std::default_random_engine generator;

/**
 * @brief badguy::badguy
 * @param g is the parent Game
 */
badguy::badguy(Game* g) {
    game=g;

    //initiate the bad guy image
    badguy_img = new QPixmap;
    badguy_img->load(":/img/badguy.gif");
    //setRect(198-badguy_h, 96, badguy_w, badguy_h);
    setPixmap(badguy_img->scaledToWidth(badguy_w));
    setZValue(-10);

    std::uniform_int_distribution<int> distribution(0,8);

    //pick a zone to spawn
    bool picked = false;
    while (picked==false){
       //randomly pick which zone to spawn in
       //distribution.reset();
       zone = distribution(generator);

       //make sure there is not already a bad guy or hostage in that zone
       if (game->badguy_zones(zone) == false && game->hostage_zones(zone) == false)
            picked = true;
    }

    //update zones list
    game->set_badguys_zones(zone, true);

    //set coordinates depending on which zone
    if (zone==0){
        spawn_y = 102-badguy_h;
        x_min   = 198;
        x_max   = 449;
    }
    if (zone==1){
        spawn_y = 102-badguy_h;
        x_min   = 768;
        x_max   = 1017;
    }
    if (zone==2){
        spawn_y = 132;
        x_min   = 198;
        x_max   = 429;
    }
    if (zone==3){
        spawn_y = 132;
        x_min   = 458;
        x_max   = 757;
    }
    if (zone==4){
        spawn_y = 132;
        x_min   = 788;
        x_max   = 1017;
    }
    if (zone==5){
        spawn_y = 222;
        x_min   = 198;
        x_max   = 429;
    }
    if (zone==6){
        spawn_y = 222;
        x_min   = 788;
        x_max   = 1017;
    }
    if (zone==7){
        spawn_y = 312;
        x_min   = 198;
        x_max   = 429;
    }

    if (zone==8){
        spawn_y = 312;
        x_min   = 788;
        x_max   = 1017;
    }

    //randomly spawn on the left or right of each zone
    std::bernoulli_distribution p(0.5);
    if (p(generator))
        setPos(x_min,spawn_y);
    else
        setPos(x_max,spawn_y);

    //use a timer to move
    QTimer* timer = new QTimer();
    connect (timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

/**
 * @brief badguy::~badguy
 * badguy destructor
 */
badguy::~badguy()
{
    //update zones list
    game->set_badguys_zones(zone, false);
    game->badguy_killed();
    game->score->setPlainText(QString("Bank Robbers: ") + QString::number(game->badguys_remaining() ) );
}

/**
 * @brief badguy::move
 * moves the bad guy left or right within its zone with some randomness
 */
void badguy::move()
{
    {
    //only move one fifth of the time this function is called
    //int maybe = rand() %2;
    //if (maybe != 0)
    //    return;
    }

    //shift value
    int shift=11;

    //randomly move in direction left or right
    double prob;
    if (last_move==0)
        prob = 0.9;
    if (last_move==1)
        prob = 0.1;

    std::bernoulli_distribution p(prob);

    if(p(generator))
        //if already all the way left move right instead
        if (x()-shift<x_min) { setPos(x_min+shift,y()); last_move=1; }
        else                 { setPos(x()-shift,y());   last_move=0; }

    else
        //if already all the way right move left instead
        if (x()+shift>x_max) { setPos(x_max-shift,y()); last_move=0; }
        else                 { setPos(x()+shift,y());   last_move=1; }
}

