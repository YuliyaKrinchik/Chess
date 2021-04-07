#include "board.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

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
            //previousClickedCell->
            emit secondClick();
        }
    }
    else
    {
        previousClickedCell = &cells[(int(event->scenePos().x() - 39 )/ 90)][(int(event->scenePos().y() - 39 ) / 90)];
        //previousClickedCell->setBrush(Qt::red);
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
            QRectF * rect = new QRectF();
                       rect->setWidth(90);
                       rect->setHeight(90);
                       cells[i][j].setRect(*rect);
                       cells[i][j].setX(39 + i*90);
                       cells[i][j].setY(39 + j*90);
                       this->addItem(&cells[i][j]);
        }
    }
}

//здесть надо добавить все фигурки, пока что она одна
void Board::addFigures()
{
    for (int i = 0; i < 8; ++i) {
        cellsToPieces[&cells[i][1]] = new Pawn(cells[i][1].x(), cells[i][1].y(), true);
        this->addItem(cellsToPieces.value(&cells[i][1]));
    }
    for (int i = 0; i < 8; ++i) {
        cellsToPieces[&cells[i][6]] = new Pawn(cells[i][6].x(), cells[i][6].y(), false);
        this->addItem(cellsToPieces.value(&cells[i][6]));
    }

}

//тут какую-нибуд  проверку возможен ли ход
void Board::move()
{
    if (cellsToPieces.contains(previousClickedCell))
    {
        cellsToPieces[previousClickedCell]->setPos(clickedCell->pos());
        cellsToPieces.insert(clickedCell, cellsToPieces[previousClickedCell]);
        cellsToPieces.remove(previousClickedCell);
    }
}
