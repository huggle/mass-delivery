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

#define HUGGLE_EXTENSION
#include <huggle_core/iextension.hpp>
#include <QAction>
#include "deliveryform.h"
#include <huggle_core/mainwindow.hpp>

class MassDelivery : public QObject, public Huggle::iExtension
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
        Q_PLUGIN_METADATA(IID "org.huggle.extension.qt" FILE "huggle-md.json")
#endif
    Q_INTERFACES(Huggle::iExtension)

    public:
        MassDelivery(QObject *parent = 0);
        ~MassDelivery();
        bool Register();
        bool IsWorking();
        void Hook_MainWindowOnLoad(void *window);
        QString GetExtensionName() { return "MassDelivery"; }
        QString GetExtensionAuthor() { return "Petr Bena"; }
        QString GetExtensionDescription() { return "Mass delivery of msgs"; }
        bool RequestCore() { return true; }
        bool RequestNetwork() { return true; }
        bool RequestConfiguration() { return true; }
        Huggle::MainWindow *main;
        QAction *menu;
    private slots:
        void OnClick();
    private:
        DeliveryForm *form;
};

#endif

