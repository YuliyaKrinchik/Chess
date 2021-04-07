#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QWidget>
#include <QGraphicsPixmapItem>


class ChessPiece : public QGraphicsPixmapItem
{
    QImage *image = new QImage(":/images/pawn-white.png");

public:
    ChessPiece(int x, int y);
};

#endif // CHESSPIECE_H
