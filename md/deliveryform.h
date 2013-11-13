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

#include <QDialog>
#include <QList>
#include <QString>
#include "../../huggle3-qt-lx/huggle/configuration.hpp"
#include "../../huggle3-qt-lx/huggle/wikiuser.hpp"
#include "../../huggle3-qt-lx/huggle/core.hpp"

namespace Ui {
class DeliveryForm;
}

class DeliveryForm : public QDialog
{
    Q_OBJECT

public:
    explicit DeliveryForm(QWidget *parent = 0);
    ~DeliveryForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeliveryForm *ui;
    void Refresh();
    QList<Huggle::WikiUser*> Users;
    int CurrentUser;
};

#endif // DELIVERYFORM_H