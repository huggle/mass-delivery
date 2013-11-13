//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "massdelivery.h"

#include <qdeclarative.h>

MassDelivery::MassDelivery(QDeclarativeItem *parent): QDeclarativeItem(parent)
{
    // By default, QDeclarativeItem does not draw anything. If you subclass
    // QDeclarativeItem to create a visual item, you will need to uncomment the
    // following line:

    // setFlag(ItemHasNoContents, false);
    menu = NULL;
    this->form = NULL;
}

MassDelivery::~MassDelivery()
{
    delete form;
    delete menu;
}

bool MassDelivery::Register()
{
    return true;
}

bool MassDelivery::IsWorking()
{
    return true;
}

void MassDelivery::Hook_MainWindowOnLoad(void *window)
{
    // here we need to make a menu item
    Huggle::MainWindow *w = (Huggle::MainWindow*)window;
    menu = new QAction("Send mass message", w->ui->menuFile);
    w->ui->menuFile->insertAction(w->ui->actionExit, menu);
    connect(menu, SIGNAL(triggered()), this, SLOT(OnClick()));
}

void MassDelivery::OnClick()
{
    if (form != NULL)
    {
        delete form;
    }
    form = new DeliveryForm();
    form->show();
}

Q_EXPORT_PLUGIN2("org.huggle.extension.qt", MassDelivery)