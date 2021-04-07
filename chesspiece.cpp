#include "chesspiece.h"
#include <QDebug>

ChessPiece::ChessPiece(int x, int y)
{
    this->setX(x);
    this->setY(y);

    this->setPos(x, y);
}
