//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef DELIVERYFORM_H
#define DELIVERYFORM_H

#define HUGGLE_EXTENSION
#include <huggle_core/definitions.hpp>
#include <QDialog>
#include <QList>
#include <QTimer>
#include <QString>
#include <huggle_core/wikiuser.hpp>

namespace Ui {
class DeliveryForm;
}

class DeliveryForm : public QDialog
{
    Q_OBJECT

public:
    explicit DeliveryForm(QWidget *parent = 0);
    ~DeliveryForm();
    QTimer *t;

private slots:
    void OnTime();
    void on_pushButton_clicked();

private:
    void Refresh();
    Ui::DeliveryForm *ui;
    QList<Huggle::WikiUser*> Users;
    int CurrentUser;
    int Total;
};

#endif // DELIVERYFORM_H
