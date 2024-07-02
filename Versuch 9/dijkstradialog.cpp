#include "dijkstradialog.h"
#include "ui_dijkstradialog.h"

Dijkstradialog::Dijkstradialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dijkstradialog)
{
    ui->setupUi(this);

}

Dijkstradialog::~Dijkstradialog()
{
    delete ui;
}


QString Dijkstradialog::getCity1Name()
{
    startingCity = ui->startLct->text();
    return startingCity;
}


QString Dijkstradialog::getCity2Name()
{
    endCity = ui->endLct->text();
    return endCity;
}
