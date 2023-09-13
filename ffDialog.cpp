#include "ffDialog.h"
#include <iostream>

FfDialog::FfDialog(QWidget *parent) : QDialog(parent)
{
    selectedButtonIndex = -1;
    for (int i = 0; i < 6; ++i) {
        player[i] = new QRadioButton("Player " + QString::number(i), this);
        player[i]->setGeometry(140, 15 + (i * 30), 150, 40);
        i == 0 ? player[i]->setText(QString::number(i + 1) + " Fire Fighter") : player[i]->setText(QString::number(i + 1) + " Fire Fighters");
        connect(player[i], &QRadioButton::clicked, this, [this, i]() {
            selectedButtonIndex = i;
        });
    }
    player[1]->setChecked(true);
    start = new QPushButton("start", this);
    start->setGeometry(150, 200, 100, 40);
    start->setText("Start");

    connect(start, &QPushButton::clicked, this, &QDialog::accept);
}
