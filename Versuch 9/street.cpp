#include "street.h"

Street::Street(City* stadt1, City* stadt2):
    stadt1(stadt1), stadt2(stadt2)
{

}

Street::~Street()
{

}

void Street::draw(QGraphicsScene &scene)
{
    int x1 = ((stadt1)->getX()) +5;
    int y1 = ((stadt1)->getY()) +5;
    int x2 = ((stadt2)->getX()) +5;
    int y2 = ((stadt2)->getY()) +5;

    QPen Pen;
    Pen.setColor(Qt::lightGray);
    Pen.setWidth(2);
    scene.addLine(x1, y1, x2, y2, Pen);
}

City* Street::getStadt1() const
{
    return stadt1;
}

City* Street::getStadt2() const
{
    return stadt2;
}

void Street::strassen_id()
{
    qDebug() << "Verbindung zwischen " << stadt1->getName() << " und " << stadt2->getName();
}


void Street::drawRed(QGraphicsScene &scene)
{
    int x1 = ((stadt1)->getX()) +5;
    int y1 = ((stadt1)->getY()) +5;
    int x2 = ((stadt2)->getX()) +5;
    int y2 = ((stadt2)->getY()) +5;

    QPen Pen;
    Pen.setColor(Qt::red);
    Pen.setWidth(3);
    scene.addLine(x1, y1, x2, y2, Pen);
}
