#include "chesspiece.h"
#include <QDebug>

ChessPiece::ChessPiece(int x, int y)
{
    this->setX(x);
    this->setY(y);
    this->setPixmap(QPixmap::fromImage(*image).scaled(90,90));
    this->setPos(x, y);
}


