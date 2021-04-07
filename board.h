#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMap>
#include "cell.h"
#include "chesspiece.h"
#include <QMainWindow>

class Board :  public QGraphicsScene
{
    Q_OBJECT
    Cell cells[8][8];
    QMap<Cell*, ChessPiece *> cellsToPieces;
virtual void mousePressEvent(QGraphicsSceneMouseEvent *) override;
public:
    Board();
    Cell * clickedCell;
    Cell * previousClickedCell;
    bool mouseWasPressed;
    void drawCells();
    void addFigures();
public slots:
    void move();
signals:
    void secondClick();
};

#endif // BOARD_H
