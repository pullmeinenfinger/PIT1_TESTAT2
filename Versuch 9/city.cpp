#include "city.h"


City::City(QString name, int x, int y):
    name(name), x(x), y(y)
{

}

City::~City()
{

}

void City::draw(QGraphicsScene &scene)
{
    QPen Pen;
    QString Stadt = this->name;
    Pen.setColor(Qt::white);
    Pen.setWidth(2);
    scene.addEllipse(x, y, 8, 8, Pen, QBrush(Qt::red, Qt::SolidPattern));

    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(x, y);
    text->setPlainText(Stadt);
    scene.addItem(text);
}

QString City::getName()
{
    return name;
}

int City::getX()
{
    return x;
}

int City::getY()
{
    return y;
}
