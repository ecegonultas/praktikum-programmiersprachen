/// \file dialogaddcity.cpp
#include "dialogaddcity.h"
#include "ui_dialogaddcity.h"

#include <QDebug>

DialogAddCity::DialogAddCity(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAddCity)
{
    ui->setupUi(this);
}

DialogAddCity::~DialogAddCity()
{
    delete ui;
}

City* DialogAddCity::getCity()
{
    QString name = ui->lineEdit_name->text();
    int x = ui->lineEdit_x->text().toInt();
    int y = ui->lineEdit_y->text().toInt();

    qDebug() << "Neue Stadt:" << name << x << y;

    return new City(name, x, y);
}