#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
class Game;

class Score : public QGraphicsTextItem{
public:
    Score(Game* g);
    ~Score();
};

#endif // SCORE_H
