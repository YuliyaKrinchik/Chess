#include "chesspiece.h"
#include <QDebug>

bool ChessPiece::figureCanMove(const Cell *start, const Cell *end)
{
    return true;
}

ChessPiece::ChessPiece(int x, int y)
{
    this->setX(x);
    this->setY(y);

    this->setPos(x, y);
}
