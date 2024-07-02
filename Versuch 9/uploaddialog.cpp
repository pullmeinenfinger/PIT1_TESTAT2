#include "uploaddialog.h"
#include "ui_uploaddialog.h"

Uploaddialog::Uploaddialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Uploaddialog)
{
    ui->setupUi(this);
}

Uploaddialog::~Uploaddialog()
{
    delete ui;
}

void Uploaddialog::on_uploadButton1_clicked()
{
    QFileDialog upload;

    filePath1 = upload.getOpenFileName(this,tr("Open City File"),"C:\\Users\\baris\\Documents\\Streetplanner" , tr("Text Files (*.txt)"));
    ui->path1->setText(filePath1);
    qDebug() << filePath1;

}




void Uploaddialog::on_uploadButton2_clicked()
{
    QFileDialog upload;

    filePath2 = upload.getOpenFileName(this,tr("Open Street File"),"C:\\Users\\baris\\Documents\\Streetplanner" , tr("Text Files (*.txt)"));
    ui->path2->setText(filePath2);
    qDebug() << filePath2;

}

QString Uploaddialog::getFileCities()
{
    return filePath1;
}

QString Uploaddialog::getFileStreets()
{
    return filePath2;
}
