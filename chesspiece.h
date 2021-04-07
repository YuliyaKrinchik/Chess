#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QGraphicsPixmapItem>


class ChessPiece : public QGraphicsPixmapItem
{
public:
    ChessPiece(int x, int y);
};

#endif // CHESSPIECE_H
