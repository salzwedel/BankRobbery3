#include "Game.h"
#include "hostage.h"

//extern std::default_random_engine generator;

//set bottom level for vehicle alignment
const int roadlevel=650;
/**
 * @brief Game::Game
 * constructs the Game scene
 */
Game::Game(){

    gameover=false;
    hostagekilled=false;

    initial_badg = 20;
    initial_host = 10;

    badg_remaining = initial_badg;
    host_remaining = initial_host;

    max_badg_onscreen = 5;
    max_host_onscreen = 4;

    scene1 = new QGraphicsScene;
    player = new MyPlayer(this);

    score = new QGraphicsTextItem;
    score->setPlainText(QString("Bank Robbers: ") + QString::number(badguys_remaining()));
    score->setPos(10,10);
    score->setFont(QFont("Arial",18));
    scene1->addItem(score);

    scene1->setSceneRect(0,0,1280,720);
    setScene(scene1);

    //QGraphicsRectItem* boundingrect = new QGraphicsRectItem;
    //boundingrect->setRect(0,0,1200,720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(1280,720);
    //mainLayout->addWidget(mainview);



    QGraphicsRectItem* police1 = new QGraphicsRectItem();
    QGraphicsRectItem* ambulance = new QGraphicsRectItem();
    QGraphicsRectItem* SWAT = new QGraphicsRectItem();
    QGraphicsRectItem* fire = new QGraphicsRectItem();

    QGraphicsPixmapItem* bank = new QGraphicsPixmapItem();


    //*********** CHANGE APPEARANCES OF ITEMS HERE ********************

    //set images
    QPixmap * bank_img = new QPixmap(":/img/BR_bank.gif");



    //sizes of vehicles
    int
            police1_w = 100,
            police1_h = 50,

            ambulance_w = 110,
            ambulance_h = 60,

            SWAT_w = 130,
            SWAT_h = 60,

            fire_w=160,
            fire_h=65;

    //position of vehicles
    int
            police1_x = 600,
            police1_y = roadlevel - police1_h,

            ambulance_x = 200,
            ambulance_y = roadlevel - ambulance_h,

            SWAT_x = 950,
            SWAT_y = roadlevel - SWAT_h,

            fire_x = 400,
            fire_y = roadlevel - fire_h;

    //set  vehicle geometry
    police1  ->setRect(0,0,police1_w,police1_h);
    police1  ->setPos(police1_x,police1_y);
    ambulance->setRect(0,0,ambulance_w,ambulance_h);
    ambulance->setPos(ambulance_x,ambulance_y);
    SWAT     ->setRect(0,0,SWAT_w,SWAT_h);
    SWAT     ->setPos(SWAT_x,SWAT_y);
    fire     ->setRect(0,0,fire_w,fire_h);
    fire     ->setPos(fire_x,fire_y);



    //set other object geometry

    bank->setPixmap(*bank_img);

    //bank->show();

    //add items to the scene
    scene1->addItem(player);
    scene1->addItem(police1);
    scene1->addItem(ambulance);
    scene1->addItem(SWAT);
    scene1->addItem(fire);
    scene1->addItem(bank);

    //set focus to player
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //timer to spawn  badguys
    QTimer* spawn_b_timer = new QTimer;
    connect (spawn_b_timer,SIGNAL(timeout()),this,SLOT(spawn_b()));
    spawn_b_timer->start(90);

    //timer to spawn hostages
    QTimer* spawn_h_timer = new QTimer;
    connect (spawn_h_timer,SIGNAL(timeout()),this,SLOT(spawn_h()));
    spawn_h_timer->start(0);

}

Game::~Game()
{

}

/**
 * @brief spawn_b
 * @spawn a new badguy
 */
void Game::spawn_b(){

    if(badguys_remaining()==0){
        if(gameover==false){
            gameover=true;
            Endings(0 );
        }
        delete this;
    }



    std::bernoulli_distribution p(0.91);
    if (p(generator))
        return;

    //check if a new badguy can be spawned
    if (badguys_remaining() <= badguys_onscreen()){
        return;
    }
    if (badguys_onscreen() >= max_badguys_onscreen()){
        return;
    }

    badguy* newbg = new badguy(this);
    scene1->addItem(newbg);

    //debug code
    qDebug() << "badguys remaining: " << badguys_remaining();
    qDebug() << "badguys onscreen: " << badguys_onscreen();
    qDebug() << "max_badguys_onscreen: " << max_badguys_onscreen();
}



/**
 * @brief spawn_h
 * @spawn a new hostage
 */
void Game::spawn_h(){

    if(hostagekilled==true){
        if(gameover==false){
            gameover=true;
            Endings( 1 );
        }
        delete this;
    }

    std::bernoulli_distribution p(0.95);
    if (p(generator))
        return;

    //check if a new hostage can be spawned
    if (hostages_remaining() <= hostages_onscreen()){
        return;
    }
    if (hostages_onscreen() >= max_hostages_onscreen()){
        return;
    }

    hostage* newh = new hostage(this);
    scene1->addItem(newh);

    //debug code
    qDebug() << "hostages remaining: " << hostages_remaining();
    qDebug() << "hostages onscreen: " << hostages_onscreen();
    qDebug() << "hostages_onscreen: " << max_hostages_onscreen();
}


