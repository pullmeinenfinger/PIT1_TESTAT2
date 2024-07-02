#include "mainwindow.h"
#include "mapiofileinput.h"
#include "ui_dialog.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "dijkstra.h"
#include "dijkstradialog.h"
#include "uploaddialog.h"

#include <QString>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QWidget>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    mapio = new MapIoNrw;
    scene.addLine(0,0, 1, 1, QPen(Qt::transparent));

    ui->testStrasse->hide();
    ui->testmap->hide();
    ui->TestDrawCity->hide();
    ui->TestAbstractMap->hide();
    ui->TestDijkstra->hide();
    ui->testDialog->hide();
    ui->testSimple_Draw->hide();
    ui->pushButton_teste_was->hide();
    ui->buttonDijkstra->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
    scene.addLine(0,0, 1, 1, QPen(Qt::transparent));
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this, "Der StreetPlanner", "Dieses Programm ist eine UI App für Versuch 9 der Praktikum Informatik");
}

void MainWindow::on_actionTest_Mode_triggered()
{
    if (ui->actionTest_Mode->isChecked()==false)
    {
        ui->testStrasse->hide();
        ui->testmap->hide();
        ui->TestDrawCity->hide();
        ui->TestAbstractMap->hide();
        ui->TestDijkstra->hide();
        ui->testDialog->hide();
        ui->testSimple_Draw->hide();
        ui->pushButton_teste_was->hide();

    }

    else if(ui->actionTest_Mode->isChecked()==true)
    {
        ui->testStrasse->show();
        ui->testmap->show();
        ui->TestDrawCity->show();
        ui->TestAbstractMap->show();
        ui->TestDijkstra->show();
        ui->testDialog->show();
        ui->testSimple_Draw->show();
        ui->pushButton_teste_was->show();

    }

}

void MainWindow::on_actionReset_Scene_triggered()
{
    scene.clear();
    scene.addLine(0,0, 1, 1, QPen(Qt::transparent));
    map.draw(scene);
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    qDebug() << "Sie haben den Knopf geklickt.";

    QString str;
    QString str1;

    str = ui -> lineEdit -> text ();
    qDebug() << "Ihre Eingabe: " << str;
    str1 = QString("Der von Ihnen eingegebene Text ist: %1").arg(str);
    bool istZahl= false;
    int erhoehteZahl = str.toInt() + 4;

    if(str.toInt(&istZahl))
    {
        qDebug() << "Ihre Eingabe ist eine Zahl:" << str;
        qDebug() << "Ihre Eingabe ist um 4 erhöht:" << erhoehteZahl;
    }
    else
    {
        qDebug() << "Ihre Eingabe ist ein Text:"<< str;
    }


    int x;
    int y;
    QRandomGenerator generator;
    x =  generator.bounded(9);
    y = generator.bounded(9);
    qDebug() << "Random x position:" << x << ", Random y position:" << y;
    scene.addRect(x, y, 30, 8, QPen(Qt::black),
                  QBrush(Qt::black, Qt::SolidPattern));
    scene.addRect(x, y + 8, 30, 8, QPen(Qt::red),
                  QBrush(Qt::red, Qt::SolidPattern));
    scene.addRect(x, y + 16, 30, 8, QPen(Qt::yellow),
                  QBrush(Qt::yellow, Qt::SolidPattern));
}


void MainWindow::on_testSimple_Draw_clicked()
{
    QPen Pen;
    Pen.setColor(Qt::white);
    Pen.setWidth(3);
    scene.addRect(50, 20, 50, 100, Pen);
}

void MainWindow::on_TestDrawCity_clicked()
{
    City newCity1 = City("City 1", 10, 10);
    newCity1.draw(scene);

    City newCity2 = City("City 2", 90, 10);
    newCity2.draw(scene);
    qDebug() << "Zwei Städte werden gezeichnet";
}


void MainWindow::on_testmap_clicked()
{
    Map testMap;
    City newCityy1("City1", 40, 20);
    City newCityy2("City2", 90, 100);
    Street strasse1(&newCityy1, &newCityy2);
    testMap.addCity(&newCityy1);
    testMap.addCity(&newCityy2);
    testMap.addStreet(&strasse1);
    testMap.draw(scene);


}

void MainWindow::on_testStrasse_clicked()
{
        City* newCity1 = new City ("noobCity1", 10, 20);
        City* newCity2 = new City ("noobCity2", 80, 10);
        Street* strasse1 = new Street (newCity1, newCity2);
        newCity1->draw(scene);
        newCity2->draw(scene);
        strasse1->draw(scene);
}

