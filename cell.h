#ifndef CELL_H
#define CELL_H
#include <QGraphicsRectItem>



class Cell : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Cell();
};


#endif // CELL_H
