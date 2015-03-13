#ifndef GAME_H
#define GAME_H


#include <QObject>
#include <QPixmap>
#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QTimer>
#include <bitset>
#include "badguy.h"
#include <random>
#include "myplayer.h"
#include <QDebug>
#include <QGraphicsTextItem>
#include "endings.h"


extern std::default_random_engine generator;

class badguy;
//class MyPlayer;



/**
 * @class Game
 * @brief The Game class inherits from QGraphics view and builds the scene
 */
class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    ~Game();

    QGraphicsScene* scene1;
    MyPlayer* player;    
    QGraphicsTextItem* score;

    //getters
    /**
     * @brief badguys_remaining
     * @return the number of badguys remaining
     */
    int badguys_remaining()       { return badg_remaining;    }
    /**
     * @brief badguys_onscreen
     * @return the number of badguys currently on the screen
     */
    size_t badguys_onscreen()     { return badg_zones.count();}
    /**
     * @brief max_badguys_onscreen
     * @return the maximum of badguys to be shown
     */
    int max_badguys_onscreen()    { return max_badg_onscreen; }
    /**
     * @brief badguy_zones
     * @param n is which zone to check
     * @return returns true if there is a badguy in the nth zone
     */
    bool badguy_zones(int n)      { return badg_zones[n];     }

    /**
     * @brief hostages_remaining
     * @return number of hostages remaining
     */
    int hostages_remaining()      { return host_remaining;    }
    /**
     * @brief hostages_onscreen
     * @return number hostages shown on the screen
     */
    size_t hostages_onscreen()    { return host_zones.count();}
    /**
     * @brief max_hostages_onscreen
     * @return max number of hostages shown on screen
     */
    int max_hostages_onscreen()   { return max_host_onscreen; }
    /**
     * @brief hostage_zones
     * @param n checks the nth zone
     * @return true if there is a hostage in the nth zone
     */
    bool hostage_zones(int n)     { return host_zones[n];     }

    //setters
    /**
     * @brief badguy_killed
     * decrements the number of badguys remaining
     */
    void badguy_killed()                       { badg_remaining--;  }
    /**
     * @brief set_badguys_zones
     * @param p is the pth zone
     * @param b is true or false
     * sets true or false when a a badguy is added to or removed from a zone
     */
    void set_badguys_zones (size_t p, bool b)  { badg_zones[p] = b; }

    /**
     * @brief hostage_killed
     * sets flag true when a hostage is killed
     */
    void hostage_killed()                      { hostagekilled=true;}
    /**
     * @brief set_hostages_zones
     * @param p is the pth zone
     * @param b is true or false
     * sets true or false when a a hostage is added to or removed from a zone
     */
    void set_hostages_zones (size_t p, bool b) { host_zones[p] = b; }


private:

    int initial_badg;
    int initial_host;

    int host_remaining;
    int badg_remaining;

    //int badg_onscreen;
    //int host_onscreen;

    int max_badg_onscreen;
    int max_host_onscreen;

    std::bitset<16> badg_zones;
    std::bitset<16> host_zones;

    bool gameover;
    bool hostagekilled;


public slots:
    void spawn_b();
    void spawn_h();

};


#endif // GAME_H
