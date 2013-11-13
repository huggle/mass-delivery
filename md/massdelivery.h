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
// this is a path to huggle 3 source code, keep it if you
// checkout extensions folder to same folder where you
// have huggle3 folder
#include "../../huggle3-qt-lx/huggle/iextension.hpp"
#include "../../huggle3-qt-lx/huggle/ui_mainwindow.h"
#include "../../huggle3-qt-lx/huggle/mainwindow.hpp"

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
    private slots:
        void OnClick();
    private:
        DeliveryForm *form;
};

QML_DECLARE_TYPE(MassDelivery)

#endif

