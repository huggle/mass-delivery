//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QDeclarativeItem>
#include <QAction>
#include "deliveryform.h"
#include <iextension.hpp>
#include "ui_mainwindow.h"
#include <mainwindow.hpp>

class MassDelivery : public QDeclarativeItem, public Huggle::iExtension
{
    Q_OBJECT
    Q_INTERFACES(Huggle::iExtension)

    public:
        MassDelivery(QDeclarativeItem *parent = 0);
        ~MassDelivery();
        bool Register();
        bool IsWorking();
        void Hook_MainWindowOnLoad(void *window);
        QString GetExtensionName() { return "MassDelivery"; }
        QString GetExtensionAuthor() { return "Petr Bena"; }
        QString GetExtensionDescription() { return "Mass delivery of msgs"; }
        QAction *menu;
        bool RequestCore() { return true; }
        bool RequestNetwork() { return true; }
        bool RequestConfiguration() { return true; }
    private slots:
        void OnClick();
    private:
        DeliveryForm *form;
};

QML_DECLARE_TYPE(MassDelivery)

#endif

