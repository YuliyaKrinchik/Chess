#include "bishop.h"

Bishop::Bishop(int x, int y, bool color) : ChessPiece(x, y)
{
    if (color) {
        this->setPixmap(QPixmap::fromImage(*whiteImage).scaled(90,90));
    }
    else {
        this->setPixmap(QPixmap::fromImage(*blackImage).scaled(90,90));
    }
}
