//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "massdelivery.h"
#include <huggle_core/localization.hpp>
#include <huggle_core/configuration.hpp>
#include <huggle_core/core.hpp>
#include <huggle_core/querypool.hpp>
#include <huggle_core/syslog.hpp>
#include <QMenu>

MassDelivery::MassDelivery(QObject *parent): QObject(parent)
{
    this->menu = NULL;
    this->form = NULL;
}

MassDelivery::~MassDelivery()
{
    delete this->form;
    delete this->menu;
}

bool MassDelivery::Register()
{
    this->Init();
    return true;
}

bool MassDelivery::IsWorking()
{
    return true;
}

void MassDelivery::Hook_MainWindowOnLoad(void *window)
{
    // here we need to make a menu item
    this->main = (Huggle::MainWindow*)window;
    this->menu = new QAction("Send mass message", (QObject*)this->main->GetMenu(HUGGLE_MW_MENU_SYSTEM));
    this->main->GetMenu(HUGGLE_MW_MENU_SYSTEM)->insertAction(this->main->GetMenuItem(HUGGLE_MW_MENUITEM_EXIT), this->menu);
    connect(this->menu, SIGNAL(triggered()), this, SLOT(OnClick()));
}

void MassDelivery::OnClick()
{
    if (this->form != NULL)
    {
        delete this->form;
    }
    form = new DeliveryForm(this->main);
    form->show();
}

#if QT_VERSION < 0x050000
    Q_EXPORT_PLUGIN2("org.huggle.extension.qt", MassDelivery)
#endif
