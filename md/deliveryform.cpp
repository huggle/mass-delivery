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

DeliveryForm::DeliveryForm(QWidget *parent) : QDialog(parent), ui(new Ui::DeliveryForm)
{
    CurrentUser = 0;
    ui->setupUi(this);
    ui->lineEdit_2->setText(Huggle::Configuration::UserName + " meh Delivering a mass message " + Huggle::Configuration::EditSuffixOfHuggle);
}

DeliveryForm::~DeliveryForm()
{
    delete ui;
}

void DeliveryForm::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    this->Users.clear();
    QString text = ui->textEdit->toPlainText();
    text = text.replace("\n", "");
    text = text.replace(" ", "");
    while (text.contains(","))
    {
        if (text.startsWith(","))
        {
            text = text.mid(1);
            continue;
        }
        QString user = text.mid(0, text.indexOf(","));
        text = text.mid(text.indexOf(",") + 1);
        Users.append(new Huggle::WikiUser(user));
    }
    if (text != "")
    {
        Users.append(new Huggle::WikiUser(text));
    }

    CurrentUser = 0;
    while (CurrentUser < Users.count())
    {
        Huggle::Core::MessageUser(Users.at(CurrentUser), ui->textEdit_2->toPlainText(), ui->lineEdit->text(), ui->lineEdit_2->text());
        CurrentUser++;
    }
    ui->pushButton->setText("Sending");
}

void DeliveryForm::Refresh()
{
    ui->pushButton->setText("Sending (" + QString::number(this->CurrentUser) + "/" + QString::number(this->Users.count()) + ")");
}
