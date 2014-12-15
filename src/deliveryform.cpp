//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "deliveryform.h"
#include "ui_deliveryform.h"
#include <configuration.hpp>
#include <exception.hpp>
#include <wikiutil.hpp>
#include <core.hpp>

DeliveryForm::DeliveryForm(QWidget *parent) : QDialog(parent), ui(new Ui::DeliveryForm)
{
    CurrentUser = 0;
    this->t = new QTimer();
    ui->setupUi(this);
    ui->lineEdit_2->setText(hcfg->SystemConfig_Username + " is delivering a mass message " + hcfg->ProjectConfig->EditSuffixOfHuggle);
}

DeliveryForm::~DeliveryForm()
{
    delete this->t;
    delete ui;
}

void DeliveryForm::OnTime()
{
    if (Users.count() > 0)
    {
        QString text = ui->textEdit_2->toPlainText();
        Huggle::WikiUser *wu = this->Users.at(0);
        this->Users.removeAt(0);
        text = text.replace("$target_user", wu->Username);
        Huggle::WikiUtil::MessageUser(wu, text, ui->lineEdit->text(), ui->lineEdit_2->text(), true, NULL, true);
        CurrentUser++;
        Refresh();
        delete wu;
    } else
    {
        t->stop();
    }
}

static QString reformat(QString name)
{
    name.replace(" ", "_");
    if (name.startsWith("User:"))
        name = name.mid(5);
    name = name.trimmed();
    return name;
}

void DeliveryForm::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->textEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->textEdit_2->setEnabled(false);
    this->Users.clear();
    QString text = ui->textEdit->toPlainText();
    text = text.replace("\n", "");
    //text = text.replace(" ", "");
    while (text.contains(","))
    {
        if (text.startsWith(","))
        {
            text = text.mid(1);
            continue;
        }
        QString user = text.mid(0, text.indexOf(","));
        text = text.mid(text.indexOf(",") + 1);
        text = reformat(text);
        Users.append(new Huggle::WikiUser(user));
    }
    text = reformat(text);
    if (text != "")
    {
        Users.append(new Huggle::WikiUser(text));
    }
    this->Total = Users.count();
    connect(this->t, SIGNAL(timeout()), this, SLOT(OnTime()));
    this->t->start(6000);
    this->CurrentUser = 0;
}

void DeliveryForm::Refresh()
{
    ui->pushButton->setText("Sending (" + QString::number(this->CurrentUser) + "/" + QString::number(this->Total + 1) + ")");
}
