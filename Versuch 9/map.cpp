#include "map.h"

Map::Map()
{

}

Map::~Map()
{

}

void Map::addCity(City* stadt)
{
    staedte_Liste.append(stadt);
    qDebug() << stadt->getName() << "wurde in die Karte hinzugefügt.";
}

City* Map::findCity(const QString cityName) const
{
    for(QVector<City*>::const_iterator it = staedte_Liste.begin(); it != staedte_Liste.end(); it++)
    {
        if ((*it)->getName() == cityName)
        {
            return *it;
        }
    }

    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector <Street*> cityStreetList;
    for(QVector<Street*>::const_iterator it = strassen_Liste.begin(); it != strassen_Liste.end(); it++)
    {
        if(city == (*it)->getStadt1() || city == (*it)->getStadt2())
        {
            cityStreetList.append(*it);
        }
    }

    return cityStreetList;
}

QVector<City*> Map::getCityList()
{
    return staedte_Liste;
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (city == street->getStadt1())
    {
        return street->getStadt2();
    }

    else if (city == street->getStadt2())
    {
        return street->getStadt1();
    }

    else
    {
        return nullptr;
    }
}

double Map::getLength(const Street* street) const
{
    double x1 = street->getStadt1()->getX();
    double x2 = street->getStadt2()->getX();
    double y1 = street->getStadt1()->getY();
    double y2 = street->getStadt2()->getY();

    double x_laenge = abs(x2 - x1);
    double y_laenge = abs(y2 - y1);

    double length = sqrt(x_laenge*x_laenge + y_laenge*y_laenge);

    return length;
}

bool Map::addStreet(Street* strasse)
{
    City* city1 = strasse->getStadt1();
    City* city2 = strasse->getStadt2();

    if (findCity(city1->getName()) != nullptr && findCity(city2->getName()) != nullptr)
    {
        strassen_Liste.append(strasse);
        return true;
    }

    else
    {
        return false;
    }
}

void Map::draw(QGraphicsScene &scene)
{
    for(QVector<City*>::iterator it = staedte_Liste.begin(); it != staedte_Liste.end(); it++)
    {
        (*it)->draw(scene);
    }
    for(QVector<Street*>::iterator it1 = strassen_Liste.begin(); it1 != strassen_Liste.end(); it1++)
    {
        (*it1)->draw(scene);
    }
}

