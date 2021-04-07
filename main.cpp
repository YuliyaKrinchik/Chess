#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <cell.h>
#include "board.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Board * board = new Board();
    QGraphicsView * view = new QGraphicsView(board);

    board->drawCells();
    board->addFigures();
    view->resize(800,800);
    view->show();
    return app.exec();
}