void MainWindow::on_TestAbstractMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1)
        {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1)
        {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
        {
            qDebug() << "-Error: City a could not be found.";
        }

        city = testMap.findCity("b");
        if (city != b)
        {
            qDebug() << "-Error: City b could not be found.";
        }

        city = testMap.findCity("c");
        if (city != nullptr)
        {
            qDebug() << "-Error: If city could not be found 0 should be returned.";
        }

        testMap.addCity(c);
        testMap.addStreet(s2);

        {
            qDebug() << "MapTest: getOppositeCity";
            const City *city = testMap.getOppositeCity(s, a);
            if (city != b)
            {
                qDebug() << "-Error: Opposite city should be b.";
            }

            city = map.getOppositeCity(s, c);
            if (city != nullptr)
            {
                qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
            }
        }

        {
            qDebug() << "MapTest: streetLength";
            double l = testMap.getLength(s2);
            double expectedLength = 223.6;
            // compare doubles with 5% tolerance
            if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            {
                qDebug() << "-Error: Street Length is not equal to the expected.";
            }
        }

        {
            qDebug() << "MapTest: getStreetList";
            QVector<Street*> streetList1 = testMap.getStreetList(a);
            QVector<Street*> streetList2 = testMap.getStreetList(b);
            if (streetList1.size() != 1)
            {
                qDebug() << "-Error: One street should be found for city a.";
            }
            else if (*streetList1.begin() != s)
            {
                qDebug() << "-Error: The wrong street has been found for city a.";
            }

            if (streetList2.size() != 2)
            {
                qDebug() << "-Error: Two streets should be found for city b.";
            }
        }
        qDebug() << "MapTest: End Test of the Map.";
    }

}

void MainWindow::on_TestDijkstra_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    testMap.addCity(a);
    testMap.addCity(b);
    testMap.addCity(c);

    Street *s1 = new Street(a, b);
    Street *s2 = new Street(b, c);
    Street *s3 = new Street(a, c);
    testMap.addStreet(s1);
    testMap.addStreet(s2);
    testMap.addStreet(s3);

    testMap.draw(scene);

    QVector<Street*> kuerzesterWeg = Dijkstra::search(testMap, a->getName(), c->getName());

    for(auto it = kuerzesterWeg.begin(); it != kuerzesterWeg.end(); it++)
    {
        (*it)->drawRed(scene);
    }
}

void MainWindow::on_testDialog_clicked()
{
    Dialog dialogTest;
    int result = dialogTest.exec();
    qDebug() << QString("Dialog result: %1").arg(result);
}

void MainWindow::on_addStrasse_clicked()
{
    Dialog dialog;
    dialog.streetDialog();
    int i = dialog.exec();
    qDebug() << "Der Rückgabewert: " << i;

    if (i == 1)
    {
        QString Name1 = dialog.getCity1Name();
        QString Name2 = dialog.getCity2Name();

        if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
        {
            qDebug() << "please enter valid cities!";
            return;
        }
        else
        {
            City* newCity1 = map.findCity(Name1);
            City* newCity2 = map.findCity(Name2);

            Street* strasse1 = new Street(newCity1, newCity2);
            if(map.addStreet(strasse1))
            {
                strasse1->draw(scene);
            }
        }
    }
    else
    {
        qDebug() << "No new street has been added!";
    }
}



void MainWindow::on_addCity_clicked()
{
    Dialog dialog;
    dialog.cityDialog();
    int i = dialog.exec();
    qDebug() << "Der Rückgabewert: " << i;

    if (i == 1)
    {
        City* dialogCity = dialog.newCity();
        map.addCity(dialogCity);
        dialogCity->draw(scene);
    }

    else
    {
        qDebug() << "Keine neue Stadt wurde hinzugefuegt.";
    }
}

void MainWindow::on_FillMap_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
}


void MainWindow::on_pushButton_clicked()
{
    Dijkstradialog dijkstra;
    int i = dijkstra.exec();
    qDebug() << "Der Rückgabewert: " << i;

    if (i == 1)
    {
        QString Name1 = dijkstra.getCity1Name();
        QString Name2 = dijkstra.getCity2Name();

        if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
        {
            qDebug() << "please enter valid cities!";
            return;
        }
        else if(map.findCity(Name1) != nullptr && map.findCity(Name2) != nullptr)
        {
            QVector<Street*> kuerzesterWeg = Dijkstra::search(map, Name1, Name2);

            for(auto it = kuerzesterWeg.begin(); it != kuerzesterWeg.end(); it++)
            {
                (*it)->drawRed(scene);

            }
        }
    }
    else
    {
        qDebug() << "Dijkstra is cancelled.";
    }


}


void MainWindow::on_uploadButton_clicked()
{
    Uploaddialog upload;
    int i = upload.exec();
    qDebug() << "Der Rückgabewert: " << i;

    if (i == 1)
    {
        MapIoFileinput files(upload.getFileCities(),upload.getFileStreets());
        files.fillMap(map);
        map.draw(scene);
    }
    else
    {
        qDebug() << "File upload is cancelled.";
    }


}


void MainWindow::on_buttonDijkstra_clicked()
{
}



