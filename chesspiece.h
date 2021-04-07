#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QGraphicsPixmapItem>
#include <cell.h>


class ChessPiece : public QGraphicsPixmapItem
{
public:
    virtual bool figureCanMove(const Cell * start, const Cell * end);
    ChessPiece(int x, int y);
};

#endif // CHESSPIECE_H
