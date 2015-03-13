#include "score.h"
#include "game.h"

Score::Score()
{

}

Score::Score(Game *g)
{
    setPlainText("Bank Robbers Remaining: " + g->badguys_remaining());
}

Score::~Score()
{

}

