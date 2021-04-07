#include "board.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <pawn.h>

Board::Board()
{
    mouseWasPressed = false;
    previousClickedCell = NULL;
    clickedCell = NULL;
    connect(this, &Board::secondClick, this, &Board::move);
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (mouseWasPressed)
    {
        clickedCell = &cells[(int(event->scenePos().x() - 39 )/ 90)][(int(event->scenePos().y() - 39 ) / 90)];
        mouseWasPressed = false;
        if (clickedCell != previousClickedCell) {
            emit secondClick();
        }
    }
    else
    {
        previousClickedCell = &cells[(int(event->scenePos().x() - 39 )/ 90)][(int(event->scenePos().y() - 39 ) / 90)];
        mouseWasPressed = true;
    }
}

void Board::drawCells()
{
    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,800,800);
    rect->setBrush(QImage(":/images/board.png").scaled(800,800));
    this->addItem(rect);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            cells[i][j].setX(39 + i*90);
            cells[i][j].setY(39 + j*90);

        }
    }
}

//здесть надо добавить все фигурки, пока что она одна
void Board::addFigures()
{
    for (int i =0; i<8;i++)
    {
        cellsToPieces[&cells[i][1]] = new Pawn(cells[i][1].x(), cells[i][1].y());
        this->addItem(cellsToPieces.value(&cells[i][1]));
    }


}
//проверка возможного хода
void Board::move()
{
   // qDebug() << "Called move" << Qt::endl;
    if (cellsToPieces.contains(previousClickedCell))
    {
        cellsToPieces[previousClickedCell]->setPos(clickedCell->pos());
        cellsToPieces.insert(clickedCell, cellsToPieces[previousClickedCell]);
        cellsToPieces.remove(previousClickedCell);
    }
}

