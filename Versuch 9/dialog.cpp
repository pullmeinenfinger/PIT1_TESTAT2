#include "dialog.h"
#include "ui_dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::streetDialog()
{
    ui->nameStadt1->show();
    ui->nameStadt2->show();
    ui->label_5->show();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->nameStadt->hide();
    ui->xAchse->hide();
    ui->yAchse->hide();
    this->setWindowTitle("Add Street");
    this->setFixedSize(minimumSize());
}
void Dialog::cityDialog()
{
    ui->nameStadt1->hide();
    ui->nameStadt2->hide();
    ui->label_5->hide();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->nameStadt->show();
    ui->xAchse->show();
    ui->yAchse->show();
    this->setWindowTitle("Add City");
    this->setFixedSize(minimumSize());
}

City* Dialog::newCity()
{
    dialogCity = ui->nameStadt->text();
    qDebug() << dialogCity;
    bool ok;

    x = ui->xAchse->text().toInt(&ok);

    if (ok == false)
    {
        qDebug() << "Bitte geben Sie eine Zahl ein!";
    }
    else
    {
        qDebug() << y;
    }

    y = ui->yAchse->text().toInt(&ok);
    if (ok == false)
    {
        qDebug() << "Bitte geben Sie eine Zahl ein!";
    }
    else
    {
        qDebug() << y;
    }

    return  new City(dialogCity, x, y);
}

QString Dialog::getCity1Name()
{
    nameCity1 = ui->nameStadt1->text();
    return nameCity1;
}

QString Dialog::getCity2Name()
{
    nameCity2 = ui->nameStadt2->text();
    return nameCity2;
}
